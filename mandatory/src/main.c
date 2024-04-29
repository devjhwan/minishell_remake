/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/29 14:50:50 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "setup.h"
#include "lexer.h"
#include "executor.h"
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

void	main_loop(t_shell *shell)
{
	char	*str;
	t_token	*tokens;

	while (!shell->is_exit)
	{
		set_default_minishell_signal();
		set_minishell_terminal();
		str = readline("minishell: ");
		if (str == NULL)
			break ;
		add_history(str);
		tokens = lexer(str);
		if (tokens == NULL)
			continue ;
		free(str);
		rollback_terminal_setting();
		set_execution_signal();
		execute(tokens);
	}
}

int	main(int args, char **argv, char **envp)
{
	int		exit_code;
	t_shell	*shell;

	shell = init_shell(args, argv, envp);
	if (shell == NULL)
		return (1);
	main_loop(shell);
	exit_code = shell->exit_code;
	free_shell(shell);
	return (rollback_terminal_setting(), exit_code);
}
