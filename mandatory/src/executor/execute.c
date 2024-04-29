/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/29 14:53:52 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "parser.h"
#include <sys/types.h>
#include <unistd.h>

static int	has_pipe(t_token *tokens)
{
	while (tokens != NULL)
	{
		if (tokens->t == PIPE)
			return (1);
		tokens = tokens->next;
	}
	return (0);
}

static void	execute_single_command(t_token *tokens)
{
	t_cmd	*cmd;

	cmd = parser(tokens);
	if (cmd != NULL)
		print_command(cmd);
	free_cmd(cmd);
	free_tokens(tokens);
}

static void	execute_multiple_command(t_token *tokens)
{
	t_token	*next_tokens;
	t_cmd	*cmd;
	pid_t	pid;
	int		p_fd[2];

	next_tokens = get_next_command_tokens(&tokens);
	pid = -2;
	while (next_tokens != NULL)
	{
		if (pipe(p_fd) == -1)
			break ;
		pid = fork();
		if (pid == -1)
			break ;
		else if (pid == 0)
		{
			cmd = parser(next_tokens);
			free_tokens(next_tokens);
			if (cmd != NULL)
			{
				print_command(cmd);
				free_cmd(cmd);
			}
			get_shell()->is_exit = 1;
			break ;
		}
		else
		{
			free_tokens(next_tokens);
			next_tokens = get_next_command_tokens(&tokens);
		}
	}
	free_tokens(tokens);
}

void	execute(t_token *tokens)
{
	if (!has_pipe(tokens))
		execute_single_command(tokens);
	else
		execute_multiple_command(tokens);
}
