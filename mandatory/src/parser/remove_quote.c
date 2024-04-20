/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/20 04:40:18 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*remove_quote(char *arg)
{
	size_t	i;

	if (arg[0] == '\'')
	{
		i = 1;
		while (arg[i] != '\0' && arg[i] != '\'')
			i++;
		if (arg[i] == '\'')
			arg[i] = '\0';
		arg = ft_strdup(arg + 1);
	}
	else if (arg[0] == '\"')
	{
		i = 1;
		while (arg[i] != '\0' && arg[i] != '\"')
			i++;
		if (arg[i] == '\"')
			arg[i] = '\0';
		arg = ft_strdup(arg + 1);
	}
	return (arg);
}
