/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/26 15:58:41 by junghwle         ###   ########.fr       */
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

	if (check_environment("HOME", shell) == 0)
		print_error(HOME_NOT_SET, "cd", NULL);
	else
	{
		homepath = search_environment("HOME", shell);
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

	homepath = get_homepath(shell);
	if (homepath != NULL)
	{
		change_directory(homepath, shell);
		free(homepath);
	}
}

void	cd_back(t_shell *shell)
{
	(void)shell;
}
void	exec_cd(char **args, t_shell *shell)
{
	if (args[1] == NULL)
		cd_env_home(shell);
	else if (args[2] != NULL)
		print_error(TOO_MANY_ARGUMENTS, "cd", NULL);
	else if (ft_strncmp(args[1], "~", 2) == 0)
		cd_home(shell);
	else if (ft_strncmp(args[1], "-", 2) == 0)
		cd_back(shell);
}
