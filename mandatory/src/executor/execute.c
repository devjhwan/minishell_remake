/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/22 02:03:52 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"

void	execute(t_shell *shell)
{
	t_cmd		*cmds;
	t_executor	*exec;

	cmds = shell->cmds;
	while (cmds != NULL)
	{
		exec = create_new_executor(cmds);
		if (exec != NULL)
		{
			free_executor(&exec);
		}
		cmds = cmds->next;
	}
}