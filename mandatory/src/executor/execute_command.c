/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/28 16:01:35 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "executor.h"
#include "utils.h"
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

static int	manage_child_redirection(int p[2], t_executor *exec, \
												t_shell *shell)
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

static int	manage_parent_redirection(int p[2], t_executor *exec, \
												t_shell *shell)
{
	close(p[1]);
	close(shell->fdin);
	if (!exec->islast)
		shell->fdin = p[0];
	else
	{
		close(p[0]);
		shell->fdin = dup(STDIN_FILENO);
	}
	return (1);
}

static int	check_command_path(char *path)
{
	if (path == NULL)
		return (0);
	else if (path[0] == '\0' || access(path, F_OK) == -1)
		return (print_error(COMMAND_NOT_FOUND, path, NULL), 0);
	else if (access(path, X_OK) == -1)
		return (print_error(PERMISSION_DENIED, path, NULL), 0);
	return (1);
}

pid_t	execute_command(t_executor *exec, t_shell *shell)
{
	int		p[2];
	pid_t	pid;
	char	*path;

	if (pipe(p) < 0)
		return (-1);
	pid = fork();
	if (pid == 0)
	{
		path = NULL;
		if (exec->args[0] != NULL)
			path = get_path_from_env(exec->args[0], shell->env);
		if (exec->args[0] != NULL && \
				manage_child_redirection(p, exec, shell) && \
				isbuiltin(exec->args[0]))
			execute_builtin(exec, shell);
		else if (check_command_path(path) == 0)
			execve(path, exec->args, shell->env);
		shell->is_exit = 1;
		free(path);
	}
	else if (manage_parent_redirection(p, exec, shell) == 0)
		return (-1);
	return (pid);
}
