/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contains_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:11:42 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/29 13:30:24 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "libft.h"

int	contains_env(char *arg)
{
	int		i;
	int		len;
	char	**env;

	i = 0;
	len = ft_strlen(arg);
	env = get_shell()->env;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], arg, len) == 0)
			return (i);
		i++;
	}
	return (-1);
}
