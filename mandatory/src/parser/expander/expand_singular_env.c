/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_singular_env.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 21:52:18 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/28 15:44:29 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "utils.h"
#include "parser_tree.h"
#include <stdlib.h>
#include <stdio.h>

static void	transport_adjacent_arguments(t_ptree *node, t_ptree *adj_argnode)
{
	node = node->left;
	if (node != NULL)
	{
		while (node->right != NULL)
			node = node->right;
		if (node->right != adj_argnode)
			node->right = adj_argnode;
	}
}

static int	append_new_node(char *arg, t_ptree *content)
{
	t_ptree	*new_content;

	new_content = create_new_node(CONTENT, NULL);
	if (new_content == NULL)
		return (0);
	new_content->left = create_new_node(ARGUMENT_EXP, arg);
	if (new_content->left == NULL)
		return (free_tree(new_content), 0);
	new_content->right = content->right;
	content->right = new_content;
	return (1);
}

static int	split_arguments(char **split, t_ptree *node, t_ptree *adj_argnode)
{
	int	i;

	node->right = NULL;
	i = 1;
	while (node->t != CONTENT)
		node = node->parent;
	while (split[i] != NULL)
	{
		if (append_new_node(split[i], node) == 0)
			return (0);
		i++;
		node = node->right;
	}
	transport_adjacent_arguments(node, adj_argnode);
	return (1);
}

static int	expand_argument_node(char *new_arg, t_ptree *node)
{
	char	**split;

	split = ft_split(new_arg, " ");
	if (split == NULL)
		return (free(new_arg), 0);
	free(node->arg);
	if (split[0] != NULL)
		node->arg = ft_strdup(split[0]);
	else
		node->arg = ft_strdup("");
	if (node->arg == NULL || split[0] == NULL)
		return (free_strarray(split), 0);
	if (split_arguments(split, node, node->right))
		return (free_strarray(split), 1);
	else
		return (free_strarray(split), 0);
}

int	expand_singular_env(t_ptree *node)
{
	char	*new_arg;

	if (node->arg[1] == '\'' || node->arg[1] == '\"')
	{
		new_arg = remove_quote(node->arg + 1);
		if (new_arg == NULL)
			return (0);
		free(node->arg);
		node->arg = new_arg;
	}
	else
	{
		new_arg = search_environment(node->arg + 1);
		if (new_arg == NULL || ft_strchr(new_arg, ' ') == NULL)
		{
			free(node->arg);
			node->arg = new_arg;
			return (1);
		}
		if (expand_argument_node(new_arg, node) == 0)
			return (free(new_arg), 0);
		free(new_arg);
	}
	return (1);
}
