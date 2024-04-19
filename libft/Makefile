# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/03 14:32:42 by junghwle          #+#    #+#              #
#    Updated: 2024/04/19 17:36:43 by junghwle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=libft.a

SRCDIR			:=.
OBJDIR			:=.objs
SRCS			:=ft_bzero.c ft_memset.c ft_calloc.c ft_split.c ft_strchr.c \
				  ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
				  ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
				  ft_strtrim.c ft_substr.c ft_putstr.c
OBJS			:=$(patsubst %.c, $(OBJDIR)/%.o, $(SRCS))
DEPS			:=$(OBJS:.o=.d)

INCLUDE			:=-I.
AR				:=ar rcs
CC				:=cc
CFLAGS			:=-Wall -Werror -Wextra
DEPFLAGS		:=-MMD
COMPILE.c		:=$(CC) $(DEPFLAGS) $(CFLAGS) $(INCLUDE) -c -o

all: 			$(OBJDIR) $(NAME)

$(NAME): 		$(OBJS) Makefile
					$(AR) $@ $(OBJS)
					echo "(LIBFT) COMPILING $@"

$(OBJDIR)/%.o: 	$(SRCDIR)/%.c Makefile 
					$(COMPILE.c) $@ $<
					echo "(LIBFT) COMPILING $@"

$(OBJDIR): 		Makefile
					mkdir -p $@

clean:
					rm -rf $(OBJDIR)

fclean: 		clean
					rm -f $(NAME)

re: 			fclean all

-include $(DEPS)

.PHONY: 		all clean fclean re
.SILENT:
