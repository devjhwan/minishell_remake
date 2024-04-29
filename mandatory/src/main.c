/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/29 12:56:40 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"
#include "lexer.h"
#include "executor.h"
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

void	main_loop(void)
{
	char	*str;
	t_token	*tokens;

	while (1)
	{
		set_default_minishell_signal();
		set_minishell_terminal();
		str = readline("minishell: ");
		if (str == NULL)
			break ;
		tokens = lexer(str);
		if (tokens == NULL)
			continue ;
		add_history(str);
		free(str);
		rollback_terminal_setting();
		set_execution_signal();
		execute(tokens);
		free_tokens(tokens);
	}
}

int	main(int args, char **argv, char **envp)
{
	int		exit_code;

	(void)args;
	(void)argv;
	(void)envp;
	exit_code = 0;
	main_loop();
	return (rollback_terminal_setting(), exit_code);
}
