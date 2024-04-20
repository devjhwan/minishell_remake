/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/20 04:17:03 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include "utils.h"

void	print_redir_error(char *line);

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

static int	expand_env_redir(t_rdtype t, char **filename, char **envp)
{
	char	*new_filename;

	if (ft_strchr(*filename, '$') != NULL)
	{
		if (t == IN2)
		{
			new_filename = remove_quote(*filename);
			if (new_filename == NULL)
				return (0);
		}
		else
		{
			new_filename = expand_env(*filename, envp);
			if (new_filename == NULL)
				return (0);
		}
		free(*filename);
		*filename = new_filename;
	}
	return (1);
}

int	set_redir(char **line, t_cmd *cmd, char **envp)
{
	t_redir		*new_rd;
	t_rdtype	t;
	int			len;
	char		*filename;

	t = get_redir_type(*line);
	if ((*line)[0] == (*line)[1])
		(*line)++;
	(*line)++;
	while (**line == ' ')
		(*line)++;
	if (!is_arg(*line))
		return (print_redir_error(*line), 0);
	len = count_arg_length(*line);
	filename = ft_substr(*line, 0, len);
	*line += len;
	if (filename == NULL)
		return (0);
	if (!expand_env_redir(t, &filename, envp))
		return (free(filename), 0);
	new_rd = new_redir(t, filename);
	if (new_rd == NULL)
		return (free(filename), 0);
	append_redir(cmd, new_rd);
	return (1);
}
