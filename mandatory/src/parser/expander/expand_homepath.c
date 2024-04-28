/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_homepath.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 21:48:16 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/28 16:36:15 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_tree.h"
#include "libft.h"
#include "utils.h"
char	*expand_homepath(t_ptree *node)
{
	char	*new_arg;
	char	*tmp;

	if (node->arg[1] == '/')
	{
		tmp = get_homepath();
		if (tmp == NULL)
			return (NULL);
		new_arg = ft_strjoin(2, tmp, node->arg + 1);
	}
	else if (node->right != NULL && node->right->arg[0] == '$')
	{
		tmp = search_environment(node->right->arg + 1);
		if (tmp == NULL || tmp[0] != '/')
			new_arg = ft_strdup(node->arg);
		else
			new_arg = get_homepath();
	}
	else if (node->arg[1] == '\0')
		return (get_homepath());
	else
		new_arg = ft_strdup(node->arg);
	return (new_arg);
}
