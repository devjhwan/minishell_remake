/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:53:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/26 00:29:14 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

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
	int		is_exit;
}	t_shell;

int		init_shell_struct(t_shell *shell, int as, char **av, char **ep);
void	free_shell_struct(t_shell *shell);

#endif