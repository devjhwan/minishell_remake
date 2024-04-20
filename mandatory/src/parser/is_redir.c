/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_redir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/20 02:08:04 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

int	is_redir(char *arg)
{
	if (ft_strncmp(arg, "<<", 2) == 0 || ft_strncmp(arg, ">>", 2) == 0 || \
		ft_strncmp(arg, "<", 1) == 0 || ft_strncmp(arg, ">", 1) == 0)
		return (1);
	return (0);
}
