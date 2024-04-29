/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_shlvl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:47:49 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/29 13:27:06 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "libft.h"
#include "builtin.h"
#include "print_error.h"

static int	check_shlvl_exception2(int lvl)
{
	char	*arg;

	arg = ft_strdup("SHLVL=1");
	if (arg == NULL)
		return (-1);
	exec_export((char *[]){"export", arg, NULL});
	free(arg);
	arg = ft_itoa(lvl);
	if (arg == NULL)
		return (-1);
	print_error(HIGH_SHLVL, arg, NULL);
	return (free(arg), 1);
}

static int	check_shlvl_exception(int lvl)
{
	char	*arg;

	if (lvl < 0)
	{
		arg = ft_strdup("SHLVL=0");
		if (arg == NULL)
			return (-1);
		exec_export((char *[]){"export", arg, NULL});
		return (free(arg), 1);
	}
	else if (lvl == 1000)
	{
		exec_unset((char *[]){"unset", "SHLVL", NULL});
		return (1);
	}
	else if (lvl > 1000)
		return (check_shlvl_exception2(lvl));
	else
		return (0);
}

int	manage_shlvl(void)
{
	char	*shlvl;
	char	*arg;
	int		lvl;
	int		ret;

	shlvl = search_environment("SHLVL");
	if (shlvl == NULL)
		return (0);
	arg = NULL;
	lvl = ft_atoi(shlvl) + 1;
	ret = check_shlvl_exception(lvl);
	if (ret == -1)
		return (free(shlvl), 0);
	else if (ret == 0)
	{
		free(shlvl);
		shlvl = ft_itoa(lvl);
		if (shlvl == NULL)
			return (0);
		arg = ft_strjoin(2, "SHLVL=", shlvl);
		if (arg == NULL)
			return (free(shlvl), 0);
		exec_export((char *[]){"export", arg, NULL});
	}
	return (free(shlvl), free(arg), 1);
}
