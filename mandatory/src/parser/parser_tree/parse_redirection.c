/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 20:08:35 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/21 20:44:23 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_tree.h"

t_ptree	*parse_redirection(t_ptoken **tokens)
{
	t_ptree	*redirection;

	redirection = create_new_node(REDIRECTION, (*tokens)->arg);
	if (redirection == NULL)
		return (NULL);
	*tokens = skip_space_tokens((*tokens)->next);
	redirection->left = parse_argument(tokens);
	if (redirection->left == NULL)
		return (free_tree(redirection), NULL);
	return (redirection);
}