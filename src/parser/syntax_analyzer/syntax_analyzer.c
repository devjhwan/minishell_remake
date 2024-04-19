/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analyzer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:24:16 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/08 11:08:06 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "utils.h"

int	check_missing_argument(t_token *tokens);
int	check_missing_argument2(t_token *tokens);

int	syntax_analyzer(t_token *tokens)
{
	while (tokens != NULL)
	{
		if ((tokens->t == PIPE || tokens->t == OR || tokens->t == AND) && \
			!check_missing_argument(tokens))
			return (0);
		else if (tokens->t == RD && ! check_missing_argument2(tokens))
			return (0);
		else
			tokens = tokens->next;
	}
	return (1);
}
