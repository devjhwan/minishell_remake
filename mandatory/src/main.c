/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/26 21:31:14 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
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

	while (!shell->is_exit)
	{
		free_cmds(&shell->cmds);
		set_default_minishell_signal();
		set_minishell_terminal();
		str = readline("minishell: ");
		if (str == NULL)
			break ;
		add_history(str);
		shell->cmds = parser(str);
		free(str);
		if (shell->cmds == NULL || shell->is_exit)
			continue ;
		rollback_terminal_setting();
		set_execution_signal();
		execute(shell);
	}
}

int	main(int args, char **argv, char **envp)
{
	t_shell	*shell;
	int		exit_code;

	shell = init_shell_struct(args, argv, envp);
	if (shell == NULL)
		return (0);
	main_loop(shell);
	exit_code = shell->exit_code;
	free_shell_struct(&shell);
	return (rollback_terminal_setting(), exit_code);
}
