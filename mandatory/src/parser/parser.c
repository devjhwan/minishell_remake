/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:39:38 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/26 21:15:28 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "parser_token.h"
#include "parser_tree.h"

t_cmd	*_parse_tree_to_cmds(t_ptree *tree);

t_cmd	*parser(char *line)
{
	t_ptoken	*tokens;
	t_ptree		*parser_tree;
	t_cmd		*cmds;

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
	if (expander(parser_tree) == 0)
		return (free_tree(parser_tree), NULL);
	// print_parser_tree(parser_tree);
	cmds = _parse_tree_to_cmds(parser_tree);
	free_tree(parser_tree);
	// print_command(cmds);
	return (cmds);
}
