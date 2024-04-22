/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:53:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/22 01:31:01 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "command.h"

typedef struct	s_shell
{
	t_cmd	*cmds;
	char	**env;
}	t_shell;

t_cmd	*parser(char *line, char **envp);
void	execute(t_shell *shell);

void	set_minishell_terminal(void);
void	rollback_terminal_setting(void);
void	set_default_minishell_signal(void);
void	set_execution_signal(void);

#endif