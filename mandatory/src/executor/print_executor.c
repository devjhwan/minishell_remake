/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_executor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/29 12:54:35 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include <stdio.h>

void	print_executor(t_executor *exec)
{
	int	i;

	i = 0;
	printf("Arguments: {\n");
	while (exec->args[i] != NULL)
	{
		printf("\t%s", exec->args[i]);
		i++;
		if (exec->args[i] != NULL)
			printf(",\n");
		else
			printf("\n");
	}
	printf("},\n");
	if (exec->rdin == NULL)
		printf("Redirection IN: { NULL }\n");
	else
		printf("Redirection IN: { type: %s, path: %s },\n", \
			get_redir_enum_name(exec->rdin->t), exec->rdin->filename);
	if (exec->rdout == NULL)
		printf("Redirection OUT: { NULL }\n");
	else
		printf("Redirection OUT: { type: %s, path: %s }\n", \
			get_redir_enum_name(exec->rdout->t), exec->rdout->filename);
	printf("\n");
}
