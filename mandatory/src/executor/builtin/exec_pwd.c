/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/26 15:58:29 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include <stdio.h>
#include <unistd.h>

void	exec_pwd(void)
{
	char	*pwd;

	pwd = (char *)malloc(sizeof(char) * 1024);
	if (pwd != NULL && getcwd(pwd, 1024) != NULL)
		printf("%s\n", pwd);
	free(pwd);
}
