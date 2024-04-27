/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/27 15:52:08 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "utils.h"
#include "libft.h"
#include <stdlib.h>

static int	check_digit(char *arg, char *nb)
{
	int	i;

	while (arg[0] == ' ')
		arg++;
	if (*arg == '\0')
		return (0);
	i = 0;
	while (arg[i] != '\0' && ft_isdigit(arg[i]))
		i++;
	while (arg[i] == ' ')
		i++;
	if (arg[i] != '\0')
		return (0);
	while (arg[0] == '0')
		arg++;
	i = 0;
	while (arg[i] != '\0' && i < 19)
		i++;
	if (i < 19)
		return (1);
	i--;
	while (i >= 0 && arg[i] <= nb[i])
		i--;
	return (i < 0);
}

static int	isnumeric(char *arg)
{
	char	*nb;

	nb = ft_strdup("9223372036854775807");
	if (nb == NULL)
		return (0);
	if (arg[0] == '+')
		arg++;
	else if (arg[0] == '-')
	{
		arg++;
		nb[18] = '8';
	}
	if (arg[0] == '\0')
		return (free(nb), 0);
	if (check_digit(arg, nb))
		return (free(nb), 1);
	else
		return (free(nb), 0);
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
	while (*arg == ' ')
		arg++;
	if (nf)
		while (ft_isdigit(*arg))
			nb = nb * 10 - (*arg++ - '0');
	else
		while (ft_isdigit(*arg))
			nb = nb * 10 + (*arg++ - '0');
	return (nb);
}

void	exec_exit(char **args, t_shell *shell)
{
	// ft_putstrerr("exit\n");
	if (args[1] == NULL)
	{
		shell->new_exit_code = shell->exit_code;
		shell->is_exit = 1;
	}
	else if (!isnumeric(args[1]))
	{
		print_error(NUMERIC_ARGUMENT, args[0], args[1]);
		shell->is_exit = 1;
	}
	else if (args[2] != NULL)
		print_error(TOO_MANY_ARGUMENTS, args[0], NULL);
	else
	{
		shell->new_exit_code = atoc(args[1]);
		shell->is_exit = 1;
	}
}
