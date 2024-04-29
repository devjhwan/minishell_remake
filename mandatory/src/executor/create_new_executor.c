/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_new_executor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/29 13:27:50 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "utils.h"
#include "libft.h"

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
		if (check_redirs(cmd->redirs) == 0)
			return (free_executor(&exec), NULL);
		if (set_exec_rdin(cmd->redirs, exec) == 0)
			return (free_executor(&exec), NULL);
		if (set_exec_rdout(cmd->redirs, exec) == 0)
			return (free_executor(&exec), NULL);
	}
	exec->islast = 0;
	if (cmd->next == NULL)
		exec->islast = 1;
	return (exec);
}
