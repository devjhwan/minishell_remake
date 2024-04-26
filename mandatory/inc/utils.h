/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/26 21:36:35 by junghwle         ###   ########.fr       */
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
	COMMAND_NOT_FOUND,
	TOO_MANY_ARGUMENTS,
	NUMERIC_ARGUMENT,
	HOME_NOT_SET,
	NO_FILE2,
	NOT_A_DIRECTORY,
	PERMISSION_DENIED2,
	NOT_A_VALID_IDENTIFIER,
	OLDPWD_NOT_SET
}	t_errtype;

char	*remove_quote(char *arg);
int		contains_export(char *arg, char **strarr);
int		contains_env(char *arg, char **strarr);
int		check_environment(char *arg);
char	*get_path_from_env(char *arg, char **envp);
char	*search_environment(char *arg);
void	print_error(t_errtype t, char *arg1, char *arg2);
void	print_strarray(char **args);
char	**copy_strarray(char **args);
void	free_strarray(char **strarr);
int		isbuiltin(char *arg);
int		isdir(char *filepath);
char	*get_homepath(void);

#endif