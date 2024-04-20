/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/20 04:00:06 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include "utils.h"

static int	is_pipe_syntax_error(t_cmd *tmp, char *line)
{
	if ((tmp->args == NULL || tmp->args[0] == NULL) && tmp->redirs == NULL)
		return (print_error(UNEXPECTED_TOKEN, "|", NULL), 1);
	if (is_arg(line))
		return (1);
	line++;
	while (*line == ' ')
		line++;
	if (*line == '\0')
		return (print_error(UNEXPECTED_TOKEN, "newline", NULL), 1);
	if (is_pipe(line))
		return (print_error(UNEXPECTED_TOKEN, "|", NULL), 1);
	return (0);
}

static int	parser_logic(char **line, t_cmd **tmp, t_arglist **args, \
							char **envp)
{
	if (is_redir(*line))
	{
		if (!set_redir(line, *tmp, envp))
			return (0);
	}
	else if (is_pipe(*line))
	{
		(*tmp)->args = set_argument(*args);
		free_arguments(args);
		if ((*tmp)->args == NULL)
			return (0);
		if (is_pipe_syntax_error(*tmp, *line))
			return (0);
		(*tmp)->next = new_cmd(get_cmd_type(line));
		if ((*tmp)->next == NULL)
			return (0);
		*tmp = (*tmp)->next;
		return (1);
	}
	else
	{
		if (!add_argument(args, line, envp))
			return (0);
	}
	return (1);
}

t_cmd	*parser(char *line, char **envp)
{
    t_cmd		*cmds;
	t_cmd		*tmp;
	t_arglist	*args;

	cmds = new_cmd(P);
	if (cmds == NULL)
		return (NULL);
	tmp = cmds;
	args = NULL;
	while (*line != '\0')
	{
		while (*line == ' ')
			line++;
		if (!parser_logic(&line, &tmp, &args, envp))
			return (free_cmds(&cmds), free_arguments(&args), NULL);
	}
	tmp->args = set_argument(args);
	free_arguments(&args);
	return (cmds);
}
