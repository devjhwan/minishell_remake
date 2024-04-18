/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contains_in_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:20:01 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/18 21:27:13 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	contains_in_env(char *arg, char **envp)
{
	int	arg_len;

	arg_len = ft_strlen(arg);
	while (*envp != NULL)
	{
		if (ft_strncmp(*envp, arg, arg_len) == 0)
		{
			if ((*envp)[arg_len] == '\0')
				return (1);
			else if ((*envp)[arg_len] == '=')
				return (1);
		}
		envp++;
	}
	return (0);
}
