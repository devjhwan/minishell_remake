/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:47:13 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/18 21:48:50 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMDS_H
# define CMDS_H

# include <stdlib.h>

enum e_redirType
{
	IN,
	OUT,
	IN2,
	OUT2
};

typedef struct s_redirs
{
	enum e_redirType	t;
	char				*file_name;
	struct s_redirs		*next;
}	t_redirs;

enum e_pipeType
{
	PIPE_T,
	AND_T,
	OR_T
};

typedef struct s_cmds
{
	enum e_pipeType	t;
	char			**args;
	t_redirs		*rd_arr;
	struct s_cmds	*next;
}	t_cmds;

t_cmds	*parse_command(char *arg, char **envp);
void	free_cmds(t_cmds *cmds);

#endif