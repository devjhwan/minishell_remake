/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_new_executor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/26 03:03:33 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "utils.h"
#include "libft.h"

int		_check_redirs(t_redir *redir);
int		_set_exec_rdin(t_redir *redirs, t_redir **rdin);
int		_set_exec_rdout(t_redir *redirs, t_redir **rdin);

t_executor	*create_new_executor(t_cmd *cmd)
{
	t_executor	*exec;

	exec = (t_executor *)ft_calloc(1, sizeof(t_executor));
	if (exec == NULL)
		return (NULL);
	exec->args = copy_strarray(cmd->args);
	if (exec->args == NULL)
		return (free(exec), NULL);
	if (cmd->redirs != NULL)
	{
		if (_check_redirs(cmd->redirs) == 0)
			return (free_executor(&exec), NULL);
		if (_set_exec_rdin(cmd->redirs, &exec->in) == 0)
			return (free_executor(&exec), NULL);
		if (_set_exec_rdout(cmd->redirs, &exec->out) == 0)
			return (free_executor(&exec), NULL);
	}
	exec->islast = 0;
	if (cmd->next == NULL)
		exec->islast = 1;
	return (exec);
}
