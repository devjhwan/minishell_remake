/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/24 00:05:00 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void	wait_all_pipe(pid_t last_pid, t_shell *shell);

void	execute(t_shell *shell)
{
	t_cmd		*cmds;
	t_executor	*exec;
	pid_t		pid;

	pid = -1;
	cmds = shell->cmds;
	while (cmds != NULL)
	{
		exec = create_new_executor(cmds, shell->env);
		if (exec != NULL)
		{
			// print_executor(exec);
			pid = execute_command(exec, shell);
			free_executor(&exec);
			if (pid == -1)
				break;
		}
		cmds = cmds->next;
	}
	wait_all_pipe(pid, shell);
	unlink(".heredoc");
}

void	wait_all_pipe(pid_t last_pid, t_shell *shell)
{
	if (last_pid > 0)
	{
		waitpid(last_pid, &shell->exit_code, 0);
		if (WIFEXITED(shell->exit_code))
			printf("%d\n", WEXITSTATUS(shell->exit_code));
		else if (WIFSIGNALED(shell->exit_code))
			printf("%d\n", WTERMSIG(shell->exit_code));
	}
}
