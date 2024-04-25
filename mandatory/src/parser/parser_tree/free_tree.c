/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:50:43 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/25 13:05:43 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_tree.h"

void	free_tree(t_ptree *tree)
{
	if (tree != NULL)
	{
		if (tree->left != NULL)
			free_tree(tree->left);
		tree->left = NULL;
		if (tree->right != NULL)
			free_tree(tree->right);
		tree->right = NULL;
		free(tree->arg);
		tree->arg = NULL;
		free(tree);
	}
}
