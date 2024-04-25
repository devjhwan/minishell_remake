/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_to_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:39:38 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/25 13:04:46 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "parser_tree.h"

static int	count_arguments(t_ptree *node)
{
	int	count;

	count = 0;
	if (node->left->t == ARGUMENT)
		count++;
	if (node->right != NULL)
		count += count_arguments(node->right);
	return (count);
}

static int	append_argument(char **args, t_ptree *node)
{
	if (node->left->t == ARGUMENT)
	{
		*args = join_tree_arguments(node->left);
		if (*args == NULL)
			return (0);
		if (node->right != NULL && \
			append_argument(&(args[1]), node->right) == 0)
			return (0);
	}
	else if (node->right != NULL && append_argument(args, node->right) == 0)
		return (0);
	return (1);
}

static int	append_redirection(t_redir **redir, t_ptree *node)
{
	if (node->left->t == REDIRECTION)
	{
		*redir = (t_redir *)malloc(sizeof(t_redir));
		if (*redir == NULL)
			return (0);
		(*redir)->t = get_redir_type(node->left->arg);
		(*redir)->filename = join_tree_arguments(node->left->left);
		if ((*redir)->filename == NULL)
			return (0);
		(*redir)->next = NULL;
		if (node->right != NULL && \
			append_redirection(&((*redir)->next), node->right) == 0)
			return (0);
	}
	else if (node->right != NULL && append_redirection(redir, node->right) == 0)
		return (0);
	return (1);
}

int	parse_to_cmd_arguments(t_cmd *cmd, t_ptree *node)
{
	int	count;

	count = count_arguments(node);
	cmd->args = (char **)ft_calloc((count + 1), sizeof(char *));
	if (cmd->args == NULL)
		return (0);
	if (append_argument(cmd->args, node) == 0)
		return (0);
	return (1);
}

int	parse_to_cmd_redirections(t_cmd *cmd, t_ptree *node)
{
	if (append_redirection(&cmd->redirs, node) == 0)
		return (0);
	return (1);
}
