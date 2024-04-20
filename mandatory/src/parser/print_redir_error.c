/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_redir_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/20 03:43:18 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "utils.h"

static char	*get_err_argument(char *line)
{
	if (line[0] == '<')
	{
		if (line[1] == '<')
			line[2] = '\0';
		else
			line[1] = '\0';
	}
	else if (line[0] == '>')
	{
		if (line[1] == '>')
			line[2] = '\0';
		else
			line[1] = '\0';
	}
	else if (line[0] == '|')
		line[1] = '\0';
	return (line);
}

void	print_redir_error(char *line)
{
	char		*arg;
	
	while (*line == ' ')
		line++;
	if (*line == '\0')
		print_error(UNEXPECTED_TOKEN, "newline", NULL);
	else
	{
		arg = get_err_argument(line);
		print_error(UNEXPECTED_TOKEN, arg, NULL);
	}
}