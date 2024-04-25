/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/25 22:44:12 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "utils.h"
#include "libft.h"

int		is_valid_argument(char *arg);
char	*create_new_export_arg(char *var_name, char *content);
int		split_argument(char *arg, char **var_name, \
						char **content, int *append_f);
int		contains_export(char *arg, char **strarr);

int	append_to_export(char *var_name, char *new_content, t_shell *shell)
{
	char	*new_arg;
	int		count;
	char	**tmp;
	
	new_arg = create_new_export_arg(var_name, new_content);
	if (new_arg == NULL)
		return (free(var_name), free(new_content), 0);
	count = 0;
	while (shell->export[count] != NULL)
		count++;
	tmp = (char **)malloc(sizeof(char *) * (count + 2));
	if (tmp == NULL)
		return (free(new_arg), free(var_name), free(new_content),  0);
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

int	add_to_env(char *var_name, char *new_content, \
					int append_f, t_shell *shell)
{
	(void) append_f;
	(void) shell;
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
			if (is_valid_argument(args[i]))
			{
				if (split_argument(args[i], &var_name, &content, &append_f) == 0 || \
					add_to_export(var_name, content, append_f, shell) == 0 || \
					add_to_env(var_name, content, append_f, shell) == 0)
					break ;
			}
			i++;
		}
	}
}
