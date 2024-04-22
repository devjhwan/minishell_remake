/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 17:34:09 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/22 11:58:20 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_token.h"
#include <stdio.h>

static char	*get_enum_name(t_tokentype t)
{
	if (t == ARG)
		return ("ARGUMENT");
	else if (t == SQ)
		return ("SINGLE QUOTE");
	else if (t == DQ)
		return ("DOUBLE QUOTE");
	else if (t == ENV)
		return ("ENVIRONMENT");
	else if (t == SP)
		return ("SPACE");
	else if (t == RD)
		return ("REDIRECTION");
	else if (t == PIPE)
		return ("PIPE");
	else
		return ("UNKNOWN");
}

void	print_tokens(t_ptoken *tokens)
{
	while (tokens != NULL)
	{
		printf("{ token_type = %-12s, argument = %-8s }", \
				get_enum_name(tokens->t), tokens->arg);
		if (tokens->next != NULL)
			printf(",\n");
		else
			printf("\n");
		tokens = tokens->next;
	}
	printf("\n");
}
