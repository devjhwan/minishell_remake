/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 20:08:35 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/25 13:05:49 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_tree.h"

t_ptree	*parse_argument(t_ptoken **tokens)
{
	t_ptree	*argument;

	argument = create_new_node(ARGUMENT, (*tokens)->arg);
	if (argument == NULL)
		return (NULL);
	*tokens = (*tokens)->next;
	if (*tokens != NULL && ((*tokens)->t == ARG || (*tokens)->t == ENV || \
							(*tokens)->t == SQ || (*tokens)->t == DQ))
	{
		argument->right = parse_argument(tokens);
		if (argument->right == NULL)
			return (free_tree(argument), NULL);
	}
	return (argument);
}
