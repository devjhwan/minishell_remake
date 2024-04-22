/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/22 12:42:21 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

pid_t	execute_command(t_executor *exec, char **envp)
{
	int		p[2];
	pid_t	pid;

	pipe(p);
	pid = fork();
	if (pid == 0)
	{
		if (execve(exec->args[0], exec->args, envp) < 0)
		{
			perror("minishell: ");
			exit(1);
		}
	}
	return (pid);
}
