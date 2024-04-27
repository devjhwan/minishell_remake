/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substr_argument2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 17:20:27 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/27 15:40:21 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*substr_quote(char **line)
{
	int		len;
	char	*str;

	len = 1;
	while ((*line)[len] != '\0' && \
			ft_strchr("|\'", (*line)[len]) == NULL)
		len++;
	if ((*line)[len] == '\'')
		str = ft_substr(*line, 0, ++len);
	else
	{
		str = (char *)malloc(sizeof(char) * (len + 2));
		if (str == NULL)
			return (NULL);
		ft_strlcpy(str, *line, len + 1);
		str[len] = '\'';
		str[len + 1] = '\0';
	}
	*line += len;
	return (str);
}

char	*substr_dquote(char **line)
{
	int		len;
	char	*str;

	len = 1;
	while ((*line)[len] != '\0' && \
			ft_strchr("|\"", (*line)[len]) == NULL)
		len++;
	if ((*line)[len] == '\"')
		str = ft_substr(*line, 0, ++len);
	else
	{
		str = (char *)malloc(sizeof(char) * (len + 2));
		if (str == NULL)
			return (NULL);
		ft_strlcpy(str, *line, len + 1);
		str[len] = '\"';
		str[len + 1] = '\0';
	}
	*line += len;
	return (str);
}

char	*substr_space(char **line)
{
	int		len;
	char	*str;

	len = 0;
	while ((*line)[len] == ' ')
		len++;
	str = ft_substr(*line, 0, len);
	*line += len;
	return (str);
}

char	*substr_argument(char **line)
{
	int		len;
	char	*str;

	len = 0;
	while ((*line)[len] != '\0' && \
			ft_strchr("|$<> \'\"", (*line)[len]) == NULL)
		len++;
	str = ft_substr(*line, 0, len);
	*line += len;
	return (str);
}
