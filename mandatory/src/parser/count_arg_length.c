/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_arg_length.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/19 17:32:21 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	count_arg_length(char *arg)
{
	int	len;

	len = 0;
	if (*arg == '\"')
	{
		len++;
		while (arg[len] != '\0' && arg[len] != '\"')
			len++;
	}
	else if (*arg == '\'')
	{
		len++;
		while (arg[len] != '\0' && arg[len] != '\'')
			len++;
	}
	else
	{
		while (arg[len] != '\0' && arg[len] != ' ' && \
			!is_redir(&arg[len]) && !is_pipe(&arg[len]))
			len++;
	}
	return (len);
}
