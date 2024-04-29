/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:53:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/29 12:59:25 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "token.h"
# include "command.h"

typedef struct s_executor
{
	char	**args;
	t_redir	*rdin;
	t_redir	*rdout;
	int		islast;
}	t_executor;

void		execute(t_token	*tokens);

t_executor	*create_new_executor(t_cmd *cmd);
void		print_executor(t_executor *exec);
int			set_exec_rdin(t_redir *redirs, t_executor *exec);
int			set_exec_rdout(t_redir *redirs, t_executor *exec);
void		free_executor(t_executor **exec);

#endif