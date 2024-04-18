/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_tokens2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:33:58 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/07 21:11:22 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "libft.h"
#include <stdio.h>

int	join_quotes(t_token *tokens)
{
	char	*quote;
	char	*tmp;

	if (tokens->t != SQ && tokens->t != DQ)
		return (1);
	while (tokens->next != NULL && tokens->next->t != tokens->t)
		if (!join_consecutive_tokens(tokens))
			return (0);
	if (tokens->next != NULL)
		return (join_consecutive_tokens(tokens));
	else
	{
		if (tokens->t == SQ)
			quote = "\'";
		else
			quote = "\"";
		tmp = tokens->arg;
		tokens->arg = ft_strjoin(2, tmp, quote);
		free(tmp);
		if (tokens->arg == NULL)
			return (0);
	}
	return (1);
}

int	join_to_env(t_token *tokens)
{
	if (tokens->t != ENV)
		return (1);
	if (tokens->next == NULL || tokens->next->t != ARG)
	{
		tokens->t = ARG;
		if (tokens->prev != NULL && tokens->prev->t == ARG)
			return (join_consecutive_tokens(tokens->prev));
		return (1);
	}
	else
		return (join_consecutive_tokens(tokens));
	return (1);
}
