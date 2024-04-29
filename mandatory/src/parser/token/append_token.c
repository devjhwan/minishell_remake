/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:55:20 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/29 12:06:02 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

char	*substr_pipe(char **line);
char	*substr_redir(char **line);
char	*substr_env(char **line);
char	*substr_quote(char **line);
char	*substr_dquote(char **line);
char	*substr_space(char **line);
char	*substr_argument(char **line);

int	append_token(t_token **tokens, char **line, t_tokentype t)
{
	char		*arg;
	t_token	*new_token;

	arg = NULL;
	if (t == PIPE)
		arg = substr_pipe(line);
	else if (t == RD)
		arg = substr_redir(line);
	else if (t == ENV)
		arg = substr_env(line);
	else if (t == SQ)
		arg = substr_quote(line);
	else if (t == DQ)
		arg = substr_dquote(line);
	else if (t == SP)
		arg = substr_space(line);
	else if (t == ARG)
		arg = substr_argument(line);
	if (arg == NULL)
		return (0);
	new_token = create_new_token(t, arg);
	if (new_token == NULL)
		return (free(arg), 0);
	push_back_token(tokens, new_token);
	return (1);
}
