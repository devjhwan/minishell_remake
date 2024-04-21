/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 21:06:42 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/21 21:06:56 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*remove_quote(char *arg)
{
	char	*new_arg;

	new_arg = ft_substr(arg, 1, ft_strlen(arg) - 2);
	return (new_arg);
}