/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_singular_env.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 21:52:18 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/27 15:50:12 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "utils.h"
#include "parser_tree.h"
#include <stdlib.h>

static void	transport_adjacent_arguments(t_ptree *node)
{
	t_ptree	*tmp;

	tmp = node->right;
	node->right = NULL;
	while (node->t != CONTENT)
		node = node->parent;
	while (node->right != NULL)
		node = node->right;
	node = node->left;
	if (node != NULL)
	{
		while (node->right != NULL)
			node = node->right;
		node->right = tmp;
	}
}

static int	append_new_node(char *arg, t_ptree *content)
{
	t_ptree	*new_content;

	new_content = create_new_node(CONTENT, NULL);
	if (new_content == NULL)
		return (0);
	new_content->left = create_new_node(ARGUMENT, arg);
	if (new_content->left == NULL)
		return (free_tree(new_content), 0);
	content->right = new_content;
	return (1);
}

static int	expand_argument_node(char *new_arg, t_ptree *node)
{
	char	**split;
	int		i;

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
	i = 1;
	while (node->t != CONTENT)
		node = node->parent;
	while (split[i] != NULL)
	{
		if (append_new_node(split[i], node) == 0)
			return (free_strarray(split), 0);
		i++;
		node = node->right;
	}
	return (free_strarray(split), 1);
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
		if (new_arg == NULL)
			return (0);
		if (ft_strchr(new_arg, ' ') == NULL)
			return (free(node->arg), node->arg = new_arg, 1);
		if (expand_argument_node(new_arg, node) == 0)
			return (0);
		free(new_arg);
		transport_adjacent_arguments(node);
	}
	return (1);
}
