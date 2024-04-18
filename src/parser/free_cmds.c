/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:44:07 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/18 21:48:43 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmds.h"

static void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
		free(args[i++]);
	free(args);
}

static void	free_redirections(t_redirs *redirs)
{
	t_redirs	*delnode;

	while (redirs != NULL)
	{
		delnode = redirs;
		redirs = redirs->next;
		free(delnode->file_name);
		delnode->file_name = NULL;
		delnode->next = NULL;
		free(delnode);
	}
}

void	free_cmds(t_cmds *cmds)
{
	t_cmds	*delnode;

	while (cmds != NULL)
	{
		delnode = cmds;
		cmds = cmds->next;
		free_args(delnode->args);
		delnode->args = NULL;
		free_redirections(delnode->rd_arr);
		delnode->rd_arr = NULL;
		delnode->next = NULL;
		free(delnode);
	}
}
