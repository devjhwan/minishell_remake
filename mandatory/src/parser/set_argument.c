/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_argument.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/19 17:16:48 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

static int	count_args(t_arglist *args)
{
	int	count;

	count = 0;
	while (args != NULL)
	{
		count++;
		args = args->next;
	}
	return (count);
}

static void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
	{
		free(args[i]);
		args[i] = NULL;
		i++;
	}
	*args = NULL;
	free(args);
}

char	**set_argument(t_arglist *arglist)
{
	char	**args;
	int		i;

	args = (char **)malloc(sizeof(char *) * (count_args(arglist) + 1));
	if (args == NULL)
		return (NULL);
	i = 0;
	while (arglist != NULL)
	{
		args[i] = ft_strdup(arglist->arg);
		if (args[i] == NULL)
			return (free_args(args), NULL);
		arglist = arglist->next;
		i++;
	}
	return (args);
}
