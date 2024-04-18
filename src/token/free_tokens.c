/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:58:28 by junghwle          #+#    #+#             */
/*   Updated: 2024/03/26 20:25:11 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

void	free_tokens(t_token **token_list)
{
	t_token	*del_token;

	while (*token_list != NULL)
	{
		del_token = *token_list;
		*token_list = (*token_list)->next;
		free(del_token->arg);
		free(del_token);
	}
}
