/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isbuiltin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/29 13:35:19 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "libft.h"

int	isbuiltin(char *arg)
{
	char	*low_arg;

	low_arg = ft_strdup(arg);
	if (low_arg != NULL)
		ft_tolower(low_arg);
	if (ft_strncmp(arg, "echo", 5) == 0)
		return (free(low_arg), 1);
	if (contains_env("PATH") && ft_strncmp(low_arg, "echo", 5) == 0)
		return (free(low_arg), 1);
	else if (ft_strncmp(arg, "cd", 3) == 0)
		return (free(low_arg), 1);
	else if (ft_strncmp(arg, "pwd", 3) == 0)
		return (free(low_arg), 1);
	else if (ft_strncmp(arg, "export", 3) == 0)
		return (free(low_arg), 1);
	else if (ft_strncmp(arg, "unset", 3) == 0)
		return (free(low_arg), 1);
	else if (ft_strncmp(arg, "env", 3) == 0)
		return (free(low_arg), 1);
	else if (ft_strncmp(arg, "exit", 3) == 0)
		return (free(low_arg), 1);
	return (free(low_arg), 0);
}
