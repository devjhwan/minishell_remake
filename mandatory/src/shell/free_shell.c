/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:53:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/29 13:27:22 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "utils.h"
#include <unistd.h>
#include <stdlib.h>

void	free_shell(t_shell *shell)
{
	if (shell != NULL)
	{
		if (shell->env != NULL)
			free_strarray(shell->env);
		if (shell->export != NULL)
			free_strarray(shell->export);
		shell->env = NULL;
		free(shell->pwd_save);
		free(shell->pwd);
		free(shell->oldpwd);
		close(shell->stdin_fd_save);
		close(shell->stdout_fd_save);
		close(shell->fdin);
		close(shell->fdout);
	}
}
