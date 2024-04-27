/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:31:04 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/27 14:44:25 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_tree.h"
#include <stdlib.h>

static t_ptree	*create_and_parse_content(t_ptoken **tokens)
{
	t_ptree	*content;

	content = create_new_node(CONTENT, NULL);
	if (content == NULL)
		return (NULL);
	if ((*tokens)->t == ARG || (*tokens)->t == ENV || \
		(*tokens)->t == SQ || (*tokens)->t == DQ)
	{
		content->left = parse_argument(tokens);
		if (content->left == NULL)
			return (free_tree(content), NULL);
	}
	else if ((*tokens)->t == RD)
	{
		content->left = parse_redirection(tokens);
		if (content->left == NULL)
			return (free_tree(content), NULL);
	}
	content->left->parent = content;
	return (content);
}

t_ptree	*parse_content(t_ptoken **tokens)
{
	t_ptree	*content;

	content = create_and_parse_content(tokens);
	*tokens = skip_space_tokens(*tokens);
	if (*tokens != NULL)
	{
		if (*tokens == NULL)
			return (content);
		if ((*tokens)->t != PIPE)
		{
			content->right = parse_content(tokens);
			if (content->right == NULL)
				return (free_tree(content), NULL);
		}
	}
	return (content);
}
