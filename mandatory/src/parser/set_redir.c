/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/19 17:32:55 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

static t_rdtype	get_redir_type(char *line)
{
	if (ft_strncmp(line, "<", 2) == 0)
		return (IN);
	else if (ft_strncmp(line, ">", 2) == 0)
		return (OUT);
	else if (ft_strncmp(line, "<<", 3) == 0)
		return (IN2);
	else if (ft_strncmp(line, ">>", 3) == 0)
		return (OUT2);
	else
		return (RD_ERR);
}

int	set_redir(char **line, t_cmd *cmd)
{
	t_redir	*new_rd;
	int		len;
	char	*filename;
	t_redir *tmp;

	new_rd = (t_redir *)malloc(sizeof(t_redir));
	if (new_rd == NULL)
		return (0);
	new_rd->t = get_redir_type(*line);
	while (**line == '<' || **line == '>' || **line == ' ')
		(*line)++;
	//TODO check if it is argument
	len = count_arg_length(*line);
	filename = ft_substr(*line, 0, len);
	*line += len;
	if (filename == NULL)
		return (free(new_rd), 0);
	new_rd->filename = filename;
	new_rd->next = NULL;
	tmp = cmd->redirs;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new_rd;
	return (1);
}
