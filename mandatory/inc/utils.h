/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/20 14:43:49 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

typedef enum e_errtype
{
	UNEXPECTED_TOKEN,
	AMBIGUOUS_REDIRECT
}	t_errtype;

void	print_error(t_errtype t, char *arg1, char *arg2);
char	*search_env(char *arg, char **envp);
int		check_env(char *arg, char **envp);
void	free_split(char **split);

#endif