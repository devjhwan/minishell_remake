/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 21:54:14 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/28 16:25:21 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_tree.h"
#include "utils.h"

int		expand_singular_env(t_ptree *node);
char	*expand_dquote_env(char *arg);
char	*expand_homepath(t_ptree *node);

static char	*get_new_argument(t_ptree *node)
{
	char	*new_arg;

	if (ft_strchr(node->arg, '$') != NULL)
	{
		if (node->arg[0] == '\'')
			new_arg = remove_quote(node->arg);
		else if (node->arg[0] == '\"')
			new_arg = expand_dquote_env(node->arg);
		else
			new_arg = ft_strdup("");
	}
	else if (node->arg[0] == '\'' || node->arg[0] == '\"')
		new_arg = remove_quote(node->arg);
	else if (node->arg[0] == '~')
		new_arg = expand_homepath(node);
	else
		new_arg = ft_strdup(node->arg);
	return (new_arg);
}

int	expand_node(t_ptree *node)
{
	char	*new_arg;

	if (node->arg == NULL)
		return (0);
	if (node->arg[0] == '$')
		return (expand_singular_env(node));
	new_arg = get_new_argument(node);
	free(node->arg);
	node->arg = new_arg;
	return (1);
}
