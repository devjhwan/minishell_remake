/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_tree_arguments.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:39:38 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/28 16:09:50 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_tree.h"

char	*join_tree_arguments(t_ptree *node)
{
	char	*tmp1;
	char	*tmp2;
	char	*str;

	tmp1 = node->arg;
	node->arg = NULL;
	if (node->right == NULL)
		return (tmp1);
	else
	{
		tmp2 = join_tree_arguments(node->right);
		if (tmp1 == NULL)
			return (tmp2);
		if (tmp2 == NULL)
			return (tmp1);
		str = ft_strjoin(2, tmp1, tmp2);
		return (free(tmp1), free(tmp2), str);
	}
}
