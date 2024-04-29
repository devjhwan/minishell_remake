/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contains_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:11:23 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/29 13:30:06 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "libft.h"

int	contains_export(char *arg)
{
	int		i;
	int		len;
	char	**export;

	i = 0;
	len = ft_strlen(arg);
	export = get_shell()->export;
	while (export[i] != NULL)
	{
		if (ft_strncmp(export[i] + 11, arg, len) == 0)
			return (i);
		i++;
	}
	return (-1);
}
