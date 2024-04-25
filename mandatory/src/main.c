/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/25 22:41:35 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int	main(int args, char **argv, char **envp)
{
	t_shell	shell;
	char	*str;
	int		exit_code;

	init_shell_struct(&shell, args, argv, envp);
	while (!shell.is_exit)
	{
		free_cmds(&shell.cmds);
		set_default_minishell_signal();
		set_minishell_terminal();
		str = readline("minishell: ");
		if (str == NULL)
			break ;
		add_history(str);
		shell.cmds = parser(str, &shell);
		free(str);
		if (shell.cmds == NULL || shell.is_exit)
			continue ;
		rollback_terminal_setting();
		set_execution_signal();
		execute(&shell);
	}
	exit_code = shell.exit_code;
	free_shell_struct(&shell);
	return (rollback_terminal_setting(), exit_code);
}
