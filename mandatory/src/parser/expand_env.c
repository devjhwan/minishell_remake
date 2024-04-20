/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/20 14:51:27 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "utils.h"
#include "libft.h"
#include <stdlib.h>

int	env_varlen(char *arg)
{
	int	len;

	len = 1;
	while (arg[len] != '\0' && ft_strchr(" \'\"$", arg[len]) == NULL)
		len++;
	return (len);
}

char	*replace_env(char *arg, int i, int isquote, char **envp)
{
	char	*tmp1;
	char	*tmp2;
	char	*tmp3;

	if (arg[i + 1] == '\'' || arg[i + 1] == '\"')
	{
		if (isquote)
			return (ft_strdup(arg));
		return (remove_quote(&arg[i + 1]));
	}
	tmp1 = ft_substr(arg, 0, i);
	tmp3 = ft_substr(arg, i + env_varlen(&arg[i]), ft_strlen(arg));
	arg[i + env_varlen(&arg[i])] = '\0';
	tmp2 = search_env(&arg[i + 1], envp);
	if (tmp1 == NULL || tmp2 == NULL || tmp3 == NULL)
		return (free(tmp1), free(tmp2), free(tmp3), NULL);
	arg = ft_strjoin(3, tmp1, tmp2, tmp3);
	return (free(tmp1), free(tmp2), free(tmp3), arg);
}

char	*search_and_replace_env(char *arg, int isquote, char **envp)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_strdup(arg);
	if (tmp == NULL)
		return (NULL);
	while (tmp[i] != '\0')
	{
		if (tmp[i] == '$' && ft_strchr(" $", tmp[i + 1]) == NULL && \
			is_arg(&tmp[i + 1]))
		{
			arg = replace_env(tmp, i, isquote, envp);
			free(tmp);
			if (arg == NULL)
				return (NULL);
			tmp = arg;
		}
		else
			i++;
	}
	return (tmp);
}

char	*expand_env(char *arg, char **envp)
{
	int	i;

	if (ft_strchr(arg, '$') == NULL)
		return (NULL);
	if (arg[0] == '\'')
	{
		i = ft_strlen(arg);
		if (arg[i - 1] == '\'')
			arg[i - 1] = '\0';
		return (ft_strdup(arg + 1));
	}
	if (arg[0] == '\"')
	{
		i = ft_strlen(arg);
		if (arg[i - 1] == '\"')
			arg[i - 1] = '\0';
		return (search_and_replace_env(arg + 1, 1, envp));
	}
	return (search_and_replace_env(arg, 0, envp));
}
