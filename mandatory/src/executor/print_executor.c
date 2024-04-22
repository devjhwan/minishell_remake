/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_executor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/22 11:57:58 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include <stdio.h>

static char	*get_redir_enum_name(t_rdtype t)
{
	if (t == IN)
		return ("IN");
	else if (t == IN2)
		return ("HEREDOC");
	else if (t == OUT)
		return ("OUT");
	else if (t == OUT2)
		return ("OUT2");
	else
		return ("UNKNOWN");
}

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
	if (exec->in == NULL)
		printf("Redirection IN: { NULL }\n");
	else
		printf("Redirection IN: { type: %s, path: %s },\n", \
			get_redir_enum_name(exec->in->t), exec->in->filename);
	if (exec->out == NULL)
		printf("Redirection OUT: { NULL }\n");
	else
		printf("Redirection OUT: { type: %s, path: %s }\n", \
			get_redir_enum_name(exec->out->t), exec->out->filename);
	printf("\n");
}
