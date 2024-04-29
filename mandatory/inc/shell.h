/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:53:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/29 13:30:18 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

typedef struct s_shell
{
	char	**env;
	char	**export;
	char	*pwd_save;
	char	*pwd;
	char	*oldpwd;
	int		stdin_fd_save;
	int		stdout_fd_save;
	int		fdin;
	int		fdout;
	int		exit_code;
	int		new_exit_code;
	int		is_exit;
}	t_shell;

t_shell	*get_shell(void);
t_shell	*init_shell(int as, char **av, char **ep);
void	free_shell(t_shell *shell);

int		contains_export(char *arg);
int		contains_env(char *arg);
char	*get_path_from_env(char *arg, char **envp);
char	*search_environment(char *arg);
char	*get_homepath(void);
int		manage_shlvl(void);

#endif