/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_new_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 17:17:18 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/21 18:37:45 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_token.h"

t_ptoken	*create_new_token(t_tokentype t, char *arg)
{
	t_ptoken	*new_token;

	new_token = (t_ptoken *)malloc(sizeof(t_ptoken));
	if (new_token == NULL)
		return (NULL);
	new_token->t = t;
	new_token->arg = arg;
	new_token->next = NULL;
	new_token->prev = NULL;
	return (new_token);
}
