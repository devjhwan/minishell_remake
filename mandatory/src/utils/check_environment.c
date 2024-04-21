/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_environment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/21 21:56:48 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_environment(char *arg, char **envp)
{
	int	i;
	int	arg_len;

	i = 0;
	arg_len = ft_strlen(arg);
	if (arg_len == 0)
		return (1);
	if (arg[0] == '\'' || arg[0] == '\"')
		return (1);
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], arg, arg_len) == 0 && envp[i][arg_len] == '=')
			return (1);
		i++;
	}
	return (0);
}