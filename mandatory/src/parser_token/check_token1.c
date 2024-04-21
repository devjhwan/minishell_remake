/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_token1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 17:21:37 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/21 17:31:26 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	_ispipe(char *line)
{
	if (*line == '|')
		return (1);
	else
		return (0);
}

int	_isredir(char *line)
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

int	_isenv(char *line)
{
	if (*line == '$')
		return (1);
	else
		return (0);
}
