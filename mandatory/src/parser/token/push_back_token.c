/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 17:15:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/29 12:06:02 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

void	push_back_token(t_token **tokens, t_token *new_token)
{
	t_token	*tmp;

	if (*tokens == NULL)
		*tokens = new_token;
	else
	{
		tmp = *tokens;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_token;
		new_token->prev = tmp;
	}
}
