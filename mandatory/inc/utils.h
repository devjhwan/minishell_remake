/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/26 00:24:28 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "shell.h"

typedef enum e_errtype
{
	UNEXPECTED_TOKEN,
	AMBIGUOUS_REDIRECT,
	NO_FILE,
	PERMISSION_DENIED,
	IS_DIRECTORY,
	COMMAND_NOT_FOUND,
	TOO_MANY_ARGUMENTS,
	NUMERIC_ARGUMENT
}	t_errtype;

char	*remove_quote(char *arg);
int		check_environment(char *arg, t_shell *shell);
char	*search_environment(char *arg, t_shell *shell);
void	print_error(t_errtype t, char *arg1, char *arg2);
void	print_strarray(char **args);
char	**copy_strarray(char **args);
void	free_strarray(char **strarr);
int		isbuiltin(char *arg);

#endif