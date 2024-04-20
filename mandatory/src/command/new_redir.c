/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/20 03:39:19 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include <stdlib.h>

t_redir	*new_redir(t_rdtype t, char *filename)
{
	t_redir	*redir;

	redir = (t_redir *)malloc(sizeof(t_redir));
	if (redir == NULL)
		return (NULL);
	redir->t = t;
	redir->filename = filename;
	redir->next = NULL;
	return (redir);
}
