/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/20 02:05:04 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

t_cmd	*parser(char *line)
{
    t_cmd		*cmds;
	t_cmd		*tmp;
	int			i;
	t_arglist	*args;

	cmds = new_cmd(P);
	if (cmds == NULL)
		return (NULL);
	tmp = cmds;
	args = NULL;
	while (*line != '\0')
	{
		i = 0;
		while (line[i] == ' ')
			i++;
		line = &line[i];
		if (is_redir(line))
		{
			if (!set_redir(&line, tmp))
				return (free_cmds(&cmds), free_arguments(&args), NULL);
		}
		else if (is_pipe(line))
		{
			tmp->args = set_argument(args);
			free_arguments(&args);
			tmp->next = new_cmd(get_cmd_type(&line));
			if (tmp->next == NULL)
				return (free_cmds(&cmds), free_arguments(&args), NULL);
			tmp = tmp->next;
		}
		else
		{
			if (!add_argument(&args, &line))
				return (free_cmds(&cmds), free_arguments(&args), NULL);
		}
	}
	tmp->args = set_argument(args);
	free_arguments(&args);
	return (cmds);
}
