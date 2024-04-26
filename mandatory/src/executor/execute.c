/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/26 22:24:47 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "executor.h"
#include "utils.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int	execute_one_command(t_cmd *cmd, t_shell *shell)
{
	pid_t		pid;
	t_executor	*exec;

	pid = -1;
	exec = create_new_executor(cmd);
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
	while (cmd != NULL && !shell->is_exit)
	{
		exec = create_new_executor(cmd);
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
	if (pid > 0)
		waitpid(pid, &shell->new_exit_code, 0);
	if (shell->new_exit_code >= 256)
		shell->new_exit_code /= 256;
	shell->exit_code = shell->new_exit_code;
	unlink(".heredoc");
}
