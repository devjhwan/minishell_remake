/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_strarr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:42:36 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/21 17:27:55 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	free_strarr(char **strarr)
{
	int	i;

	i = 0;
	while (strarr[i] != NULL)
	{
		free(strarr[i]);
		strarr[i] = NULL;
		i++;
	}
	free(strarr);
}
