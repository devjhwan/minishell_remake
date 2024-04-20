/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/20 05:02:09 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "command.h"
# include <stdio.h>

typedef struct s_arglist
{
	char				*arg;
	struct s_arglist	*next;
}	t_arglist;

t_cmd	*parser(char *arg, char **envp);

int		is_redir(char *arg);
int		is_pipe(char *arg);
int		is_arg(char *line);
char	*remove_quote(char *arg);
int		count_arg_length(char *arg);
int		set_redir(char **line, t_cmd *cmd, char **envp);
char	**set_argument(t_arglist *arglist);
int		add_argument(t_arglist **args, char **arg, char **envp);
void	free_arguments(t_arglist **args);
char	*expand_env(char *arg, char **envp);

#endif