/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/29 11:59:28 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_ERROR_H
# define PRINT_ERROR_H

typedef enum e_errtype
{
	UNEXPECTED_TOKEN,
	AMBIGUOUS_REDIRECT,
	NO_FILE,
	PERMISSION_DENIED,
	IS_DIRECTORY,
	IS_DIRECTORY2,
	COMMAND_NOT_FOUND,
	TOO_MANY_ARGUMENTS,
	NUMERIC_ARGUMENT,
	HOME_NOT_SET,
	NO_FILE2,
	NOT_A_DIRECTORY,
	PERMISSION_DENIED2,
	NOT_A_VALID_IDENTIFIER,
	OLDPWD_NOT_SET,
	FILENAME_TOO_LONG,
	HIGH_SHLVL
}	t_errtype;

void	print_error(t_errtype t, char *arg1, char *arg2);

#endif