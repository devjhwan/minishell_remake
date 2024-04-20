/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/20 05:08:32 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "utils.h"
#include "libft.h"
#include <stdlib.h>

/*
$
$USER
"$USER"
'$USER'
$USER$USER
"$USER$USER"
$USER hola $USER
"$USER hola $USER"
$ASDF
"$ASDF"
'$ASDF'
$ASDF$USER
"$USER$ASDF"
$ASDF hola $USER
"$USER hola $ASDF"
$"USER"
$'USER'
$"ASDF"
$'ASDF'
$?
*/

int	env_varlen(char *arg)
{
	int	len;

	len = 0;
	while (arg[len] != '\0' && ft_strchr(" \'\"", arg[len]) == NULL)
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
	if (!isquote)
		return (search_env(&arg[i + 1], envp));
	tmp1 = ft_substr(arg, 0, i);
	tmp2 = search_env(&arg[i + 1], envp);
	tmp3 = ft_substr(arg, i + env_varlen(&arg[i + 1]), ft_strlen(arg));
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
		if (tmp[i] == '$')
		{
			arg = replace_env(tmp, i, isquote, envp);
			free(tmp);
			if (arg == NULL)
				return (NULL);
			tmp = arg;
			if (tmp[i] == '\0')
				return (tmp);
		}
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
	else if (arg[1] == '\"')
	{
		i = ft_strlen(arg);
		if (arg[i - 1] == '\"')
			arg[i - 1] = '\0';
		return (search_and_replace_env(arg + 1, 1, envp));
	}
		return (search_and_replace_env(arg, 0, envp));
}