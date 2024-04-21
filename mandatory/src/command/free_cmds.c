/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/21 16:45:35 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "utils.h"
#include <stdlib.h>

void	free_cmds(t_cmd **cmds)
{
	t_cmd	*cmd;

	cmd = *cmds;
	while (cmd != NULL)
	{
		*cmds = cmd->next;
		if (cmd->args != NULL)
			free_strarr(cmd->args);
		cmd->args = NULL;
		if (cmd->redirs != NULL)
			free_redirections(cmd->redirs);
		cmd->redirs = NULL;
		cmd->next = NULL;
		free(cmd);
		cmd = *cmds;
	}
}
