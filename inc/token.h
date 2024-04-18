/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:24:41 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/08 11:09:37 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include <stdlib.h>
# include "libft.h"

typedef enum e_token_type
{
	ARG,
	BK,
	SQ,
	DQ,
	RD,
	PIPE,
	ENV,
	AND,
	OR,
	WC
}	t_token_type;

typedef struct s_token
{
	t_token_type		t;
	char				*arg;
	struct s_token		*next;
	struct s_token		*prev;
}	t_token;

typedef struct s_cmds	t_cmds;

t_token	*lexer(char *arg);
int		syntax_analyzer(t_token *tokens);
int		expander(t_token *tokens, char **envp);
t_cmds	*parser(t_token *tokens);
int		set_cmd(t_cmds *cmd, t_token **tokens);

t_token	*get_last_token(t_token *token_list);
t_token	*create_new_token(t_token_type t, char *arg);
int		append_token(t_token **token_list, t_token_type t, char *arg);
int		join_consecutive_tokens(t_token *token);
void	delete_token(t_token *token);
void	free_tokens(t_token **token_list);
void	print_token_list(t_token *token_list);

#endif
