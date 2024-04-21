/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_singular_env.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 21:52:18 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/21 21:52:43 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdlib.h>

char	*expand_singular_env(char *arg, char **envp)
{
	if (arg == NULL)
		return (NULL);
	if (arg[1] == '\'' || arg[1] == '\"')
		return (remove_quote(arg + 1));
	else
		return (search_environment(arg + 1, envp));
}