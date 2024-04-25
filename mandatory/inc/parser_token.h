/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_token.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:36:05 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/25 13:21:12 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_TOKEN_H
# define PARSER_TOKEN_H

# include <stdlib.h>

typedef enum e_tokentype
{
	ARG,
	SQ,
	DQ,
	ENV,
	SP,
	RD,
	PIPE
}	t_tokentype;

typedef struct s_token
{
	t_tokentype		t;
	char			*arg;
	struct s_token	*next;
	struct s_token	*prev;
}	t_ptoken;

t_ptoken	*lexer(char *line);
int			syntax_analyzer(t_ptoken *tokens);

t_ptoken	*create_new_token(t_tokentype t, char *arg);
void		push_back_token(t_ptoken **tokens, t_ptoken *new_token);
int			append_token(t_ptoken **tokens, char **line, t_tokentype t);
void		free_tokens(t_ptoken *tokens);
void		print_tokens(t_ptoken *tokens);
t_ptoken	*skip_space_tokens(t_ptoken *tokens);

#endif