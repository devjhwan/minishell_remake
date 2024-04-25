/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/26 01:03:38 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "libft.h"
#include <stdlib.h>

int	_contains_export(char *arg, char **strarr);
int	_contains_env(char *arg, char **strarr);

static void	unset_envvar(int pos, char **env)
{
	free(env[pos]);
	while (env[++pos] != NULL)
		env[pos - 1] = env[pos];
	env[pos - 1] = NULL;
}

void	exec_unset(char **args, t_shell *shell)
{
	int	i;
	int	pos;

	i = 1;
	while (args[i] != NULL)
	{
		pos = _contains_export(args[i], shell->export);
		if (pos != -1)
			unset_envvar(pos, shell->export);
		pos = _contains_env(args[i], shell->env);
		if (pos != -1)
			unset_envvar(pos, shell->env);
		i++;
	}
}
