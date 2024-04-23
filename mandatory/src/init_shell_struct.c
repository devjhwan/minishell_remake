/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:53:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/23 21:22:49 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "utils.h"
#include <unistd.h>

int	init_shell_struct(t_shell *shell, int as, char **av, char **ep)
{
	(void)as;
	(void)av;
	shell->cmds = NULL;
	shell->env = copy_strarray(ep);
	if (shell->env == NULL)
		return (0);
	shell->stdinfd_cpy = dup(STDIN_FILENO);
	shell->stdoutfd_cpy = dup(STDOUT_FILENO);
	shell->fdin = dup(STDIN_FILENO);
	if (shell->stdinfd_cpy < 0 || \
		shell->stdoutfd_cpy < 0 || \
		shell->fdin < 0)
		return (free_shell_struct(shell), 0);
	shell->exit_code = 0;
	return (1);
}
