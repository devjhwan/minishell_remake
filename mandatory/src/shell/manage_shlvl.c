/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_shlvl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:47:49 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/28 17:59:50 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "executor.h"
#include "libft.h"
#include "utils.h"

static int	manage_shlvl_exception(int lvl, char *shlvl, t_shell *shell)
{
	char	*arg;

	arg = NULL;
	if (lvl < 0)
	{
		arg = ft_strdup("SHLVL=0");
		if (arg != NULL)
			exec_export((char *[]){"export", arg, NULL}, shell);
		return (free(arg), free(shlvl), 0);
	}
	else if (lvl > 1000)
	{
		arg = ft_strdup("SHLVL=1");
		if (arg != NULL)
			exec_export((char *[]){"export", arg, NULL}, shell);
		free(shlvl);
		shlvl = ft_itoa(lvl);
		if (shlvl != NULL)
			print_error(HIGH_SHLVL, shlvl, NULL);
		return (free(arg), free(shlvl), 0);
	}
	else if (lvl == 1000)
		exec_unset((char *[]){"unset", "SHLVL", NULL}, shell);
	return (free(arg), 1);
}

void	manage_shlvl(t_shell *shell)
{
	char	*shlvl;
	char	*arg;
	int		lvl;

	shlvl = search_environment("SHLVL");
	arg = NULL;
	if (shlvl != NULL)
	{
		lvl = ft_atoi(shlvl) + 1;
		if (manage_shlvl_exception(lvl, shlvl, shell) != 0)
		{
			free(shlvl);
			shlvl = ft_itoa(lvl);
			if (shlvl != NULL)
				arg = ft_strjoin(2, "SHLVL=", shlvl);
			if (arg != NULL)
				exec_export((char *[]){"export", arg, NULL}, shell);
			free(shlvl);
		}
	}
}
