/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/26 21:28:48 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "utils.h"
#include "libft.h"

int		_is_valid_argument(char *arg);
char	*_create_new_export_arg(char *var_name, char *content);
int		_split_argument(char *arg, char **v_name, char **cntnt, int *append_f);
int		_export_pwd_management(char *var_name, char *content, t_shell *shell);

int	append_to_export(char *var_name, char *new_content, t_shell *shell)
{
	char	*new_arg;
	int		count;
	char	**tmp;

	new_arg = _create_new_export_arg(var_name, new_content);
	if (new_arg == NULL)
		return (free(var_name), free(new_content), 0);
	count = 0;
	while (shell->export[count] != NULL)
		count++;
	tmp = (char **)malloc(sizeof(char *) * (count + 2));
	if (tmp == NULL)
		return (free(new_arg), free(var_name), free(new_content), 0);
	count = 0;
	while (shell->export[count] != NULL)
	{
		tmp[count] = shell->export[count];
		count++;
	}
	tmp[count++] = new_arg;
	tmp[count] = NULL;
	free(shell->export);
	shell->export = tmp;
	return (1);
}

int	add_to_export(char *var_name, char *new_content, \
					int append_f, t_shell *shell)
{
	int		pos;
	char	*prev_content;
	char	*new_arg;

	pos = contains_export(var_name, shell->export);
	if (pos != -1 && new_content != NULL)
	{
		prev_content = ft_strchr(shell->export[pos], '=');
		if (prev_content != NULL)
			(prev_content)[ft_strlen(prev_content) - 1] = '\0';
		if (append_f && prev_content != NULL)
			new_arg = ft_strjoin(5, "declare -x ", var_name, \
									prev_content, new_content, "\"");
		else
			new_arg = ft_strjoin(5, "declare -x ", var_name, \
									"=\"", new_content, "\"");
		if (new_arg == NULL)
			return (free(var_name), free(new_content), 0);
		free(shell->export[pos]);
		shell->export[pos] = new_arg;
	}
	else if (pos == -1)
		return (append_to_export(var_name, new_content, shell));
	return (1);
}

int	append_to_env(char *var_name, char *new_content, t_shell *shell)
{
	char	*new_arg;
	int		count;
	char	**tmp;

	new_arg = ft_strjoin(3, var_name, "=", new_content);
	if (new_arg == NULL)
		return (free(var_name), free(new_content), 0);
	count = 0;
	while (shell->env[count] != NULL)
		count++;
	tmp = (char **)malloc(sizeof(char *) * (count + 2));
	if (tmp == NULL)
		return (free(new_arg), free(var_name), free(new_content), 0);
	count = 0;
	while (shell->env[count] != NULL)
	{
		tmp[count] = shell->env[count];
		count++;
	}
	tmp[count++] = new_arg;
	tmp[count] = NULL;
	free(shell->env);
	shell->env = tmp;
	return (free(var_name), free(new_content), 1);
}

int	add_to_env(char *var_name, char *new_content, \
					int append_f, t_shell *shell)
{
	int		pos;
	char	*prev_content;
	char	*new_arg;

	if (new_content == NULL)
		return (free(var_name), free(new_content), 1);
	pos = contains_env(var_name, shell->env);
	if (pos != -1 && new_content != NULL)
	{
		prev_content = ft_strchr(shell->env[pos], '=');
		if (prev_content == NULL)
			return (free(var_name), free(new_content), 1);
		if (append_f)
			new_arg = ft_strjoin(3, var_name, prev_content, new_content);
		else
			new_arg = ft_strjoin(3, var_name, "=", new_content);
		if (new_arg == NULL)
			return (free(var_name), free(new_content), 0);
		free(shell->env[pos]);
		shell->env[pos] = new_arg;
	}
	else if (pos == -1)
		return (append_to_env(var_name, new_content, shell));
	return (free(var_name), free(new_content), 1);
}

void	exec_export(char **args, t_shell *shell)
{
	int		i;
	char	*var_name;
	char	*content;
	int		append_f;

	if (args[1] == NULL)
		print_strarray(shell->export);
	else
	{
		i = 1;
		while (args[i] != NULL)
		{
			if (!_is_valid_argument(args[i]))
				print_error(NOT_A_VALID_IDENTIFIER, "export", args[i]);
			else if (_split_argument(args[i], &var_name, \
									&content, &append_f) == 0 || \
					_export_pwd_management(var_name, content, shell) == 0 || \
					add_to_export(var_name, content, append_f, shell) == 0 || \
					add_to_env(var_name, content, append_f, shell) == 0)
				break ;
			i++;
		}
	}
}
