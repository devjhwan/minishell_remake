/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tree_to_cmds.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:39:38 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/26 00:17:01 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "parser_tree.h"

int	_parse_to_cmd_arguments(t_cmd *cmd, t_ptree *node);
int	_parse_to_cmd_redirections(t_cmd *cmd, t_ptree *node);

t_cmd	*_parse_tree_to_cmds(t_ptree *tree)
{
	t_cmd	*cmds;

	if (tree->t != COMMAND)
		return (NULL);
	cmds = create_new_cmd(get_cmd_type(tree->arg));
	if (cmds == NULL)
		return (NULL);
	if (_parse_to_cmd_arguments(cmds, tree->left) == 0)
		return (free_cmds(&cmds), NULL);
	if (_parse_to_cmd_redirections(cmds, tree->left) == 0)
		return (free_cmds(&cmds), NULL);
	if (tree->right != NULL)
	{
		cmds->next = _parse_tree_to_cmds(tree->right);
		if (cmds->next == NULL)
			return (free_cmds(&cmds), NULL);
	}
	return (cmds);
}
