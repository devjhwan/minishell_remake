/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:48:55 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/18 21:22:39 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

int	expand_env(t_token *tokens, char **envp);
int	expand_wildcard(t_token *token);

int	expander(t_token *tokens, char **envp)
{
	while (tokens != NULL)
	{
		if (!expand_env(tokens, envp))
			return (0);
		if (!expand_wildcard(tokens))
			return (0);
		tokens = tokens->next;
	}
	return (1);
}
