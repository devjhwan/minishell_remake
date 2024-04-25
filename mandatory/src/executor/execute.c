/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/25 17:14:18 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"
#include "utils.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void	wait_all_pipe(pid_t last_pid, t_shell *shell);

int	execute_one_command(t_cmd *cmd, t_shell *shell)
{
	pid_t	pid;
	t_executor	*exec;

	pid = -1;
	exec = create_new_executor(cmd, shell->env);
	if (exec != NULL)
	{
		if (isbuiltin(exec->args[0]))
			execute_builtin(exec, shell);
		else
			pid = execute_command(exec, shell);
		free_executor(&exec);
	}
	return (pid);
}

int	execute_multiple_command(t_cmd *cmd, t_shell *shell)
{
	t_executor	*exec;
	pid_t		pid;

	pid = -1;
	while (cmd != NULL)
	{
		exec = create_new_executor(cmd, shell->env);
		if (exec != NULL)
		{
			pid = execute_command(exec, shell);
			free_executor(&exec);
			if (pid == -1)
				break ;
		}
		cmd = cmd->next;
	}
	return (pid);
}

void	execute(t_shell *shell)
{
	t_cmd		*cmds;
	pid_t		pid;

	cmds = shell->cmds;
	if (cmds->next == NULL)
		pid = execute_one_command(cmds, shell);
	else
		pid = execute_multiple_command(cmds, shell);
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
