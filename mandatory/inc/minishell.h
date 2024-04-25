/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:53:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/25 13:02:58 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "command.h"

typedef struct s_shell
{
	t_cmd	*cmds;
	char	**env;
	char	**export;
	int		stdinfd_cpy;
	int		stdoutfd_cpy;
	int		fdin;
	int		exit_code;
}	t_shell;

t_cmd	*parser(char *line, t_shell *shell);

void	set_minishell_terminal(void);
void	rollback_terminal_setting(void);
void	set_default_minishell_signal(void);
void	set_execution_signal(void);

int		init_shell_struct(t_shell *shell, int as, char **av, char **ep);
void	free_shell_struct(t_shell *shell);

#endif