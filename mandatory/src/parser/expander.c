/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 20:50:36 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/21 22:08:53 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_tree.h"
#include "utils.h"
#include "libft.h"

int	expand_node(t_ptree *node, char **envp);

int	is_ambiguous(t_ptree *node, char **envp)
{
	if (node == NULL || node->t != ARGUMENT || node->arg == NULL)
		return (1);
	if (node->arg[0] != '$')
		return (0);
	else if (check_environment(node->arg + 1, envp) == 1)
		return (0);
	else
		return (is_ambiguous(node->right, envp));
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
}

int	expander(t_ptree *tree, char **envp)
{
	if (tree != NULL)
	{
		if (tree->t == ARGUMENT && expand_node(tree, envp) == 0)
			return (0);
		else if (tree->t == REDIRECTION && is_ambiguous(tree->left, envp))
			return (print_ambiguous_redirection(tree->left), 0);
		if (tree->left != NULL && expander(tree->left, envp) == 0)
			return (0);
		if (tree->right != NULL && expander(tree->right, envp) == 0)
			return (0);
	}
	return (1);
}