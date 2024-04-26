/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substr_argument1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 17:19:37 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/26 16:05:01 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*_substr_quote(char **line);
char	*_substr_dquote(char **line);

char	*_substr_pipe(char **line)
{
	char	*str;

	str = ft_substr(*line, 0, 1);
	*line += 1;
	return (str);
}

char	*_substr_redir(char **line)
{
	char	*str;

	str = NULL;
	if (ft_strncmp(*line, "<<", 2) == 0)
	{
		str = ft_substr(*line, 0, 2);
		*line += 2;
	}
	else if (ft_strncmp(*line, ">>", 2) == 0)
	{
		str = ft_substr(*line, 0, 2);
		*line += 2;
	}
	else if (ft_strncmp(*line, "<", 1) == 0)
	{
		str = ft_substr(*line, 0, 1);
		*line += 1;
	}
	else if (ft_strncmp(*line, ">", 1) == 0)
	{
		str = ft_substr(*line, 0, 1);
		*line += 1;
	}
	return (str);
}

char	*_substr_env(char **line)
{
	int		len;
	char	*str;
	char	*tmp;
	char	*tmp2;

	len = 1;
	while ((*line)[len] != '\0' && \
			ft_strchr("|$ <>\'\"/", (*line)[len]) == NULL)
		len++;
	str = ft_substr(*line, 0, len);
	*line += len;
	if (len == 1 && (**line == '\'' || **line == '\"'))
	{
		if (**line == '\'')
			tmp = _substr_quote(line);
		else
			tmp = _substr_dquote(line);
		if (tmp == NULL)
			return (NULL);
		tmp2 = ft_strjoin(2, str, tmp);
		free(str);
		free(tmp);
		str = tmp2;
	}
	return (str);
}
