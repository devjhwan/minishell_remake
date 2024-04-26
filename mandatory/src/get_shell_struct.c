/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_shell_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 20:47:17 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/26 21:44:30 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include <stdlib.h>
#include <stdio.h>

t_shell	*get_shell_struct(void)
{
	static t_shell	*shell;

	if (shell == NULL)
	{
		shell = (t_shell *)malloc(sizeof(t_shell));
		if (shell == NULL)
			return (NULL);
	}
	return (shell);
}
