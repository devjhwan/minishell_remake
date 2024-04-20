/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/20 01:44:34 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include <stdlib.h>

static void	free_cmd_arguments(char **args)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
	{
		free(args[i]);
		args[i] = NULL;
		i++;
	}
	free(args);
}

static void	free_cmd_redirections(t_redir *redir)
{
	t_redir	*tmp;

	tmp = redir;
	while (tmp != NULL)
	{
		redir = tmp->next;
		free(tmp->filename);
		tmp->filename = NULL;
		tmp->next = NULL;
		free(tmp);
		tmp = redir;
	}
}

void	free_cmds(t_cmd **cmds)
{
	t_cmd	*cmd;

	cmd = *cmds;
	while (cmd != NULL)
	{
		*cmds = cmd->next;
		if (cmd->args != NULL)
			free_cmd_arguments(cmd->args);
		cmd->args = NULL;
		if (cmd->redirs != NULL)
			free_cmd_redirections(cmd->redirs);
		cmd->redirs = NULL;
		cmd->next = NULL;
		free(cmd);
		cmd = *cmds;
	}
}
