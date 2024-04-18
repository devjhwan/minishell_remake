/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/18 21:50:17 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int	main(int args, char **argv, char **envp)
{
	t_sehll	shell;
	char	*str;

	(void) args;
	(void) argv;
	while (1)
	{
		set_default_minishell_signal();
		set_minishell_terminal();
		str = readline("minishell: ");
		if (str == NULL)
			break ;
		add_history(str);
		shell.cmds = parse_command(str, envp);
		free(str);
		if (shell.cmds == NULL)
			continue ;
		rollback_terminal_setting();
		set_execution_signal();
		free_cmds(shell.cmds);
		shell.cmds = NULL;
	}
	return (rollback_terminal_setting(), 0);
}
