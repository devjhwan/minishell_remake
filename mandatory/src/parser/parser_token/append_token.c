/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:55:20 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/25 13:05:32 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_token.h"

char	*_substr_pipe(char **line);
char	*_substr_redir(char **line);
char	*_substr_env(char **line);
char	*_substr_quote(char **line);
char	*_substr_dquote(char **line);
char	*_substr_space(char **line);
char	*_substr_argument(char **line);

int	append_token(t_ptoken **tokens, char **line, t_tokentype t)
{
	char		*arg;
	t_ptoken	*new_token;

	arg = NULL;
	if (t == PIPE)
		arg = _substr_pipe(line);
	else if (t == RD)
		arg = _substr_redir(line);
	else if (t == ENV)
		arg = _substr_env(line);
	else if (t == SQ)
		arg = _substr_quote(line);
	else if (t == DQ)
		arg = _substr_dquote(line);
	else if (t == SP)
		arg = _substr_space(line);
	else if (t == ARG)
		arg = _substr_argument(line);
	if (arg == NULL)
		return (0);
	new_token = create_new_token(t, arg);
	if (new_token == NULL)
		return (free(arg), 0);
	push_back_token(tokens, new_token);
	return (1);
}
