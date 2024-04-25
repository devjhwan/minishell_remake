/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_new_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:45:41 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/25 13:05:36 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_tree.h"
#include "libft.h"

t_ptree	*create_new_node(t_nodetype	t, char *arg)
{
	t_ptree	*new_node;

	new_node = (t_ptree *)malloc(sizeof(t_ptree));
	if (new_node == NULL)
		return (NULL);
	new_node->t = t;
	if (arg == NULL)
		new_node->arg = NULL;
	else
	{
		new_node->arg = ft_strdup(arg);
		if (new_node->arg == NULL)
			return (free(new_node), NULL);
	}
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}
