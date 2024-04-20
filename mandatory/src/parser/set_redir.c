/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/20 15:11:40 by junghwle         ###   ########.fr       */
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

static int	check_ambiguous_redirect(char *arg, char **envp)
{
	char	**split;
	int		i;

	if (arg[0] == '\'' || arg[0] == '\"')
		return (1);
	if (ft_strchr(arg, ' ') != NULL)
		(*ft_strchr(arg, ' ')) = '\0';
	split = ft_split(arg, "$");
	if (split == NULL)
		return (0);
	i = 0;
	if (split[0] == NULL)
		return (free_split(split), 1);
	while (split[i] != NULL)
	{
		if (check_env(split[i], envp))
			return (free_split(split), 1);
		i++;
	}
	return (free_split(split), 0);
}

static char	*get_file_name(t_rdtype t, char **line, char **envp)
{
	int		len;
	char	*tmp;
	char	*filename;

	tmp = ft_strdup(*line);
	if (tmp == NULL)
		return (NULL);
	if (t != IN2 && !check_ambiguous_redirect(tmp, envp))
		return (print_error(AMBIGUOUS_REDIRECT, tmp, NULL), NULL);
	free(tmp);
	len = count_arg_length(*line);
	filename = ft_substr(*line, 0, len);
	*line += len;
	return (filename);
}

static int	expand_env_redir(t_rdtype t, char **filename, char **envp)
{
	char	*new_filename;

	if (ft_strchr(*filename, '$') == NULL)
		return (1);
	if (t == IN2)
		new_filename = remove_quote(*filename);
	new_filename = expand_env(*filename, envp);
	if (new_filename == NULL)
		return (0);
	free(*filename);
	*filename = new_filename;
	return (1);
}

int	set_redir(char **line, t_cmd *cmd, char **envp)
{
	t_redir		*new_rd;
	t_rdtype	t;
	char		*filename;

	t = get_redir_type(*line);
	if ((*line)[0] == (*line)[1])
		(*line)++;
	(*line)++;
	while (**line == ' ')
		(*line)++;
	if (!is_arg(*line))
		return (print_redir_error(*line), 0);
	filename = get_file_name(t, line, envp);
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
