/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/28 17:08:44 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "executor.h"
#include "libft.h"
#include <unistd.h>

static void	manage_redir(t_executor *exec)
{
	int	fd;

	if (exec->out != NULL)
	{
		if (exec->out->t == OUT)
			fd = open(exec->out->filename, O_WRONLY | O_TRUNC, 0644);
		else
			fd = open(exec->out->filename, O_WRONLY | O_APPEND, 0664);
		if (fd >= 0)
			dup2(fd, STDOUT_FILENO);
		close(fd);
	}
}

void	execute_builtin(t_executor *exec, t_shell *shell)
{
	manage_redir(exec);
	if (ft_strncmp(ft_tolower(exec->args[0]), "echo", 5) == 0)
		exec_echo(exec->args);
	else if (ft_strncmp(exec->args[0], "cd", 3) == 0)
		exec_cd(exec->args, shell);
	else if (ft_strncmp(exec->args[0], "pwd", 4) == 0)
		exec_pwd(shell);
	else if (ft_strncmp(exec->args[0], "export", 7) == 0)
		exec_export(exec->args, shell);
	else if (ft_strncmp(exec->args[0], "unset", 6) == 0)
		exec_unset(exec->args, shell);
	else if (ft_strncmp(exec->args[0], "env", 4) == 0)
		exec_env(exec->args, shell->env);
	else if (ft_strncmp(exec->args[0], "exit", 5) == 0)
		exec_exit(exec->args, shell);
	dup2(shell->fdout, STDOUT_FILENO);
}
