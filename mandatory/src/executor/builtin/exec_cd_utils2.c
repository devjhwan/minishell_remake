/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cd_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/26 19:21:55 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "executor.h"
#include "utils.h"
#include "libft.h"
#include <unistd.h>

static void	update_oldpwd(t_shell *shell)
{
	char	*tmp;
	char	*tmp2;

	tmp = search_environment("PWD", shell);
	if (tmp == NULL || ft_strlen(tmp) == 0)
	{
		exec_unset((char *[]){"unset", "OLDPWD", NULL}, shell);
		exec_export((char *[]){"export", "OLDPWD", NULL}, shell);
		free(tmp);
	}
	else
	{
		tmp2 = ft_strjoin(2, "OLDPWD=", tmp);
		free(tmp);
		if (tmp2 != NULL)
			exec_export((char *[]){"export", tmp2, NULL}, shell);
		free(tmp2);
	}
}

static void	update_pwd(char *path, t_shell *shell)
{
	char	*tmp;

	tmp = ft_strjoin(2, "PWD=", path);
	if (tmp != NULL)
		exec_export((char *[]){"export", tmp, NULL}, shell);
	free(tmp);
}

int	change_directory(char *path, t_shell *shell)
{
	if (access(path, F_OK) == -1)
		return (print_error(NO_FILE2, "cd", path), 0);
	else if (!isdir(path))
		return (print_error(NOT_A_DIRECTORY, "cd", path), 0);
	else if (access(path, X_OK) == -1)
		return (print_error(PERMISSION_DENIED2, "cd", path), 0);
	else if (chdir(path) == 0)
	{
		if (contains_export("OLDPWD", shell->export) != -1)
			update_oldpwd(shell);
		if (contains_export("PWD", shell->export) != -1)
			update_pwd(path, shell);
		free(shell->oldpwd);
		shell->oldpwd = shell->pwd;
		shell->pwd = (char *)malloc(sizeof(char) * 1024);
		if (shell->pwd == NULL)
			return (0);
		getcwd(shell->pwd, 1024);
		free(shell->pwd_save);
		shell->pwd_save = ft_strdup(shell->pwd);
		if (shell->pwd_save == NULL)
			return (0);
		return (1);
	}
	return (0);
}
