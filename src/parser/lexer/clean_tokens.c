/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:38:56 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/08 11:08:06 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "libft.h"

int	join_quotes(t_token *tokens);
int	join_to_env(t_token *tokens);

static int	join_redirections(t_token *tokens)
{
	if (tokens->next == NULL || tokens->t != RD || tokens->next->t != RD)
		return (1);
	if ((!ft_strncmp(tokens->arg, "<", 2) && \
		!ft_strncmp(tokens->next->arg, "<", 2)) || \
		(!ft_strncmp(tokens->arg, ">", 2) && \
		!ft_strncmp(tokens->next->arg, ">", 2)))
		return (join_consecutive_tokens(tokens));
	return (1);
}

static int	join_to_or(t_token *tokens)
{
	if (tokens->next == NULL || tokens->t != PIPE || tokens->next->t != PIPE)
		return (1);
	tokens->t = OR;
	return (join_consecutive_tokens(tokens));
}

static int	join_ands(t_token *tokens)
{
	if (tokens->next == NULL || tokens->t != AND || tokens->next->t != AND)
		return (1);
	if (!ft_strncmp(tokens->arg, "&", 2) && \
		!ft_strncmp(tokens->next->arg, "&", 2))
		return (join_consecutive_tokens(tokens));
	return (1);
}

static int	transform_to_arg(t_token *tokens)
{
	if (!(tokens->t == AND && (tokens->next == NULL || \
			tokens->next->t != AND) && !ft_strncmp(tokens->arg, "&", 2)))
		return (1);
	tokens->t = ARG;
	if (tokens->next != NULL && tokens->next->t == ARG)
		return (join_consecutive_tokens(tokens));
	return (1);
}

int	clean_tokens(t_token *tokens)
{
	while (tokens != NULL)
	{
		if (!join_quotes(tokens))
			return (0);
		if (!join_redirections(tokens))
			return (0);
		if (!join_to_or(tokens))
			return (0);
		if (!join_ands(tokens))
			return (0);
		if (!transform_to_arg(tokens))
			return (0);
		if (!join_to_env(tokens))
			return (0);
		tokens = tokens->next;
	}
	return (1);
}
