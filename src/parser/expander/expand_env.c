/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:11:10 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/18 21:33:11 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "utils.h"
#include <stdlib.h>

static int	is_prev_heredoc(t_token *tokens)
{
	while (tokens != NULL)
	{
		if (tokens->t == RD && ft_strncmp(tokens->arg, "<<", 3) == 0)
			return (1);
		tokens = tokens->prev;
	}
	return (0);
}

static int	is_prev_redir(t_token *tokens)
{
	tokens = tokens->prev;
	while (tokens != NULL && tokens->t == BK)
		tokens = tokens->prev;
	return (tokens != NULL && tokens->t == RD);
}

static int	expand_dq_env(t_token *tokens, char **envp)
{
	char	*env;
	int		env_len;
	char	*result;
	char	*tmp;

	env = ft_strchr(tokens->arg, '$');
	env_len = 1;
	while (ft_strchr("$\" ", env[env_len]) == NULL)
		env_len++;
	result = ft_substr(tokens->arg, 0, env - tokens->arg);
	env = ft_substr(env, 0, env_len);
	if (result == NULL || env == NULL)
		return (free(result), free(env), 0);
	tmp = env;
	env = search_env(env + 1, envp);
	if (env == NULL)
		return (free(tmp), 0);
	free(tmp);
	tmp = result;
	result = ft_strjoin(3, result, env, ft_strchr(tokens->arg, '$') + env_len);
	if (result == NULL)
		return (free(tmp), free(env), 0);
	free(tokens->arg);
	tokens->arg = result;
	return (free(tmp), free(env), 1);
}

int	expand_env(t_token *tokens, char **envp)
{
	char	*tmp;

	tmp = NULL;
	if (is_prev_heredoc(tokens))
		return (1);
	if (tokens->t == ENV)
	{
		if (is_prev_redir(tokens) && !contains_in_env(tokens->arg + 1, envp))
			return (print_error(AMBIGUOUS_REDIRECT, tokens->arg, NULL), 0);
		tmp = tokens->arg;
		tokens->arg = search_env(tmp + 1, envp);
		free(tmp);
		if (tokens->arg == NULL)
			return (0);
		tokens->t = ARG;
	}
	if (tokens->t == DQ)
	{
		while (ft_strchr(tokens->arg, '$') != NULL)
			if (expand_dq_env(tokens, envp) == 0)
				return (0);
	}
	return (1);
}
