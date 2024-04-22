/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_shell_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:53:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/22 12:57:48 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "utils.h"
#include <unistd.h>

void	free_shell_struct(t_shell *shell)
{
	if (shell->cmds != NULL)
		free_cmds(&shell->cmds);
	shell->cmds = NULL;
	if (shell->env != NULL)
		free_strarray(shell->env);
	shell->env = NULL;
	close(shell->stdinfd_cpy);
	close(shell->stdoutfd_cpy);
	close(shell->fdin);
	close(shell->fdout);
}