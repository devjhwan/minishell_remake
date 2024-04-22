/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/22 10:48:27 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft.h"
#include <stdio.h>

void	print_unexpected_token(char *arg)
{
	ft_putstrerr("minishell: syntax error near unexpected token `");
	ft_putstrerr(arg);
	ft_putstrerr("'\n");
}

void	print_ambiguous_redirect(char *arg)
{
	ft_putstrerr("minishell: ");
	ft_putstrerr(arg);
	ft_putstrerr(": ambiguous redirect\n");
}

void	print_no_file(char *arg)
{
	ft_putstrerr("minishell: ");
	ft_putstrerr(arg);
	ft_putstrerr(": No such file or directory\n");
}

void	print_permission_denied(char *arg)
{
	ft_putstrerr("minishell: ");
	ft_putstrerr(arg);
	ft_putstrerr(": Permission denied\n");
}

void	print_is_directory(char *arg)
{
	ft_putstrerr("minishell: ");
	ft_putstrerr(arg);
	ft_putstrerr(": Is a directory\n");
}

void	print_error(t_errtype t, char *arg1, char *arg2)
{
	(void)arg2;
	if (t == UNEXPECTED_TOKEN)
		print_unexpected_token(arg1);
	else if (t == AMBIGUOUS_REDIRECT)
		print_ambiguous_redirect(arg1);
	else if (t == NO_FILE)
		print_no_file(arg1);
	else if (t == PERMISSION_DENIED)
		print_permission_denied(arg1);
	else if (t == IS_DIRECTORY)
		print_is_directory(arg1);
}
