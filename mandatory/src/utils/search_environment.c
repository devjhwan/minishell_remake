/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_environment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 21:51:23 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/26 00:09:09 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "libft.h"

char	*search_environment(char *arg, t_shell *shell)
{
	int	i;
	int	arg_len;

	i = 0;
	arg_len = ft_strlen(arg);
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
