/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_parser_tree.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:34:55 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/21 22:16:33 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_tree.h"

/**
 * BNF TREE RESUME
 * 
 * <COMMAND>        ::= WORD <CONTENT_L> | WORD <CONTENT_L> <COMMAND>
 * <CONTENT>        ::= <ARGUMENT> | <REDIRECTION> | 
 *                      <ARGUMENT> <CONTENT> | 
 *                      <REDIRECTION> <CONTENT>
 * <ARGUMENT>       ::= WORD | WORD <ARGUMENT>
 * <REDIRECTION>    ::= WORD <ARGUMENT>
 */
t_ptree	*create_parser_tree(t_ptoken *tokens)
{
	t_ptoken	*initial_token;
	t_ptree		*tree;

	initial_token = (t_ptoken *)malloc(sizeof(t_ptoken));
	if (initial_token == NULL)
		return (NULL);
	initial_token->t = PIPE;
	initial_token->arg = ft_strdup("|");
	if (initial_token->arg == NULL)
		return (free(initial_token), NULL);
	initial_token->next = tokens;
	initial_token->prev = NULL;
	tree = parse_command(initial_token);
	free(initial_token->arg);
	free(initial_token);
	return (tree);
}
