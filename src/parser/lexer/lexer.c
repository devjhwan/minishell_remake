/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:08:01 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/08 11:07:30 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

int	clean_tokens(t_token *tokens);

static int	check_token(int ch)
{
	if (ft_strchr(" \'\"<>|$&*", ch) == NULL)
		return (0);
	else
		return (1);
}

static int	add_arg(t_token **tokens, char *arg, int idx)
{
	char	*tmp_arg;

	tmp_arg = ft_substr(arg, 0, idx);
	if (tmp_arg == NULL)
		return (free_tokens(tokens), 0);
	if (!append_token(tokens, ARG, tmp_arg))
		return (free(tmp_arg), free_tokens(tokens), 0);
	return (1);
}

static t_token_type	get_token_type(char ch)
{
	if (ch == ' ')
		return (BK);
	if (ch == '\'')
		return (SQ);
	else if (ch == '\"')
		return (DQ);
	else if (ch == '<' || ch == '>')
		return (RD);
	else if (ch == '|')
		return (PIPE);
	else if (ch == '$')
		return (ENV);
	else if (ch == '&')
		return (AND);
	else if (ch == '*')
		return (WC);
	else
		return (ARG);
}

static int	add_tokens(t_token **tokens, int ch)
{
	char	*tmp_arg;

	tmp_arg = (char *)malloc(sizeof(char) * 2);
	if (tmp_arg == NULL)
		return (free_tokens(tokens), 0);
	tmp_arg[0] = ch;
	tmp_arg[1] = '\0';
	if (!append_token(tokens, get_token_type(ch), tmp_arg))
		return (free(tmp_arg), free_tokens(tokens), 0);
	return (1);
}

t_token	*lexer(char *arg)
{
	t_token	*tokens;
	int		idx;

	tokens = NULL;
	while (*arg != '\0')
	{
		idx = 0;
		while (arg[idx] != '\0' && !check_token(arg[idx]))
			idx++;
		if (idx > 0 && !add_arg(&tokens, arg, idx))
			return (NULL);
		if (arg[idx] != '\0' && !add_tokens(&tokens, arg[idx]))
			return (NULL);
		arg += idx;
		if (*arg != '\0')
			arg++;
	}
	if (!clean_tokens(tokens))
		return (free_tokens(&tokens), NULL);
	return (tokens);
}
