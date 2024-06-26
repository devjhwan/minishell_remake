/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_new_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/22 02:01:59 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

t_cmd	*create_new_cmd(t_cmdtype t)
{
	t_cmd	*cmd;

	if (t == ERR)
		return (NULL);
	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (cmd == NULL)
		return (NULL);
	cmd->t = t;
	cmd->args = NULL;
	cmd->redirs = NULL;
	cmd->next = NULL;
	return (cmd);
}
