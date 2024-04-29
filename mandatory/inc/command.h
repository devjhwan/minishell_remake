/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/29 14:17:16 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include "redirection.h"

typedef enum e_cmdtype
{
	PIPE_CMD,
	SINGLE_CMD
}	t_cmdtype;

typedef struct s_cmd
{
	t_cmdtype		t;
	char			**args;
	t_redir			*redirs;
}	t_cmd;

t_cmd		*create_new_cmd(t_cmdtype t);
t_cmdtype	get_cmd_type(char *arg);
char		*get_cmd_enum_name(t_cmdtype t);
void		free_cmd(t_cmd *cmds);
void		print_command(t_cmd *cmds);

#endif
