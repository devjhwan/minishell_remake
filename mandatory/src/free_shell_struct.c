/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_shell_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:53:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/25 13:03:25 by junghwle         ###   ########.fr       */
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
	if (shell->export != NULL)
		free_strarray(shell->export);
	shell->env = NULL;
	close(shell->stdinfd_cpy);
	close(shell->stdoutfd_cpy);
	close(shell->fdin);
}
