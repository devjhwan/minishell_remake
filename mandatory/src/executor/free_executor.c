/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_executor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/29 12:54:40 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "utils.h"

void	free_executor(t_executor **exec)
{
	if (*exec != NULL)
	{
		free_strarray((*exec)->args);
		(*exec)->args = NULL;
		free_redirections((*exec)->rdin);
		(*exec)->rdin = NULL;
		free_redirections((*exec)->rdout);
		(*exec)->rdout = NULL;
		free(*exec);
		*exec = NULL;
	}
}
