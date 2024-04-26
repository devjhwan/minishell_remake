/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_environment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 21:51:23 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/26 21:24:36 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "libft.h"
#include <stdio.h>

char	*search_environment(char *arg)
{
	int		i;
	int		arg_len;
	t_shell	*shell;

	i = 0;
	arg_len = ft_strlen(arg);
	shell = get_shell_struct();
	if (arg_len == 0)
		return (ft_strdup("$"));
	if (arg[0] == '?')
		return (ft_itoa(shell->exit_code));
	while (shell->env[i] != NULL)
	{
		if (ft_strncmp(shell->env[i], arg, arg_len) == 0 && \
			shell->env[i][arg_len] == '=')
			return (ft_substr(shell->env[i], arg_len + 1, \
								ft_strlen(shell->env[i])));
		i++;
	}
	return (ft_strdup(""));
}
