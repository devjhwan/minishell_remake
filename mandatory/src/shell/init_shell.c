/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:53:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/29 13:30:52 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "utils.h"
#include "libft.h"
#include "builtin.h"
#include <unistd.h>

static char	*convert_envarg_to_export(char *arg)
{
	char	*new_arg;
	int		i;

	new_arg = (char *)malloc(sizeof(char) * (ft_strlen(arg) + 14));
	if (new_arg == NULL)
		return (NULL);
	ft_strlcpy(new_arg, "declare -x ", 12);
	i = 0;
	while (arg[i] != '\0')
	{
		new_arg[i + 11] = arg[i];
		i++;
		if (arg[i - 1] == '=')
			break ;
	}
	new_arg[i + 11] = '\"';
	while (arg[i] != '\0')
	{
		new_arg[i + 12] = arg[i];
		i++;
	}
	new_arg[i + 12] = '\"';
	new_arg[i + 13] = '\0';
	return (new_arg);
}

static char	**create_export(char **ep)
{
	int		i;
	char	**export;

	i = 0;
	while (ep[i] != NULL)
		i++;
	export = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (ep[i] != NULL)
	{
		export[i] = convert_envarg_to_export(ep[i]);
		if (export[i] == NULL)
			return (free_strarray(export), NULL);
		i++;
	}
	export[i] = NULL;
	return (export);
}

static int	manage_pwd(t_shell *shell)
{
	char	*tmp;

	if (contains_export("OLDPWD") == -1)
		exec_export((char *[]){"export", "OLDPWD", NULL});
	else
	{
		tmp = search_environment("OLDPWD");
		if (tmp == NULL || !isdir(tmp))
			exec_unset((char *[]){"unset", "OLDPWD", NULL});
		free(tmp);
	}
	shell->pwd = (char *)malloc(sizeof(char) * 1024);
	if (shell->pwd == NULL)
		return (0);
	if (getcwd(shell->pwd, 1024) == NULL)
		return (0);
	shell->pwd_save = ft_strdup(shell->pwd);
	if (shell->pwd_save == NULL)
		return (0);
	tmp = ft_strjoin(2, "PWD=", shell->pwd);
	if (tmp == NULL)
		return (0);
	exec_export((char *[]){"export", tmp, NULL});
	return (free(tmp), 1);
}

t_shell	*init_shell(int as, char **av, char **ep)
{
	t_shell	*shell;

	(void)as;
	(void)av;
	shell = get_shell();
	if (shell == NULL)
		return (NULL);
	shell->pwd_save = NULL;
	shell->pwd = NULL;
	shell->oldpwd = NULL;
	shell->env = copy_strarray(ep);
	shell->export = create_export(ep);
	if (shell->env == NULL || shell->export == NULL)
		return (free_shell(shell), NULL);
	manage_shlvl();
	if (manage_pwd(shell) == 0)
		return (free_shell(shell), NULL);
	shell->stdin_fd_save = dup(STDIN_FILENO);
	shell->stdout_fd_save = dup(STDIN_FILENO);
	if (shell->stdin_fd_save < 0 || shell->stdout_fd_save < 0)
		return (free_shell(shell), NULL);
	shell->fdin = STDIN_FILENO;
	shell->fdout = STDOUT_FILENO;
	shell->exit_code = 0;
	shell->is_exit = 0;
	return (shell);
}
