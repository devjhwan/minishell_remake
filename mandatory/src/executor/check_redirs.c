/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:50:44 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/26 00:14:16 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "libft.h"
#include "get_next_line.h"
#include "utils.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

static int	check_file_in(char *filename)
{
	if (access(filename, F_OK) != 0)
		return (print_error(NO_FILE, filename, NULL), 0);
	if (access(filename, R_OK) != 0)
		return (print_error(PERMISSION_DENIED, filename, NULL), 0);
	return (1);
}

static int	check_file_heredoc(char *endstr)
{
	int		fd;
	char	*buffer;
	size_t	endstr_len;

	fd = creat(".heredoc", 0644);
	if (fd >= 0)
	{
		endstr_len = ft_strlen(endstr);
		write(STDIN_FILENO, "> ", 2);
		buffer = get_next_line(STDIN_FILENO);
		while (buffer != NULL && \
				(ft_strncmp(buffer, endstr, endstr_len) != 0 || \
				buffer[endstr_len] != '\n'))
		{
			if (write(fd, buffer, ft_strlen(buffer)) < 0)
				return (close(fd), 0);
			free(buffer);
			write(STDIN_FILENO, "> ", 2);
			buffer = get_next_line(STDIN_FILENO);
		}
		return (free(buffer), close(fd), 1);
	}
	else
		return (0);
}

static int	check_file_out(char *filename)
{
	int	fd;

	fd = creat(filename, 0664);
	if (fd < 0)
	{
		if (errno == EACCES)
			return (print_error(PERMISSION_DENIED, filename, NULL), 0);
		else if (errno == EISDIR)
			return (print_error(IS_DIRECTORY, filename, NULL), 0);
		return (0);
	}
	else
		return (close(fd), 1);
}

static int	check_file_out_append(char *filename)
{
	int			fd;
	struct stat	path_stat;

	if (access(filename, F_OK) != 0)
	{
		stat(filename, &path_stat);
		if (!S_ISREG(path_stat.st_mode))
			return (print_error(IS_DIRECTORY, filename, NULL), 0);
		else if (access(filename, W_OK) != 0)
			return (print_error(PERMISSION_DENIED, filename, NULL), 0);
		return (1);
	}
	fd = creat(filename, 0664);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

int	_check_redirs(t_redir *redir)
{
	if (redir->t == IN && check_file_in(redir->filename) == 0)
		return (0);
	else if (redir->t == IN2)
	{
		if (check_file_heredoc(redir->filename) == 0)
			return (0);
		free(redir->filename);
		redir->filename = ft_strdup(".heredoc");
		if (redir->filename == NULL)
			return (0);
	}
	else if (redir->t == OUT && check_file_out(redir->filename) == 0)
		return (0);
	else if (redir->t == OUT2 && check_file_out_append(redir->filename) == 0)
		return (0);
	if (redir->next != NULL)
		return (_check_redirs(redir->next));
	return (1);
}
