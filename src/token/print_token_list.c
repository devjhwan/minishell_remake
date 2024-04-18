/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_token_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:38:49 by junghwle          #+#    #+#             */
/*   Updated: 2024/03/26 19:44:36 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "libft.h"

void	print_token_list(t_token *token_list)
{
	ft_printf("[\n");
	while (token_list != NULL)
	{
		ft_printf("\t[\n");
		ft_printf("\ttoken_type = %d\n", token_list->t);
		ft_printf("\ttoken_arg  = %s\n", token_list->arg);
		token_list = token_list->next;
		ft_printf("\t]");
		if (token_list != NULL)
			ft_printf(",");
		ft_printf("\n");
	}
	ft_printf("]\n");
}
