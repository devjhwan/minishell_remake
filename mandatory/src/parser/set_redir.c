/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/20 03:25:33 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include "utils.h"

static t_rdtype	get_redir_type(char *line)
{
	if (ft_strncmp(line, "<<", 2) == 0)
		return (IN2);
	else if (ft_strncmp(line, ">>", 2) == 0)
		return (OUT2);
	else if (ft_strncmp(line, "<", 1) == 0)
		return (IN);
	else if (ft_strncmp(line, ">", 1) == 0)
		return (OUT);
	else
		return (RD_ERR);
}

static void	append_redir(t_cmd *cmd, t_redir *new_rd)
{
	t_redir	*tmp;

	if (cmd->redirs == NULL)
		cmd->redirs = new_rd;
	else
	{
		tmp = cmd->redirs;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_rd;
	}
}

static char	*get_err_argument(char *line)
{
	if (line[0] == '<')
	{
		if (line[1] == '<')
			line[2] = '\0';
		else
			line[1] = '\0';
	}
	else if (line[0] == '>')
	{
		if (line[1] == '>')
			line[2] = '\0';
		else
			line[1] = '\0';
	}
	else if (line[0] == '|')
		line[1] = '\0';
	return (line);
}

static void	print_redir_error(char *line)
{
	char		*arg;
	
	while (*line == ' ')
		line++;
	if (*line == '\0')
		print_error(UNEXPECTED_TOKEN, "newline", NULL);
	else
	{
		arg = get_err_argument(line);
		print_error(UNEXPECTED_TOKEN, arg, NULL);
	}
}

int	set_redir(char **line, t_cmd *cmd)
{
	t_redir	*new_rd;
	int		len;
	char	*filename;

	new_rd = (t_redir *)malloc(sizeof(t_redir));
	if (new_rd == NULL)
		return (0);
	new_rd->t = get_redir_type(*line);
	if ((*line)[0] == (*line)[1])
		(*line)++;
	(*line)++;
	while (**line == ' ')
		(*line)++;
	if (!is_arg(*line))
		return (print_redir_error(*line), free(new_rd), 0);
	len = count_arg_length(*line);
	filename = ft_substr(*line, 0, len);
	*line += len;
	if (filename == NULL)
		return (free(new_rd), 0);
	new_rd->filename = filename;
	new_rd->next = NULL;
	append_redir(cmd, new_rd);
	return (1);
}
