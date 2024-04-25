/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 21:54:14 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/26 00:16:40 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_tree.h"
#include "utils.h"

char	*_expand_singular_env(char *arg, t_shell *shell);
char	*_expand_dquote_env(char *arg, t_shell *shell);

int	_expand_node(t_ptree *node, t_shell *shell)
{
	char	*new_arg;

	if (node->arg != NULL && ft_strchr(node->arg, '$') != NULL)
	{
		if (node->arg[0] == '$')
			new_arg = _expand_singular_env(node->arg, shell);
		else if (node->arg[0] == '\'')
			new_arg = remove_quote(node->arg);
		else if (node->arg[0] == '\"')
			new_arg = _expand_dquote_env(node->arg, shell);
		else
			new_arg = ft_strdup(node->arg);
	}
	else if (node->arg[0] == '\'' || node->arg[0] == '\"')
		new_arg = remove_quote(node->arg);
	else
		return (1);
	if (new_arg == NULL)
		return (0);
	free(node->arg);
	node->arg = new_arg;
	return (1);
}
