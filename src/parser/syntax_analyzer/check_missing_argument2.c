/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_missing_argument2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 11:55:49 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/08 11:08:06 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "utils.h"

static int	find_next_argument(t_token *tokens)
{
	if (tokens->t != RD)
		return (1);
	tokens = tokens->next;
	while (tokens != NULL && \
			!(tokens->t == RD || tokens->t == PIPE || \
			tokens->t == OR || tokens->t == AND))
	{
		if (tokens->t != BK)
			return (1);
		tokens = tokens->next;
	}
	return (0);
}

/*Only checks for redirections*/
int	check_missing_argument2(t_token *tokens)
{
	while (tokens != NULL)
	{
		if (!find_next_argument(tokens))
		{
			tokens = tokens->next;
			while (tokens != NULL && \
				!(tokens->t == RD || tokens->t == PIPE || \
				tokens->t == OR || tokens->t == AND))
				tokens = tokens->next;
			if (tokens == NULL)
				print_error(UNEXPECTED_TOKEN, "newline", NULL);
			else
				print_error(UNEXPECTED_TOKEN, tokens->arg, NULL);
			return (0);
		}
		tokens = tokens->next;
	}
	return (1);
}
