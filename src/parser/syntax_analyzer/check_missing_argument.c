/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_missing_argument.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 11:54:19 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/08 11:08:06 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "utils.h"

static int	find_prev_argument(t_token *tokens)
{
	tokens = tokens->prev;
	while (tokens != NULL && \
			!(tokens->t == PIPE || tokens->t == OR || tokens->t == AND))
	{
		if (tokens->t != BK)
			return (1);
		tokens = tokens->prev;
	}
	return (0);
}

static int	find_next_argument(t_token *tokens)
{
	tokens = tokens->next;
	while (tokens != NULL && \
			!(tokens->t == PIPE || tokens->t == OR || tokens->t == AND))
	{
		if (tokens->t != BK)
			return (1);
		tokens = tokens->next;
	}
	return (0);
}

/*Only checks for |, || and &&*/
int	check_missing_argument(t_token *tokens)
{
	if (!find_next_argument(tokens) || !find_prev_argument(tokens))
	{
		print_error(UNEXPECTED_TOKEN, tokens->arg, NULL);
		return (0);
	}
	return (1);
}
