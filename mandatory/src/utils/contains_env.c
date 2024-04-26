/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contains_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:11:42 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/26 18:11:49 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	contains_env(char *arg, char **strarr)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(arg);
	while (strarr[i] != NULL)
	{
		if (ft_strncmp(strarr[i], arg, len) == 0)
			return (i);
		i++;
	}
	return (-1);
}