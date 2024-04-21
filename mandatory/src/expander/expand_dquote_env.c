/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dquote_env.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 21:53:07 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/21 21:53:32 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

static char	*replace_env(char *arg, int i, char **envp)
{
	int		env_len;
	char	*tmp1;
	char	*tmp2;
	char	*tmp3;

	env_len = 0;
	while (arg[env_len] != '\0' && ft_strchr(" \'\"", arg[env_len]) == NULL)
		env_len++;
	tmp1 = ft_substr(arg, 0, i);
	tmp2 = search_environment(&arg[i + 1], envp);
	tmp3 = ft_substr(arg, i + env_len, ft_strlen(arg));
	if (tmp1 == NULL || tmp2 == NULL || tmp3 == NULL)
		return (free(tmp1), free(tmp2), free(tmp3), NULL);
	arg = ft_strjoin(3, tmp1, tmp2, tmp3);
	return (free(tmp1), free(tmp2), free(tmp3), arg);
}

char	*expand_dquote_env(char *arg, char **envp)
{
	int		i;
	char	*new_arg;

	arg = remove_quote(arg);
	if (arg == NULL)
		return (NULL);
	i = 0;
	while (arg[i] != '\0')
	{
		while (arg[i] != '\0' && arg[i] != '$')
			i++;
		if (arg[i] == '$')
		{
			new_arg = replace_env(arg, i, envp);
			if (new_arg == NULL)
				return (free(arg), NULL);
			arg = new_arg;
		}
	}
	return (new_arg);
}