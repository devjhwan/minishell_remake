/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:39:38 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/22 00:54:19 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "parser_token.h"
#include "parser_tree.h"

int	count_arguments(t_ptree *node)
{
	int	count;

	count = 0;
	if (node->left->t == ARGUMENT)
		count++;
	if (node->right != NULL)
		count += count_arguments(node->right);
	return (count);
}

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
		if (tmp2 == NULL)
			return (free(tmp1), NULL);
		str = ft_strjoin(2, tmp1, tmp2);
		return (free(tmp1), free(tmp2), str);
	}
}

int	append_argument(char **args, t_ptree *node)
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

t_rdtype	get_redir_type(char *arg)
{
	if (ft_strncmp(arg, "<", 2) == 0)
		return (IN);
	else if (ft_strncmp(arg, ">", 2) == 0)
		return (OUT);
	else if (ft_strncmp(arg, "<<", 3) == 0)
		return (IN2);
	else
		return (OUT2);
}

int	append_redirection(t_redir **redir, t_ptree *node)
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

int	parse_to_cmd_redirections(t_cmd *cmd, t_ptree *node)
{
	if (append_redirection(&cmd->redirs, node) == 0)
		return (0);
	return (1);
}

t_cmd	*parse_to_cmds(t_ptree *tree)
{
	t_cmd	*cmds;

	if (tree->t != COMMAND)
		return (NULL);
	cmds = create_new_cmd(get_cmd_type(tree->arg));
	if (cmds == NULL)
		return (NULL);
	if (parse_to_cmd_arguments(cmds, tree->left) == 0)
		return (free_cmds(&cmds), NULL);
	if (parse_to_cmd_redirections(cmds, tree->left) == 0)
		return (free_cmds(&cmds), NULL);
	if (tree->right != NULL)
	{
		cmds->next = parse_to_cmds(tree->right);
		if (cmds->next == NULL)
			return (free_cmds(&cmds), NULL);
	}
	return (cmds);
}

t_cmd	*parser(char *line, char **envp)
{
	t_ptoken	*tokens;
	t_ptree		*parser_tree;
	t_cmd		*cmds;

	tokens = lexer(line);
	if (tokens == NULL)
		return (NULL);
	if (syntax_analyzer(tokens) == 0)
		return (free_tokens(tokens), NULL);
	// print_tokens(tokens);
	parser_tree = create_parser_tree(tokens);
	free_tokens(tokens);
	if (parser_tree == NULL)
		return (NULL);
	// print_parser_tree(parser_tree);
	if (expander(parser_tree, envp) == 0)
		return (free_tree(parser_tree), NULL);
	//printf("\n");
	//print_parser_tree(parser_tree);
	cmds = parse_to_cmds(parser_tree);
	free_tree(parser_tree);
	print_command(cmds);
	return (cmds);
}
