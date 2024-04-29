/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_command_tokens.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:50:43 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/29 14:42:12 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

t_token	*get_next_command_tokens(t_token **tokens)
{
	t_token	*next_tokens;

	next_tokens = *tokens;
	if (*tokens != NULL)
		*tokens = (*tokens)->next;
	while (*tokens != NULL && (*tokens)->t != PIPE)
		(*tokens) = (*tokens)->next;
	if (*tokens != NULL && (*tokens)->prev != NULL)
	{
		(*tokens)->prev->next = NULL;
		(*tokens)->prev = NULL;
	}
	return (next_tokens);
}
