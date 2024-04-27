/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_token1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 17:21:37 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/27 15:37:37 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ispipe(char *line)
{
	if (*line == '|')
		return (1);
	else
		return (0);
}

int	isredir(char *line)
{
	if (ft_strncmp(line, "<<", 2) == 0)
		return (1);
	else if (ft_strncmp(line, ">>", 2) == 0)
		return (1);
	else if (ft_strncmp(line, "<", 1) == 0)
		return (1);
	else if (ft_strncmp(line, ">", 1) == 0)
		return (1);
	else
		return (0);
}

int	isenv(char *line)
{
	if (*line == '$')
		return (1);
	else
		return (0);
}
