/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 20:50:36 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/26 21:14:42 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_tree.h"
#include "utils.h"
#include "libft.h"

int	_expand_node(t_ptree *node);

int	is_ambiguous(t_ptree *node)
{
	if (node == NULL || node->t != ARGUMENT || node->arg == NULL)
		return (1);
	if (node->arg[0] != '$')
		return (0);
	else if (node->arg[1] == '?')
		return (0);
	else if (check_environment(node->arg + 1) == 1)
		return (0);
	else
		return (is_ambiguous(node->right));
}

char	*join_arguments(t_ptree *node)
{
	char	*tmp;
	char	*str;

	if (node->right == NULL)
		return (ft_strdup(node->arg));
	else
	{
		tmp = join_arguments(node->right);
		if (tmp == NULL)
			return (NULL);
		str = ft_strjoin(2, node->arg, tmp);
		return (free(tmp), str);
	}
}

void	print_ambiguous_redirection(t_ptree *node)
{
	char	*str;

	str = join_arguments(node);
	if (str != NULL)
		print_error(AMBIGUOUS_REDIRECT, str, NULL);
	free(str);
}

int	expander(t_ptree *tree)
{
	if (tree != NULL)
	{
		if (tree->t == ARGUMENT && _expand_node(tree) == 0)
			return (0);
		else if (tree->t == REDIRECTION && is_ambiguous(tree->left))
			return (print_ambiguous_redirection(tree->left), 0);
		if (tree->left != NULL && expander(tree->left) == 0)
			return (0);
		if (tree->right != NULL && expander(tree->right) == 0)
			return (0);
	}
	return (1);
}
