/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/29 13:31:22 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "libft.h"
#include "utils.h"
#include <stdlib.h>

static void	unset_envvar(int pos, char **env)
{
	free(env[pos]);
	while (env[++pos] != NULL)
		env[pos - 1] = env[pos];
	env[pos - 1] = NULL;
}

static void	unset_pwd_manage(char *arg, t_shell *shell)
{
	if (ft_strncmp(arg, "PWD", 4) == 0)
	{
		free(shell->pwd);
		shell->pwd = NULL;
	}
	if (ft_strncmp(arg, "OLDPWD", 7) == 0)
	{
		free(shell->oldpwd);
		shell->oldpwd = NULL;
	}
}

void	exec_unset(char **args)
{
	int		i;
	int		pos;
	t_shell	*shell;

	i = 1;
	shell = get_shell();
	while (args[i] != NULL)
	{
		unset_pwd_manage(args[i], shell);
		pos = contains_export(args[i]);
		if (pos != -1)
			unset_envvar(pos, shell->export);
		pos = contains_env(args[i]);
		if (pos != -1)
			unset_envvar(pos, shell->env);
		i++;
	}
}
