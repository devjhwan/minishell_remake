/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:28:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/18 21:49:02 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmds.h"
#include "token.h"

int	set_redirections(t_cmds *cmds, t_token *tokens);
int	set_arguments(t_cmds *cmds, t_token *tokens);

t_cmds	*get_new_cmd(t_token_type type)
{
	t_cmds	*cmds;

	cmds = (t_cmds *)malloc(sizeof(t_cmds));
	if (cmds == NULL)
		return (NULL);
	ft_memset(cmds, 0, sizeof(t_cmds));
	if (type == PIPE)
		cmds->t = PIPE_T;
	if (type == AND)
		cmds->t = AND_T;
	if (type == OR)
		cmds->t = OR_T;
	return (cmds);
}

t_cmds	*parser(t_token *tokens)
{
	t_cmds	*cmds;
	t_cmds	*tmp;

	cmds = get_new_cmd(PIPE);
	if (cmds == NULL)
		return (NULL);
	tmp = cmds;
	while (tokens != NULL)
	{
		if (set_redirections(tmp, tokens) == 0 || \
			set_arguments(tmp, tokens) == 0)
			return (free_cmds(cmds), NULL);
		while (tokens->next != NULL && tokens->t != PIPE && \
				tokens->t != AND && tokens->t != OR)
			tokens = tokens->next;
		if (tokens->t == PIPE || tokens->t == AND || tokens->t == OR)
		{
			tmp->next = get_new_cmd(tokens->t);
			if (tmp->next == NULL)
				return (NULL);
			tmp = tmp->next;
		}
		tokens = tokens->next;
	}
	return (cmds);
}
