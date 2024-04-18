/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:49:14 by junghwle          #+#    #+#             */
/*   Updated: 2024/03/29 11:17:19 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

void	delete_token(t_token *token)
{
	free(token->arg);
	token->arg = NULL;
	token->next = NULL;
	token->prev = NULL;
	free(token);
}
