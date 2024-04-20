/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/20 02:12:20 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "libft.h"
#include <stdlib.h>

static void	print_args(char **args)
{
	int	i;

	i = 0;
	ft_putstr("args: { ");
	while (args != NULL && args[i] != NULL)
	{
		ft_putstr(args[i++]);
		if (args[i] != NULL)
			ft_putstr(", ");
	}
	ft_putstr(" },\n");
}

static void	print_redirs(t_redir *redir)
{
	if (redir == NULL)
		ft_putstr("redirs: {  }\n");
	else
	{
		ft_putstr("redirs: {\n");
		while (redir != NULL)
		{
			ft_putstr("    { type: ");
			ft_putnbr((int)redir->t);
			ft_putstr(", filename: ");
			ft_putstr(redir->filename);
			ft_putstr(" }");
			redir = redir->next;
			if (redir != NULL)
				ft_putstr(",\n");
		}
		ft_putstr("\n}\n");
	}
}

void	print_command(t_cmd *cmds)
{
	while (cmds != NULL)
	{
		print_args(cmds->args);
		print_redirs(cmds->redirs);
		cmds = cmds->next;
	}
}
