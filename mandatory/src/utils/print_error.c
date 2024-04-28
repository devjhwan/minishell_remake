/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/28 16:38:47 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft.h"
#include "shell.h"
#include <stdio.h>

void	print_unexpected_token(char *arg)
{
	ft_putstrerr("syntax error near unexpected token `");
	ft_putstrerr(arg);
	ft_putstrerr("'\n");
	get_shell_struct()->exit_code = 2;
}

void	print_ambiguous_redirect(char *arg)
{
	ft_putstrerr(arg);
	ft_putstrerr(": ambiguous redirect\n");
	get_shell_struct()->exit_code = 1;
}

void	print_no_file(char *arg)
{
	ft_putstrerr(arg);
	ft_putstrerr(": No such file or directory\n");
	get_shell_struct()->new_exit_code = 1;
}

void	print_permission_denied(char *arg)
{
	ft_putstrerr(arg);
	ft_putstrerr(": Permission denied\n");
	get_shell_struct()->new_exit_code = 1;
}

void	print_is_directory(char *arg)
{
	ft_putstrerr(arg);
	ft_putstrerr(": is a directory\n");
	get_shell_struct()->new_exit_code = 126;
}

void	print_command_not_found(char *arg)
{
	ft_putstrerr(arg);
	ft_putstrerr(": command not found\n");
	get_shell_struct()->new_exit_code = 127;
}

void	print_too_many_arguments(char *arg)
{
	ft_putstrerr(arg);
	ft_putstrerr(": too many arguments\n");
	get_shell_struct()->new_exit_code = 1;
}

void	print_numeric_argument_requiered(char *arg1, char *arg2)
{
	ft_putstrerr(arg1);
	ft_putstrerr(": ");
	ft_putstrerr(arg2);
	ft_putstrerr(": numeric argument required\n");
	get_shell_struct()->new_exit_code = 255;
}

void	print_home_not_set(char *arg)
{
	ft_putstrerr(arg);
	ft_putstrerr(": HOME not set\n");
}

void	print_no_file2(char *arg1, char *arg2)
{
	ft_putstrerr(arg1);
	ft_putstrerr(": ");
	ft_putstrerr(arg2);
	ft_putstrerr(": No such file or directory\n");
	get_shell_struct()->new_exit_code = 1;
}

void	print_not_a_directory(char *arg1, char *arg2)
{
	ft_putstrerr(arg1);
	ft_putstrerr(": ");
	ft_putstrerr(arg2);
	ft_putstrerr(": Not a directory\n");
	get_shell_struct()->new_exit_code = 1;
}

void	print_permission_denied2(char *arg1, char *arg2)
{
	ft_putstrerr(arg1);
	ft_putstrerr(": ");
	ft_putstrerr(arg2);
	ft_putstrerr(": Permission denied\n");
	get_shell_struct()->new_exit_code = 1;
}

void	print_not_a_valid_identifier(char *arg1, char *arg2)
{
	ft_putstrerr(arg1);
	ft_putstrerr(": `");
	ft_putstrerr(arg2);
	ft_putstrerr("': not a valid identifier\n");
	get_shell_struct()->new_exit_code = 1;
}

void	print_oldpwd_not_set(char *arg)
{
	ft_putstrerr(arg);
	ft_putstrerr(": OLDPWD not set\n");
}

void	print_filename_too_long(char *arg1, char *arg2)
{
	ft_putstrerr(arg1);
	ft_putstrerr(": ");
	ft_putstrerr(arg2);
	ft_putstrerr(": File name too long\n");
	get_shell_struct()->new_exit_code = 1;
}

void	print_error(t_errtype t, char *arg1, char *arg2)
{
	ft_putstrerr("minishell: ");
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
	else if (t == COMMAND_NOT_FOUND)
		print_command_not_found(arg1);
	else if (t == TOO_MANY_ARGUMENTS)
		print_too_many_arguments(arg1);
	else if (t == NUMERIC_ARGUMENT)
		print_numeric_argument_requiered(arg1, arg2);
	else if (t == HOME_NOT_SET)
		print_home_not_set(arg1);
	else if (t == NO_FILE2)
		print_no_file2(arg1, arg2);
	else if (t == NOT_A_DIRECTORY)
		print_not_a_directory(arg1, arg2);
	else if (t == PERMISSION_DENIED2)
		print_permission_denied2(arg1, arg2);
	else if (t == NOT_A_VALID_IDENTIFIER)
		print_not_a_valid_identifier(arg1, arg2);
	else if (t == OLDPWD_NOT_SET)
		print_oldpwd_not_set(arg1);
	else if (t == FILENAME_TOO_LONG)
		print_filename_too_long(arg1, arg2);
}
