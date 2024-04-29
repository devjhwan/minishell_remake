/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/29 12:53:30 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_H
# define REDIRECTION_H

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

int			check_redirs(t_redir *redir);
t_rdtype	get_redir_type(char *arg);
char		*get_redir_enum_name(t_rdtype t);
void		free_redirections(t_redir *redir);

#endif