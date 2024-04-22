/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/22 12:39:20 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void	execute(t_shell *shell)
{
	t_cmd		*cmds;
	t_executor	*exec;
	pid_t		pid;
	int			exit_status;

	pid = -1;
	cmds = shell->cmds;
	while (cmds != NULL)
	{
		exec = create_new_executor(cmds, shell->env);
		if (exec != NULL)
		{
			print_executor(exec);
			pid = execute_command(exec, shell->env);
			free_executor(&exec);
			if (pid == -1)
				break;
		}
		cmds = cmds->next;
	}
	if (pid > 0)
	{
		waitpid(pid, &exit_status, 0);
		if (WIFEXITED(exit_status))
			printf("%d\n", WEXITSTATUS(exit_status));
		else if (WIFSIGNALED(exit_status))
			printf("%d\n", WTERMSIG(exit_status));
	}
	// finished all commands. Time to wait to finish all pipes.
}
