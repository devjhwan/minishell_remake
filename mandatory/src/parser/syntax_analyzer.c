/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analyzer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:08:33 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/29 12:06:02 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "print_error.h"

static int	is_next_argument_rd(t_token *token)
{
	token = token->next;
	while (token != NULL)
	{
		if (token->t != SP && token->t != RD && token->t != PIPE)
			return (1);
		else if (token->t == RD || token->t == PIPE)
			return (0);
		token = token->next;
	}
	return (0);
}

static int	is_next_argument_pipe(t_token *token)
{
	token = token->next;
	while (token != NULL)
	{
		if (token->t != SP && token->t != PIPE)
			return (1);
		else if (token->t == PIPE)
			return (0);
		token = token->next;
	}
	return (0);
}

static int	is_prev_argument(t_token *token)
{
	token = token->prev;
	while (token != NULL)
	{
		if (token->t == ARG || token->t == SQ || \
			token->t == DQ || token->t == ENV)
			return (1);
		else if (token->t == RD || token->t == PIPE)
			return (0);
		token = token->prev;
	}
	return (0);
}

/**
 * Searchs for the first not empty argument and returns it's value.
 * If value is NULL then function has reached to the end without any arguments.
*/
static char	*get_next_token_argument(t_token *token)
{
	token = token->next;
	while (token != NULL)
	{
		if (token->t != SP)
			return (token->arg);
		token = token->next;
	}
	return ("newline");
}

int	syntax_analyzer(t_token *tokens)
{
	while (tokens != NULL)
	{
		if (tokens->t == RD && is_next_argument_rd(tokens) == 0)
		{
			print_error(UNEXPECTED_TOKEN, \
						get_next_token_argument(tokens), NULL);
			return (0);
		}
		else if (tokens->t == PIPE)
		{
			if (is_prev_argument(tokens) == 0)
				return (print_error(UNEXPECTED_TOKEN, "|", NULL), 0);
			else if (is_next_argument_pipe(tokens) == 0)
			{
				print_error(UNEXPECTED_TOKEN, \
							get_next_token_argument(tokens), NULL);
				return (0);
			}
		}
		tokens = tokens->next;
	}
	return (1);
}
