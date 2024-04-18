/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_consecutive_tokens.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:40:09 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/07 21:11:01 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "libft.h"

int	join_consecutive_tokens(t_token *token)
{
	t_token	*del_token;
	char	*tmp;

	if (token->next == NULL)
		return (1);
	tmp = token->arg;
	token->arg = ft_strjoin(2, tmp, token->next->arg);
	free(tmp);
	if (token->arg == NULL)
		return (0);
	del_token = token->next;
	token->next = del_token->next;
	if (del_token->next != NULL)
		del_token->next->prev = token;
	delete_token(del_token);
	return (1);
}
