/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/26 17:33:51 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "utils.h"
#include "libft.h"
#include <stdlib.h>

static int	isnumeric(char *arg)
{
	int		i;
	char	*nb;

	i = 0;
	nb = ft_strdup("9223372036854775807");
	if (nb == NULL)
		return (0);
	if (arg[i] == '+')
		arg++;
	else if (arg[i] == '-')
	{
		arg++;
		nb[18] = '8';
	}
	while (arg[i] != '\0' && ft_isdigit(arg[i]) && i < 19)
		i++;
	if (arg[i] != '\0' && !ft_isdigit(arg[i]))
		return (free(nb), 0);
	if (i < 19)
		return (free(nb), 1);
	while (i >= 0 && arg[i] < nb[i])
		i--;
	if (i >= 0)
		return (free(nb), 0);
	return (free(nb), 1);
}

static char	atoc(char *arg)
{
	char	nb;
	int		nf;

	nb = 0;
	nf = 0;
	if (*arg == '+')
		++arg;
	else if (*arg == '-')
	{
		++arg;
		nf = 1;
	}
	if (nf)
		while (*arg != '\0')
			nb = nb * 10 - (*arg++ - '0');
	else
		while (*arg != '\0')
			nb = nb * 10 + (*arg++ - '0');
	return (nb);
}

void	exec_exit(char **args, t_shell *shell)
{
	ft_putstrerr("exit\n");
	if (args[1] == NULL)
		shell->is_exit = 1;
	else if (args[2] != NULL)
		print_error(TOO_MANY_ARGUMENTS, args[0], NULL);
	else if (!isnumeric(args[1]))
		print_error(NUMERIC_ARGUMENT, args[0], args[1]);
	else
		shell->exit_code = atoc(args[1]);
	shell->is_exit = 1;
}
