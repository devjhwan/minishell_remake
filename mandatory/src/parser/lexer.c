/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:47:07 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/29 14:25:02 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "libft.h"

int	ispipe(char *line);
int	isredir(char *line);
int	isenv(char *line);
int	isquote(char *line);
int	isdquote(char *line);
int	is_space(char *line);
int	isargument(char *line);

t_token	*lexer(char *line)
{
	t_token	*tokens;

	tokens = NULL;
	while (*line != '\0')
	{
		if (isquote(line) && append_token(&tokens, &line, SQ) == 0)
			return (free_tokens(tokens), NULL);
		else if (isdquote(line) && append_token(&tokens, &line, DQ) == 0)
			return (free_tokens(tokens), NULL);
		else if (ispipe(line) && append_token(&tokens, &line, PIPE) == 0)
			return (free_tokens(tokens), NULL);
		else if (isredir(line) && append_token(&tokens, &line, RD) == 0)
			return (free_tokens(tokens), NULL);
		else if (isenv(line) && append_token(&tokens, &line, ENV) == 0)
			return (free_tokens(tokens), NULL);
		else if (is_space(line) && append_token(&tokens, &line, SP) == 0)
			return (free_tokens(tokens), NULL);
		else if (isargument(line) && append_token(&tokens, &line, ARG) == 0)
			return (free_tokens(tokens), NULL);
	}
	if (syntax_analyzer(tokens) == 0)
		return (free_tokens(tokens), NULL);
	return (tokens);
}
