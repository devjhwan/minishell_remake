/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:14:23 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/18 21:45:01 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "libft.h"

int expand_quotes(t_token *tokens)
{
    char    *new_arg;

    while (tokens != NULL)
    {
        if (tokens->t == SQ || tokens->t == DQ)
        {
            new_arg = ft_substr(tokens->arg, 1, ft_strlen(tokens->arg) - 2);
            if (new_arg == NULL)
                return (0);
            free(tokens->arg);
            tokens->arg = new_arg;
            tokens->t = ARG;
        }
        tokens = tokens->next;
    }
    return (1);
}
