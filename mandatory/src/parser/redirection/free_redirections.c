/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_redirections.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:45:41 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/29 12:23:45 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirection.h"
#include <stdlib.h>

void	free_redirections(t_redir *redir)
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
