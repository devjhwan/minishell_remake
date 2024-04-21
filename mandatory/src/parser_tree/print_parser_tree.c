/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_parser_tree.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:14:32 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/21 20:23:11 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_tree.h"
#include <stdio.h>

static char	*get_enum_name(t_nodetype t)
{
	if (t == COMMAND)
		return ("COMMAND");
	else if (t == CONTENT_L)
		return ("CONTENT_L");
	else if (t == CONTENT)
		return ("CONTENT");
	else if (t == ARGUMENT_L)
		return ("ARGUMENT_L");
	else if (t == ARGUMENT_STR)
		return ("ARGUMENT_STR");
	else if (t == ARGUMENT)
		return ("ARGUMENT");
	else if (t == REDIRECTION)
		return ("REDIRECTION");
	else
		return ("UNKNOWN");
}

static void	print_node(t_ptree *node, int depth)
{
	int	i;

	if (node != NULL)
	{
		if (node->left != NULL)
			print_node(node->left, depth + 1);
		i = 0;
		while (i++ < depth)
			printf("\t");
		printf("{ type = %s, arg = %s }\n", get_enum_name(node->t), node->arg);
		if (node->right != NULL)
			print_node(node->right, depth + 1);
	}
}

void	print_parser_tree(t_ptree *tree)
{
	print_node(tree, 0);
}
