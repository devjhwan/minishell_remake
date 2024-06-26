/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:53:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/26 21:34:36 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "shell.h"
# include "command.h"
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_executor
{
	char	**args;
	t_redir	*in;
	t_redir	*out;
	int		islast;
}	t_executor;

void		execute(t_shell *shell);
pid_t		execute_command(t_executor *exec, t_shell *shell);
void		execute_builtin(t_executor *exec, t_shell *shell);
void		exec_echo(char **args);
void		exec_env(char **args, char **env);
void		exec_export(char **args, t_shell *shell);
void		exec_exit(char **args, t_shell *shell);
void		exec_unset(char **args, t_shell *shell);
void		exec_pwd(t_shell *shell);
void		exec_cd(char **args, t_shell *shell);

t_executor	*create_new_executor(t_cmd *cmd);
void		free_executor(t_executor **exec);
void		print_executor(t_executor *exec);

#endif