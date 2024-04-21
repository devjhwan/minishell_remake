/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:05:02 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/21 20:38:29 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_tree.h"
#include <unistd.h>
t_ptree	*parse_command(t_ptoken *tokens)
{
	t_ptree	*command;

	command = create_new_node(COMMAND, tokens->arg);
	if (command == NULL)
		return (NULL);
	tokens = skip_space_tokens(tokens->next);
	command->left = parse_content(&tokens);
	if (command->left == NULL)
		return (free_tree(command), NULL);
	if (tokens != NULL)
	{
		tokens = skip_space_tokens(tokens);
		command->right = parse_command(tokens);
		if (command->right == NULL)
			return (free_tree(command), NULL);
	}
	return (command);
}
