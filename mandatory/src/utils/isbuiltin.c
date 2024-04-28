/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isbuiltin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/28 16:05:52 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	isbuiltin(char *arg)
{
	if (ft_strncmp(ft_tolower(arg), "echo", 5) == 0)
		return (1);
	else if (ft_strncmp(arg, "cd", 3) == 0)
		return (1);
	else if (ft_strncmp(arg, "pwd", 3) == 0)
		return (1);
	else if (ft_strncmp(arg, "export", 3) == 0)
		return (1);
	else if (ft_strncmp(arg, "unset", 3) == 0)
		return (1);
	else if (ft_strncmp(arg, "env", 3) == 0)
		return (1);
	else if (ft_strncmp(arg, "exit", 3) == 0)
		return (1);
	return (0);
}
