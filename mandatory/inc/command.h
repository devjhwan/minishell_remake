/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/22 00:33:36 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

typedef enum e_rdtype
{
	IN,
	OUT,
	IN2,
	OUT2
}	t_rdtype;

typedef struct s_redir
{
	t_rdtype		t;
	char			*filename;
	struct s_redir	*next;
}	t_redir;

typedef enum e_cmdtype
{
	P,
	ERR
}	t_cmdtype;

typedef struct s_cmd
{
	t_cmdtype		t;
	char			**args;
	t_redir			*redirs;
	struct s_cmd	*next;
}	t_cmd;

t_cmd		*create_new_cmd(t_cmdtype t);
t_cmdtype	get_cmd_type(char *arg);
void		free_redirections(t_redir *redir);
void		free_cmds(t_cmd **cmds);
void		print_command(t_cmd *cmds);

#endif
