/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_export_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:30:48 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/26 18:25:03 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "libft.h"

int	_is_valid_argument(char *arg)
{
	int	i;

	if (!ft_isalpha(arg[0]))
		return (0);
	i = 0;
	while (arg[i] != '\0' && arg[i] != '=')
	{
		if (!ft_isalnum(arg[i]) && arg[i] != '_' && \
			!(arg[i] == '+' && arg[i + 1] == '='))
			return (0);
		i++;
	}
	return (1);
}

char	*_create_new_export_arg(char *var_name, char *content)
{
	if (content == NULL)
		return (ft_strjoin(2, "declare -x ", var_name));
	else
		return (ft_strjoin(5, "declare -x ", var_name, "=\"", content, "\""));
}

int	_split_argument(char *arg, char **var_name, char **content, int *append_f)
{
	char	*tmp;

	tmp = ft_strchr(arg, '=');
	if (tmp == NULL)
	{
		*var_name = ft_strdup(arg);
		*content = NULL;
		if (*var_name == NULL)
			return (free(*var_name), 0);
	}
	else
	{
		*(tmp++) = '\0';
		*var_name = ft_strdup(arg);
		*content = ft_strdup(tmp);
		if (*var_name == NULL || *content == NULL)
			return (free(*var_name), free(*content), 0);
	}
	*append_f = 0;
	if ((*var_name)[ft_strlen((*var_name)) - 1] == '+')
	{
		(*var_name)[ft_strlen((*var_name)) - 1] = '\0';
		*append_f = 1;
	}
	return (1);
}

int	_export_pwd_management(char *var_name, char *content, t_shell *shell)
{
	if (content == NULL)
		return (1);
	if (ft_strncmp(var_name, "PWD", 4) == 0)
	{
		free(shell->pwd);
		shell->pwd = ft_strdup(content);
		if (shell->pwd == NULL)
			return (0);
	}
	else if (ft_strncmp(var_name, "OLDPWD", 7) == 0)
	{
		free(shell->oldpwd);
		shell->oldpwd = ft_strdup(content);
		if (shell->oldpwd == NULL)
			return (0);
	}
	return (1);
}
