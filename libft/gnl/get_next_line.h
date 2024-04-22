/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 19:55:54 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/22 11:05:39 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_buff
{
	char			*b;
	ssize_t			curlen;
	ssize_t			maxlen;
	ssize_t			lasti;
	int				fd;
	struct s_buff	*next;
}	t_buff;

char	*get_next_line(int fd);

t_buff	*ft_setbuffer(t_buff **blist, int fd);
void	*ft_realloc(void *p, size_t oldsize, size_t newsize);
void	*ft_freebuffer(t_buff **blist, int fd);

#endif