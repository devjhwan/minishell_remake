/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:15:55 by junghwle          #+#    #+#             */
/*   Updated: 2024/03/29 11:17:10 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

int	append_token(t_token **token_list, t_token_type t, char *arg)
{
	t_token	*last;
	t_token	*new_token;

	new_token = create_new_token(t, arg);
	if (new_token == NULL)
		return (0);
	last = get_last_token(*token_list);
	if (last == NULL)
		*token_list = new_token;
	else
	{
		new_token->prev = last;
		last->next = new_token;
	}
	return (1);
}
