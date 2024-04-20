/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/20 02:35:32 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include <stdio.h>
#include <stdlib.h>

static void	print_args(char **args)
{
	int	i;

	i = 0;
	printf("args: { ");
	while (args != NULL && args[i] != NULL)
	{
		printf("%s", args[i++]);
		if (args[i] != NULL)
			printf(", ");
	}
	printf(" },\n");
}

static void	print_redirs(t_redir *redir)
{
	if (redir == NULL)
		printf("redirs: {  }\n");
	else
	{
		printf("redirs: {\n");
		while (redir != NULL)
		{
			printf("    { type: %d, filename: %s }", \
				redir->t, redir->filename);
			redir = redir->next;
			if (redir != NULL)
				printf(",\n");
		}
		printf("\n}\n");
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
