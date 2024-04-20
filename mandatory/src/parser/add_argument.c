/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_argument.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/20 13:27:35 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

static t_arglist	*new_argument(char *arg)
{
	t_arglist	*new_arg;

	new_arg = (t_arglist *)malloc(sizeof(t_arglist));
	if (new_arg == NULL)
		return (NULL);
	new_arg->arg = arg;
	new_arg->next = NULL;
	return (new_arg);
}

int	add_argument(t_arglist **args, char **line, char **envp)
{
	int			len;
	char		*new_line;
	t_arglist	*tmp;

	(void)envp;
	len = count_arg_length(*line);
	new_line = ft_substr(*line, 0, len);
	if (new_line == NULL)
		return (0);
	*line += len;
	if (*args == NULL)
	{
		*args = new_argument(new_line);
		if (*args == NULL)
			return (free(new_line), 0);
	}
	else
	{
		tmp = *args;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_argument(new_line);
		if (*args == NULL)
			return (free(new_line), 0);
	}
	return (1);
}
