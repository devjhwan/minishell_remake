/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_token2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 17:25:02 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/21 17:46:04 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	_isquote(char *line)
{
	if (*line == '\'')
		return (1);
	else
		return (0);
}

int	_isdquote(char *line)
{
	if (*line == '\"')
		return (1);
	else
		return (0);
}

int	_isspace(char *line)
{
	if (*line == ' ')
		return (1);
	else
		return (0);
}

int	_isargument(char *line)
{
	if (ft_strchr("|$<> \'\"", *line) == NULL)
		return (1);
	else
		return (0);
}
