/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/24 00:03:36 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"
#include "libft.h"

void	execute_builtin(t_executor *exec, t_shell *shell)
{
	(void) shell;
	if (ft_strncmp(exec->args[0], "echo", 5) == 0)
		exec_echo(exec->args);
	if (ft_strncmp(exec->args[0], "env", 4) == 0)
		exec_env(shell->env);
}
