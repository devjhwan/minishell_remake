/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:50:43 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/21 18:37:45 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_token.h"

void	free_tokens(t_ptoken *tokens)
{
	t_ptoken	*deltoken;

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
