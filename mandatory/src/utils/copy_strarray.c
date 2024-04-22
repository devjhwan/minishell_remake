/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_strarray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/22 11:55:31 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

char	**copy_strarray(char **args)
{
	char	**new_args;
	int		i;

	i = 0;
	while (args[i] != NULL)
		i++;
	new_args = (char **)malloc(sizeof(char *) * (i + 1));
	if (new_args == NULL)
		return (NULL);
	i = 0;
	while (args[i] != NULL)
	{
		new_args[i] = ft_strdup(args[i]);
		if (new_args[i] == NULL)
			return (free_strarray(new_args), NULL);
		i++;
	}
	new_args[i] = NULL;
	return (new_args);
}
