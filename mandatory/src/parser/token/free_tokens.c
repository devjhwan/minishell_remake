/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:50:43 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/29 12:06:02 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

void	free_tokens(t_token *tokens)
{
	t_token	*deltoken;

	while (tokens != NULL)
	{
		deltoken = tokens;
		tokens = tokens->next;
		free(deltoken->arg);
		deltoken->arg = NULL;
		deltoken->next = NULL;
		free(deltoken);
	}
}
