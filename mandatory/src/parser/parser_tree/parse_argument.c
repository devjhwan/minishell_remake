/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 20:08:35 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/27 17:03:55 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_tree.h"
#include "utils.h"

static int	check_split_env_quote(t_ptoken *tokens)
{
	char	*env_arg;
	char	*env_arg2;
	int		res;

	if (tokens != NULL && tokens->prev != NULL && tokens->prev->t == ENV)
	{
		if (tokens->t == SQ || tokens->t == DQ)
		{
			env_arg = search_environment(tokens->prev->arg + 1);
			res = env_arg != NULL && env_arg[0] != '\0' && \
					env_arg[ft_strlen(env_arg) - 1] == ' ';
			return (free(env_arg), res);
		}
		else if (tokens->t == ENV)
		{
			env_arg = search_environment(tokens->prev->arg + 1);
			env_arg2 = search_environment(tokens->arg + 1);
			res = env_arg != NULL && env_arg2 != NULL && \
					env_arg[0] != '\0' && env_arg2[0] != '\0' && \
					env_arg[ft_strlen(env_arg) - 1] == ' ';
			return (free(env_arg), free(env_arg2), res);
		}
	}
	return (0);
}

t_ptree	*parse_argument(t_ptoken **tokens)
{
	t_ptree	*argument;

	argument = create_new_node(ARGUMENT, (*tokens)->arg);
	if (argument == NULL)
		return (NULL);
	*tokens = (*tokens)->next;
	if (check_split_env_quote(*tokens))
		return (argument);
	if (*tokens != NULL && ((*tokens)->t == ARG || (*tokens)->t == ENV || \
							(*tokens)->t == SQ || (*tokens)->t == DQ))
	{
		argument->right = parse_argument(tokens);
		if (argument->right == NULL)
			return (free_tree(argument), NULL);
		argument->right->parent = argument;
	}
	return (argument);
}
