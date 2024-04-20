/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_arg_length.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/20 14:33:13 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	count_quote_arg_length(char *arg)
{
	int	len;

	len = 0;
	if (*arg == '\"')
	{
		len++;
		while (arg[len] != '\0' && arg[len] != '\"')
			len++;
		len++;
	}
	else if (*arg == '\'')
	{
		len++;
		while (arg[len] != '\0' && arg[len] != '\'')
			len++;
		len++;
	}
	return (len);
}

int	count_arg_length(char *arg)
{
	int	len;

	if (*arg == '\"' || *arg == '\'')
		return (count_quote_arg_length(arg));
	len = 1;
	while (arg[len] != '\0' && arg[len] != ' ' && \
		!is_redir(&arg[len]) && !is_pipe(&arg[len]))
		len++;
	return (len);
}
