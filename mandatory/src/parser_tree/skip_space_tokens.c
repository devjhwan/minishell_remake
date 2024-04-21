/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_space_tokens.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 20:00:53 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/21 20:01:02 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_tree.h"

t_ptoken	*skip_space_tokens(t_ptoken *tokens)
{
	while (tokens != NULL)
	{
		if (tokens->t != SP)
			return (tokens);
		tokens = tokens->next;
	}
	return (NULL);
}