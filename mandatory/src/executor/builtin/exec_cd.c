/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/26 21:37:12 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "executor.h"
#include "libft.h"
#include "utils.h"
#include <stdio.h>
#include <unistd.h>

int	change_directory(char *path, t_shell *shell);

void	cd_env_home(t_shell *shell)
{
	char	*homepath;

	if (check_environment("HOME") == 0)
		print_error(HOME_NOT_SET, "cd", NULL);
	else
	{
		homepath = search_environment("HOME");
		if (homepath != NULL)
		{
			change_directory(homepath, shell);
			free(homepath);
		}
	}
}

void	cd_home(t_shell *shell)
{
	char	*homepath;

	homepath = get_homepath();
	if (homepath != NULL)
	{
		change_directory(homepath, shell);
		free(homepath);
	}
}

void	cd_back(t_shell *shell)
{
	if (shell->oldpwd != NULL)
	{
		if (change_directory(shell->oldpwd, shell) != 0)
			printf("%s\n", shell->pwd);
	}
	else
		print_error(OLDPWD_NOT_SET, "cd", NULL);
	(void)shell;
}

void	cd_path(char *arg, t_shell *shell)
{
	char	*tmp;

	if (ft_strncmp(arg, ".", 2) == 0 && !access(".", F_OK))
	{
		ft_putstrerr("cd: error retrieving current directory: ");
		ft_putstrerr("getcwd: cannot access parent directories: ");
		ft_putstrerr("No such file or directory\n");
		free(shell->oldpwd);
		shell->oldpwd = shell->pwd;
		tmp = ft_strjoin(2, shell->pwd_save, "/.");
		if (tmp != NULL)
		{
			free(shell->pwd_save);
			shell->pwd_save = tmp;
		}
		shell->pwd = ft_strdup(shell->pwd_save);
	}
	else
		change_directory(arg, shell);
}

void	exec_cd(char **args, t_shell *shell)
{
	int	i;

	if (args[1] != NULL && ft_strncmp(args[1], "--", 3) == 0)
	{
		free(args[1]);
		i = 1;
		while (args[i++] != NULL)
			args[i - 1] = args[i];
	}
	if (args[1] == NULL)
		cd_env_home(shell);
	else if (ft_strncmp(args[1], "~", 2) == 0)
		cd_home(shell);
	else if (ft_strncmp(args[1], "-", 2) == 0)
		cd_back(shell);
	else
		cd_path(args[1], shell);
}
