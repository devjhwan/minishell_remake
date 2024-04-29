/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cd_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/29 13:34:33 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "builtin.h"
#include "print_error.h"
#include "utils.h"
#include "libft.h"
#include <unistd.h>

static void	update_oldpwd(void)
{
	char	*tmp;
	char	*tmp2;

	tmp = search_environment("PWD");
	if (tmp == NULL || ft_strlen(tmp) == 0)
	{
		exec_unset((char *[]){"unset", "OLDPWD", NULL});
		exec_export((char *[]){"export", "OLDPWD", NULL});
		free(tmp);
	}
	else
	{
		tmp2 = ft_strjoin(2, "OLDPWD=", tmp);
		free(tmp);
		if (tmp2 != NULL)
			exec_export((char *[]){"export", tmp2, NULL});
		free(tmp2);
	}
}

static void	update_pwd(void)
{
	char	*tmp;

	tmp = ft_strjoin(2, "PWD=", get_shell()->pwd);
	if (tmp != NULL)
		exec_export((char *[]){"export", tmp, NULL});
	free(tmp);
}

static int	check_parent_dir(char *path)
{
	char	*tmp;
	int		i;

	tmp = ft_strtrim(path, " ");
	if (tmp == NULL)
		return (0);
	i = ft_strlen(tmp) - 1;
	while (i >= 0 && tmp[i] != '/')
		i--;
	if (i < 0)
		return (free(tmp), 1);
	tmp[i + 1] = '\0';
	if (!isdir(tmp))
		return (free(tmp), 0);
	else
		return (free(tmp), 1);
}

static int	check_exception(char *path)
{
	if (check_parent_dir(path) == 0)
		return (print_error(NOT_A_DIRECTORY, "cd", path), 0);
	if (access(path, F_OK) == -1)
		return (print_error(NO_FILE2, "cd", path), 0);
	else if (!isdir(path))
		return (print_error(NOT_A_DIRECTORY, "cd", path), 0);
	else if (access(path, X_OK) == -1)
		return (print_error(PERMISSION_DENIED2, "cd", path), 0);
	else
		return (1);
}

int	change_directory(char *path, t_shell *shell)
{
	if (check_exception(path) && chdir(path) == 0)
	{
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
		if (contains_export("OLDPWD") != -1)
			update_oldpwd();
		if (contains_export("PWD") != -1)
			update_pwd();
		return (1);
	}
	return (0);
}
