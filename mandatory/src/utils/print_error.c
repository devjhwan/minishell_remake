/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/20 02:43:58 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft.h"
#include <stdio.h>

void	print_unexpected_token(char *arg)
{
	ft_putstrerr("bash: syntax error near unexpected token `");
	ft_putstrerr(arg);
	ft_putstrerr("'\n");
}

void	print_error(t_errtype t, char *arg1, char *arg2)
{
	(void)arg2;
	if (t == UNEXPECTED_TOKEN)
		print_unexpected_token(arg1);
}
