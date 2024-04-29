/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:53:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/29 11:51:50 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

void	exec_echo(char **args);
void	exec_env(char **args);
void	exec_export(char **args);
void	exec_exit(char **args);
void	exec_unset(char **args);
void	exec_pwd(void);
void	exec_cd(char **args);
void	execute_builtin(char **args);

#endif