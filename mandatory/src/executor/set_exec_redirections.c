/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_exec_redirections.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/29 12:55:10 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "libft.h"

int	set_exec_rdin(t_redir *redirs, t_executor *exec)
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
	exec->rdin = tmp2;
	return (1);
}

int	set_exec_rdout(t_redir *redirs, t_executor *exec)
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
	exec->rdout = tmp2;
	return (1);
}
