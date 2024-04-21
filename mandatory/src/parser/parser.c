/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:39:38 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/21 22:20:55 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "parser_token.h"
#include "parser_tree.h"

t_cmd	*parser(char *line, char **envp)
{
	t_ptoken	*tokens;
	t_ptree	*parser_tree;

	tokens = lexer(line);
	if (tokens == NULL)
		return (NULL);
	if (syntax_analyzer(tokens) == 0)
		return (free_tokens(tokens), NULL);
	// print_tokens(tokens);
	parser_tree = create_parser_tree(tokens);
	free_tokens(tokens);
	if (parser_tree == NULL)
		return (NULL);
	// print_parser_tree(parser_tree);
	if (expander(parser_tree, envp) == 0)
		return (free_tree(parser_tree), NULL);
	printf("\n");
	print_parser_tree(parser_tree);
	return (NULL);
}
