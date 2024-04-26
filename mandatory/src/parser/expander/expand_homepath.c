/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_homepath.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 21:48:16 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/26 22:58:43 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

char	*_expand_homepath(char *arg)
{
	char	*new_arg;
	char	*tmp;

	tmp = get_homepath();
	if (tmp == NULL)
		return (NULL);
	new_arg = ft_strjoin(2, tmp, arg + 1);
	return (new_arg);
}
