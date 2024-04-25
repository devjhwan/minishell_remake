/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_singular_env.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 21:52:18 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/26 00:15:28 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "utils.h"
#include <stdlib.h>

char	*_expand_singular_env(char *arg, t_shell *shell)
{
	if (arg == NULL)
		return (NULL);
	if (arg[1] == '\'' || arg[1] == '\"')
		return (remove_quote(arg + 1));
	else
		return (search_environment(arg + 1, shell));
}
