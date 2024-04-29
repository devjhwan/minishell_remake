/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:36:05 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/29 13:50:43 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

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
}	t_token;

t_token	*create_new_token(t_tokentype t, char *arg);
void	push_back_token(t_token **tokens, t_token *new_token);
int		append_token(t_token **tokens, char **line, t_tokentype t);
void	free_tokens(t_token *tokens);
void	print_tokens(t_token *tokens);
t_token	*get_next_command_tokens(t_token **tokens);

#endif