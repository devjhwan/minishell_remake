/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:53:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/22 11:40:34 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "command.h"
# include <stdlib.h>

typedef struct s_executor
{
	char	**args;
	t_redir	*in;
	t_redir	*out;
}	t_executor;

t_executor	*create_new_executor(t_cmd *cmd, char **envp);
void		free_executor(t_executor **exec);
void		print_executor(t_executor *exec);

#endif