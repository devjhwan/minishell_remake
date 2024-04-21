/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:47:07 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/21 18:37:45 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_token.h"
#include "libft.h"

int	_ispipe(char *line);
int	_isredir(char *line);
int	_isenv(char *line);
int	_isquote(char *line);
int	_isdquote(char *line);
int	_isspace(char *line);
int	_isargument(char *line);

t_ptoken	*lexer(char *line)
{
	t_ptoken	*tokens;

	tokens = NULL;
	while (*line != '\0')
	{
		if (_ispipe(line) && append_token(&tokens, &line, PIPE) == 0)
			return (free_tokens(tokens), NULL);
		else if (_isredir(line) && append_token(&tokens, &line, RD) == 0)
			return (free_tokens(tokens), NULL);
		else if (_isenv(line) && append_token(&tokens, &line, ENV) == 0)
			return (free_tokens(tokens), NULL);
		else if (_isquote(line) && append_token(&tokens, &line, SQ) == 0)
			return (free_tokens(tokens), NULL);
		else if (_isdquote(line) && append_token(&tokens, &line, DQ) == 0)
			return (free_tokens(tokens), NULL);
		else if (_isspace(line) && append_token(&tokens, &line, SP) == 0)
			return (free_tokens(tokens), NULL);
		else if (_isargument(line) && append_token(&tokens, &line, ARG) == 0)
			return (free_tokens(tokens), NULL);
	}
	return (tokens);
}
