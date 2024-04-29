/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/29 13:34:48 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "builtin.h"
#include <unistd.h>

void	execute_builtin(char **args)
{
	if (ft_strncmp(args[0], "cd", 3) == 0)
		exec_cd(args);
	else if (ft_strncmp(args[0], "pwd", 4) == 0)
		exec_pwd();
	else if (ft_strncmp(args[0], "export", 7) == 0)
		exec_export(args);
	else if (ft_strncmp(args[0], "unset", 6) == 0)
		exec_unset(args);
	else if (ft_strncmp(args[0], "env", 4) == 0)
		exec_env(args);
	else if (ft_strncmp(args[0], "exit", 5) == 0)
		exec_exit(args);
	ft_tolower(args[0]);
	if (ft_strncmp(args[0], "echo", 5) == 0)
		exec_echo(args);
}
