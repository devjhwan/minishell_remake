/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_environment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 21:51:23 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/27 14:15:21 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "libft.h"
#include "utils.h"
#include <stdio.h>

char	*search_envvar_from_envp(char *arg, int arg_len, char **envp)
{
	int		i;
	char	*env_var;

	i = 0;
	env_var = NULL;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], arg, arg_len) == 0 && \
			envp[i][arg_len] == '=')
		{
			env_var = ft_substr(envp[i], arg_len + 1, ft_strlen(envp[i]));
			break ;
		}
		i++;
	}
	if (envp[i] == NULL)
		return (ft_strdup(""));
	return (env_var);
}

char	*search_environment(char *arg)
{
	int		arg_len;

	arg_len = ft_strlen(arg);
	if (arg_len == 0)
		return (ft_strdup("$"));
	if (arg[0] == '?')
		return (ft_itoa(get_shell_struct()->exit_code));
	if (arg[0] == '~')
		return (get_homepath());
	return (search_envvar_from_envp(arg, arg_len, get_shell_struct()->env));
}
