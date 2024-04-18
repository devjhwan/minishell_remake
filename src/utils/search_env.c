/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:03:35 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/07 21:40:59 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*search_env(char *arg, char **envp)
{
	int	arg_len;

	arg_len = ft_strlen(arg);
	while (*envp != NULL)
	{
		if (ft_strncmp(*envp, arg, arg_len) == 0)
		{
			if ((*envp)[arg_len] == '\0')
				return (ft_strdup(""));
			else if ((*envp)[arg_len] == '=')
				return (ft_substr(*envp, arg_len + 1, ft_strlen(*envp)));
		}
		envp++;
	}
	return (ft_strdup(""));
}
