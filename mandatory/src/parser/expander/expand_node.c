/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 21:54:14 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/25 13:05:24 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_tree.h"
#include "utils.h"
#include <stdio.h>

char	*expand_singular_env(char *arg, char **envp);
char	*expand_dquote_env(char *arg, char **envp);

int	expand_node(t_ptree *node, char **envp)
{
	char	*new_arg;

	if (node->arg != NULL && ft_strchr(node->arg, '$') != NULL)
	{
		if (node->arg[0] == '$')
			new_arg = expand_singular_env(node->arg, envp);
		else if (node->arg[0] == '\'')
			new_arg = remove_quote(node->arg);
		else if (node->arg[0] == '\"')
			new_arg = expand_dquote_env(node->arg, envp);
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
