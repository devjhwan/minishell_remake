/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_environment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 21:51:23 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/21 21:51:30 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*search_environment(char *arg, char **envp)
{
	int	i;
	int	arg_len;

	i = 0;
	arg_len = ft_strlen(arg);
	if (arg_len == 0)
		return (ft_strdup("$"));
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], arg, arg_len) == 0 && envp[i][arg_len] == '=')
			return (ft_substr(envp[i], arg_len + 1, ft_strlen(envp[i])));
		i++;
	}
	return (ft_strdup(""));
}