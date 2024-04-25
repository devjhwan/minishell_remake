/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/25 14:21:31 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

typedef enum e_errtype
{
	UNEXPECTED_TOKEN,
	AMBIGUOUS_REDIRECT,
	NO_FILE,
	PERMISSION_DENIED,
	IS_DIRECTORY,
	COMMAND_NOT_FOUND
}	t_errtype;

char	*remove_quote(char *arg);
int		check_environment(char *arg, char **envp);
char	*search_environment(char *arg, char **envp);
void	print_error(t_errtype t, char *arg1, char *arg2);
void	print_strarray(char **args);
char	**copy_strarray(char **args);
void	free_strarray(char **strarr);
int		isbuiltin(char *arg);

#endif