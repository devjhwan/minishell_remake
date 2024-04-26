/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cd_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/26 17:33:44 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "libft.h"
#include "get_next_line.h"
#include "utils.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

static void	call_whoami(int p[2], t_shell *shell)
{
	dup2(p[1], STDOUT_FILENO);
	close(p[0]);
	close(p[1]);
	if (execve("/usr/bin/whoami", \
			(char *[]){"/usr/bin/whoami", NULL}, shell->env) < 0)
		shell->is_exit = 1;
}

static char	*get_username(t_shell *shell)
{
	char	*username;
	pid_t	pid;
	int		p[2];

	username = NULL;
	if (pipe(p) < 0)
		return (NULL);
	pid = fork();
	if (pid == 0)
		call_whoami(p, shell);
	else if (pid > 0)
	{
		username = (char *)malloc(sizeof(char) * 256);
		if (username == NULL)
			return (close(p[0]), close(p[1]), NULL);
		if (read(p[0], username, 256) < 0)
			return (close(p[0]), close(p[1]), free(username), NULL);
		waitpid(pid, &shell->exit_code, 0);
	}
	if (username != NULL)
		username[ft_strlen(username) - 1] = '\0';
	return (close(p[0]), close(p[1]), username);
}

static char	*get_userpasswd(int fd, t_shell *shell)
{
	char	*username;
	int		len;
	char	*line;

	username = get_username(shell);
	if (username == NULL)
		return (NULL);
	len = ft_strlen(username);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (ft_strncmp(line, username, len - 1) == 0 && \
			line[len] == ':')
			return (free(username), line);
		free(line);
		line = get_next_line(fd);
	}
	return (free(username), NULL);
}

char	*get_homepath(t_shell *shell)
{
	int		fd;
	char	*userpasswd;
	char	**split;
	char	*home;

	fd = open("/etc/passwd", O_RDONLY, 0644);
	if (fd < 0)
		return (NULL);
	userpasswd = get_userpasswd(fd, shell);
	if (userpasswd == NULL)
		return (close(fd), NULL);
	split = ft_split(userpasswd, ":");
	if (split == NULL)
		return (close(fd), free(userpasswd), NULL);
	home = ft_strdup(split[5]);
	return (close(fd), free(userpasswd), free_strarray(split), home);
}
