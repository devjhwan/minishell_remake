/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 11:39:27 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/18 21:33:04 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "utils.h"

void	print_args(int argc, ...)
{
	va_list	ap;
	char	*tmp;

	va_start(ap, argc);
	while (argc-- > 0)
	{
		tmp = va_arg(ap, char *);
		write(2, tmp, ft_strlen(tmp));
	}
	va_end(ap);
}

void	print_error(int e, char *a1, char *a2)
{
	(void) a2;
	if (e == UNEXPECTED_TOKEN)
		print_args(3, "bash: syntax error near unexpected token `", a1, "'\n");
	if (e == AMBIGUOUS_REDIRECT)
		print_args(3, "bash: ", a1, ": ambiguous redirect\n");
}
