/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_executor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/22 02:07:33 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "utils.h"

void	free_executor(t_executor **exec)
{
	if (*exec != NULL)
	{
		free_strarr((*exec)->args);
		(*exec)->args = NULL;
		free_redirections((*exec)->in);
		(*exec)->in = NULL;
		free_redirections((*exec)->out);
		(*exec)->out = NULL;
		free(*exec);
		*exec = NULL;
	}
}
