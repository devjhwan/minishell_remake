/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redir_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:39:38 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/22 01:15:24 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "libft.h"

t_rdtype	get_redir_type(char *arg)
{
	if (ft_strncmp(arg, "<", 2) == 0)
		return (IN);
	else if (ft_strncmp(arg, ">", 2) == 0)
		return (OUT);
	else if (ft_strncmp(arg, "<<", 3) == 0)
		return (IN2);
	else
		return (OUT2);
}
