/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tree.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:30:53 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/27 17:17:28 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_TREE_H
# define PARSER_TREE_H

# include "parser_token.h"
# include "libft.h"
# include <stdlib.h>

typedef enum s_nodetype
{
	COMMAND,
	CONTENT,
	ARGUMENT,
	REDIRECTION,
	ARGUMENT_EXP
}	t_nodetype;

typedef struct s_ptree
{
	t_nodetype		t;
	char			*arg;
	struct s_ptree	*parent;
	struct s_ptree	*left;
	struct s_ptree	*right;
}	t_ptree;

int			expander(t_ptree *tree);

t_ptree		*create_parser_tree(t_ptoken *tokens);
t_ptree		*create_new_node(t_nodetype	t, char *arg);
t_ptree		*parse_command(t_ptoken *tokens);
t_ptree		*parse_content(t_ptoken **tokens);
t_ptree		*parse_argument(t_ptoken **tokens);
t_ptree		*parse_redirection(t_ptoken **tokens);
char		*join_tree_arguments(t_ptree *node);
void		print_parser_tree(t_ptree *tree);
void		free_tree(t_ptree *tree);

#endif