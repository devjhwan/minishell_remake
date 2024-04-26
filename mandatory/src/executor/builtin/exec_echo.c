/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/26 03:04:38 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static int	isnflag(char *arg)
{
	int	i;

	if (arg[0] != '-')
		return (0);
	i = 1;
	while (arg[i] == 'n')
		i++;
	if (arg[i] != '\0')
		return (0);
	return (1);
}

void	exec_echo(char **args)
{
	int	i;
	int	nflag;

	i = 1;
	while (args[i] != NULL && isnflag(args[i]))
		i++;
	if (i > 1)
		nflag = 1;
	else
		nflag = 0;
	while (args[i] != NULL)
	{
		printf("%s", args[i++]);
		if (args[i] != NULL)
			printf(" ");
	}
	if (!nflag)
		printf("\n");
}
