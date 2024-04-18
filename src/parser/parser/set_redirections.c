/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redirections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:21:52 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/18 21:49:14 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmds.h"
#include "token.h"

static t_redirs	*new_redirection(char *redir_type)
{
	t_redirs	*rd;

	rd = (t_redirs *)malloc(sizeof(t_redirs));
	if (rd == NULL)
		return (NULL);
	if (ft_strncmp(redir_type, "<", 2) == 0)
		rd->t = IN;
	else if (ft_strncmp(redir_type, ">", 2) == 0)
		rd->t = OUT;
	else if (ft_strncmp(redir_type, "<<", 3) == 0)
		rd->t = IN2;
	else if (ft_strncmp(redir_type, ">>", 3) == 0)
		rd->t = OUT2;
	rd->file_name = NULL;
	rd->next = NULL;
	return (rd);
}

static int	add_new_redirection(t_redirs **rd, t_cmds *cmds, t_token *tokens)
{
	if (*rd == NULL)
	{
		*rd = new_redirection(tokens->arg);
		if (*rd == NULL)
			return (0);
		cmds->rd_arr = *rd;
	}
	else
	{
		(*rd)->next = new_redirection(tokens->arg);
		if ((*rd)->next == NULL)
			return (0);
		*rd = (*rd)->next;
	}
	return (1);
}

static int	find_rd_argument(t_redirs *rd, t_token *tokens)
{
	t_token	*deltoken;

	while (tokens != NULL && tokens->next->t != ARG)
		tokens = tokens->next;
	rd->file_name = ft_strdup(tokens->next->arg);
	if (rd->file_name == NULL)
		return (0);
	deltoken = tokens->next;
	tokens->next = deltoken->next;
	delete_token(deltoken);
	return (1);
}

int	set_redirections(t_cmds *cmds, t_token *tokens)
{
	t_redirs	*rd;

	rd = NULL;
	while (tokens != NULL && tokens->t != PIPE && \
			tokens->t != AND && tokens->t != OR)
	{
		if (tokens->t == RD)
		{
			if (add_new_redirection(&rd, cmds, tokens) == 0)
				return (0);
			if (find_rd_argument(rd, tokens) == 0)
				return (0);
		}
		tokens = tokens->next;
	}
	return (1);
}
