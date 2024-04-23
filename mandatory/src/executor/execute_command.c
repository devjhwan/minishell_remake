/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/23 23:26:51 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"
#include "utils.h"
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int	manage_child_redirection(int p[2], t_executor *exec, t_shell *shell)
{
	int	fd;

	if (exec->in == NULL && dup2(shell->fdin, STDIN_FILENO) < 0)
			return (0);
	else if (exec->in != NULL)
	{
		fd = open(exec->in->filename, O_RDONLY, 0644);
		if (fd < 0 || dup2(fd, STDIN_FILENO) < 0)
			return (0);
		close(fd);
	}
	if (exec->out == NULL && !exec->islast && dup2(p[1], STDOUT_FILENO) < 0)
		return (0);
	else if (exec->out != NULL)
	{
		if (exec->out->t == OUT)
			fd = open(exec->out->filename, O_WRONLY | O_TRUNC, 0644);
		else
			fd = open(exec->out->filename, O_WRONLY | O_APPEND, 0664);
		if (fd < 0 || dup2(fd, STDOUT_FILENO) < 0)
			return (0);
	}
	return (close(p[0]), close(p[1]), close(shell->fdin), 1);
}

int	manage_parent_redirection(int p[2], t_executor *exec, t_shell *shell)
{
	close(p[1]);
	close(shell->fdin);
	if (!exec->islast)
		shell->fdin = p[0];
	else
	{
		close(p[0]);
		shell->fdin = dup(shell->stdinfd_cpy);
	}
	return (1);
}

pid_t	execute_command(t_executor *exec, t_shell *shell)
{
	int		p[2];
	pid_t	pid;

	pipe(p);
	pid = fork();
	if (pid == 0)
	{
		if (manage_child_redirection(p, exec, shell) == 0)
			exit(1);
		if (isbuiltin(exec->args[0]))
			execute_builtin(exec, shell);
		else if (execve(exec->args[0], exec->args, shell->env) < 0)
			perror("minishell: ");
		exit(1);
	}
	else if (manage_parent_redirection(p, exec, shell) == 0)
			return (-1);
	return (pid);
}
