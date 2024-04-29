/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redir_enum_name.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/29 12:29:34 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirection.h"
#include <stdio.h>

char	*get_redir_enum_name(t_rdtype t)
{
	if (t == IN)
		return ("IN");
	else if (t == IN2)
		return ("HEREDOC");
	else if (t == OUT)
		return ("OUT");
	else if (t == OUT2)
		return ("OUT2");
	else
		return ("UNKNOWN");
}