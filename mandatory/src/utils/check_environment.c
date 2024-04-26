/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_environment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/26 21:12:31 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "libft.h"

int	check_environment(char *arg)
{
	int		i;
	int		arg_len;
	t_shell	*shell;

	i = 0;
	arg_len = ft_strlen(arg);
	shell = get_shell_struct();
	if (arg_len == 0)
		return (1);
	if (arg[0] == '\'' || arg[0] == '\"')
		return (1);
	while (shell->env[i] != NULL)
	{
		if (ft_strncmp(shell->env[i], arg, arg_len) == 0 && \
						shell->env[i][arg_len] == '=')
			return (1);
		i++;
	}
	return (0);
}
