/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dquote_env.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 21:53:07 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/26 00:15:35 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "libft.h"
#include "utils.h"

static char	*replace_env(char *arg, int i, t_shell *shell)
{
	int		env_len;
	char	*tmp1;
	char	*tmp2;
	char	*tmp3;

	env_len = 1;
	while (arg[i + env_len] != '\0' && \
			ft_strchr(" $\'\"", arg[i + env_len]) == NULL)
		env_len++;
	tmp1 = ft_substr(arg, 0, i);
	tmp3 = ft_substr(arg, i + env_len, ft_strlen(arg));
	arg[i + env_len] = '\0';
	tmp2 = search_environment(&arg[i + 1], shell);
	if (tmp1 == NULL || tmp2 == NULL || tmp3 == NULL)
		return (free(tmp1), free(tmp2), free(tmp3), NULL);
	arg = ft_strjoin(3, tmp1, tmp2, tmp3);
	return (free(tmp1), free(tmp2), free(tmp3), arg);
}

char	*_expand_dquote_env(char *arg, t_shell *shell)
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
			new_arg = replace_env(arg, i, shell);
			free(arg);
			if (new_arg == NULL)
				return (NULL);
			arg = new_arg;
		}
	}
	return (new_arg);
}
