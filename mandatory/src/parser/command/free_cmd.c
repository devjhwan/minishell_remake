/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/29 14:17:06 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "utils.h"
#include <stdlib.h>

void	free_cmd(t_cmd *cmd)
{
	while (cmd != NULL)
	{
		if (cmd->args != NULL)
			free_strarray(cmd->args);
		cmd->args = NULL;
		if (cmd->redirs != NULL)
			free_redirections(cmd->redirs);
		cmd->redirs = NULL;
		free(cmd);
	}
}
