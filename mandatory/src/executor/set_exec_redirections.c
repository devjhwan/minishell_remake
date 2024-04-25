/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_exec_redirections.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/26 00:14:25 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "libft.h"

int	_set_exec_rdin(t_redir *redirs, t_redir **rdin)
{
	t_redir	*tmp;
	t_redir	*tmp2;

	tmp = NULL;
	while (redirs != NULL)
	{
		if (redirs->t == IN || redirs->t == IN2)
			tmp = redirs;
		redirs = redirs->next;
	}
	if (tmp == NULL)
		return (1);
	tmp2 = (t_redir *)malloc(sizeof(t_redir));
	if (tmp2 == NULL)
		return (0);
	tmp2->t = tmp->t;
	tmp2->filename = ft_strdup(tmp->filename);
	if (tmp2->filename == NULL)
		return (free(tmp2), 0);
	tmp2->next = NULL;
	*rdin = tmp2;
	return (1);
}

int	_set_exec_rdout(t_redir *redirs, t_redir **rdout)
{
	t_redir	*tmp;
	t_redir	*tmp2;

	tmp = NULL;
	while (redirs != NULL)
	{
		if (redirs->t == OUT || redirs->t == OUT2)
			tmp = redirs;
		redirs = redirs->next;
	}
	if (tmp == NULL)
		return (1);
	tmp2 = (t_redir *)malloc(sizeof(t_redir));
	if (tmp2 == NULL)
		return (0);
	tmp2->t = tmp->t;
	tmp2->filename = ft_strdup(tmp->filename);
	if (tmp2->filename == NULL)
		return (free(tmp2), 0);
	tmp2->next = NULL;
	*rdout = tmp2;
	return (1);
}
