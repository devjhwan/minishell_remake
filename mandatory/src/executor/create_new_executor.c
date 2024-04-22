/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_new_executor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/22 11:29:52 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "libft.h"

char	**set_exec_args(char **args, char **envp);
int		check_redirs(t_redir *redir);
int		set_exec_rdin(t_redir *redirs, t_redir **rdin);
int		set_exec_rdout(t_redir *redirs, t_redir **rdin);

t_executor	*create_new_executor(t_cmd *cmd, char **envp)
{
	t_executor	*exec;

	exec = (t_executor *)ft_calloc(1, sizeof(t_executor));
	if (exec == NULL)
		return (NULL);
	exec->args = set_exec_args(cmd->args, envp);
	if (exec->args == NULL)
		return (free(exec), NULL);
	if (cmd->redirs != NULL)
	{
		if (check_redirs(cmd->redirs) == 0)
			return (free_executor(&exec), NULL);
		if (set_exec_rdin(cmd->redirs, &exec->in) == 0)
			return (free_executor(&exec), NULL);
		if (set_exec_rdout(cmd->redirs, &exec->out) == 0)
			return (free_executor(&exec), NULL);
	}
	return (exec);
}
