/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_arguments.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:47:46 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/18 21:49:08 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmds.h"
#include "token.h"

int	count_args(t_token *tokens)
{
	int	count;

	count = 0;
	while (tokens != NULL && tokens->t != PIPE && \
			tokens->t != AND && tokens->t != OR)
	{
		if (tokens->t == ARG)
			count++;
		tokens = tokens->next;
	}
	return (count);
}

int	set_arguments(t_cmds *cmds, t_token *tokens)
{
	int	arg_len;
	int	idx;

	arg_len = count_args(tokens);
	cmds->args = (char **)malloc(sizeof(char *) * (arg_len + 1));
	if (cmds->args == NULL)
		return (0);
	idx = 0;
	while (tokens != NULL && tokens->t != PIPE && \
			tokens->t != AND && tokens->t != OR)
	{
		if (tokens->t == ARG)
		{
			cmds->args[idx] = ft_strdup(tokens->arg);
			if (cmds->args[idx] == NULL)
				return (0);
			idx++;
		}
		tokens = tokens->next;
	}
	cmds->args[idx] = NULL;
	return (1);
}
