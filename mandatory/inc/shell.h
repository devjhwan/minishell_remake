/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:53:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/28 17:54:45 by junghwle         ###   ########.fr       */
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
	char	*pwd_save;
	char	*pwd;
	char	*oldpwd;
	int		fdin;
	int		fdout;
	int		exit_code;
	int		new_exit_code;
	int		is_exit;
}	t_shell;

t_shell	*get_shell_struct(void);
t_shell	*init_shell_struct(int as, char **av, char **ep);
void	free_shell_struct(t_shell **shell);
void	manage_shlvl(t_shell *shell);

#endif