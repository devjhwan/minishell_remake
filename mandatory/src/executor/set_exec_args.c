/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_exec_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/19 18:06:38 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"
#include "unistd.h"
#include "errno.h"

static char	*find_path(char *arg, char **path_split)
{
	char	*new_arg;
	int		i;

	if (path_split == NULL)
		return (ft_strdup(arg));
	i = 0;
	while (path_split[i] != NULL)
	{
		new_arg = ft_strjoin(3, path_split[i], "/", arg);
		if (new_arg == NULL)
			return (NULL);
		if (access(new_arg, F_OK) == 0)
			return (new_arg);
		errno = 0;
		i++;
	}
	return (ft_strdup(arg));
}

static char	*get_path_from_env(char *arg, char **envp)
{
	char	**path_split;
	char	*path;
	char	*new_arg;
	int		i;

	i = 0;
	while (envp[i] != NULL && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (envp[i] == NULL)
		return (ft_strdup(arg));
	path = &envp[i][5];
	path_split = ft_split(path, ":");
	if (path_split == NULL)
		return (NULL);
	new_arg = find_path(arg, path_split);
	return (free_strarray(path_split), new_arg);
}

char	**set_exec_args(char **args, char **envp)
{
	char	**new_args;
	char	*arg;

	new_args = copy_strarray(args);
	if (new_args == NULL)
		return (NULL);
	arg = get_path_from_env(args[0], envp);
	if (arg == NULL)
		return (free_strarray(new_args), NULL);
	free(new_args[0]);
	new_args[0] = arg;
	return (new_args);
}
