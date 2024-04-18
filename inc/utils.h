/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 11:40:43 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/18 21:32:16 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "libft.h"

# define UNEXPECTED_TOKEN 0
# define AMBIGUOUS_REDIRECT 1

void	print_error(int e, char *a1, char *a2);

char	*search_env(char *arg, char **envp);
int		contains_in_env(char *arg, char **envp);

#endif