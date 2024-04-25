/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:53:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/26 01:35:24 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "utils.h"
#include "libft.h"
#include "executor.h"
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
			break;
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

	shell->pwd = (char *)malloc(sizeof(char) * 1024);
	shell->oldpwd = search_environment("OLDPWD", shell);
	if (shell->oldpwd == NULL || shell->pwd == NULL)
		return (0);
	if (shell->oldpwd[0] == '\0')
	{
		free(shell->oldpwd);
		shell->oldpwd = NULL;
		exec_export((char *[]){"export", "OLDPWD", NULL}, shell);
	}
	if (shell->pwd == NULL || getcwd(shell->pwd, 1024) == NULL)
		return (free_shell_struct(shell), 0);
	tmp = ft_strjoin(2, "PWD=", shell->pwd);
	if (tmp == NULL)
		return (0);
	exec_export((char *[]){"export", tmp, NULL}, shell);
	return (1);
}

int	init_shell_struct(t_shell *shell, int as, char **av, char **ep)
{
	(void)as;
	(void)av;
	shell->pwd = NULL;
	shell->env = copy_strarray(ep);
	shell->export = create_export(ep);
	if (shell->env == NULL || shell->export == NULL)
		return (free_strarray(shell->env), free_strarray(shell->export), 0);
	if (manage_pwd(shell) == 0)
		return (free_shell_struct(shell), 0);
	shell->stdinfd_cpy = dup(STDIN_FILENO);
	shell->stdoutfd_cpy = dup(STDOUT_FILENO);
	shell->fdin = dup(STDIN_FILENO);
	if (shell->stdinfd_cpy < 0 || shell->stdoutfd_cpy < 0 || shell->fdin < 0)
		return (free_shell_struct(shell), 0);
	shell->exit_code = 0;
	shell->is_exit = 0;
	return (1);
}
