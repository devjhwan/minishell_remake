/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/29 13:37:29 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include <stdio.h>

static void	print_arguments(char **args)
{
	printf("\tArguments: { ");
	while (*args != NULL)
	{
		printf("%s", *args);
		args++;
		if (*args != NULL)
			printf(", ");
	}
	printf(" }\n");
}

static void	print_redirections(t_redir *redirs)
{
	printf("\tRedirections: {\n");
	while (redirs != NULL)
	{
		printf("\t\t{ type: %-8s, filename: %s }", \
			get_redir_enum_name(redirs->t), redirs->filename);
		redirs = redirs->next;
		if (redirs != NULL)
			printf(",");
		printf("\n");
	}
	printf("\t}\n");
}

void	print_command(t_cmd *cmds)
{
	while (cmds != NULL)
	{
		printf("Command type: %s\n", get_cmd_enum_name(cmds->t));
		print_arguments(cmds->args);
		print_redirections(cmds->redirs);
		cmds = cmds->next;
	}
	printf("\n");
}
