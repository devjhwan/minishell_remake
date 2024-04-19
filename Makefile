# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/03 14:32:42 by junghwle          #+#    #+#              #
#    Updated: 2024/04/18 21:42:47 by junghwle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=minishell

SRCDIR			:=./src
SRCS			:=main.c

OBJDIR			:=.objs
OBJS			:=$(patsubst %.c, $(OBJDIR)/%.o, $(SRCS))

DEPS			:=$(OBJS:.o=.d)
DEPFLAGS		:=-MMD

INCLUDE			:=-I./inc -I./libft
CC				:=cc
CFLAGS			:=-Wall -Werror -Wextra

DEBUG			:=-fsanitize="address,undefined" -g

LDFLAGS			:=-L/home/linuxbrew/.linuxbrew/opt/readline/lib
CPPFLAGS		:=-I/home/linuxbrew/.linuxbrew/opt/readline/include
# LDFLAGS			:=-L${HOME}/homebrew/opt/readline/lib
# CPPFLAGS		:=-I${HOME}/homebrew/opt/readline/include

LIBFT			:=libft/libft.a

all: 			$(OBJDIR) libft $(NAME)

$(NAME): 		$(OBJS) $(LIBFT) Makefile
					$(CC) $(DEBUG) $(CFLAGS) -o $@ $(OBJS) $(LIBFT) \
						-lreadline $(LDFLAGS)
					echo "(MINISHELL) COMPILING $@"

$(OBJDIR)/%.o: 	$(SRCDIR)/%.c $(LIBFT) Makefile
					$(CC) $(DEBUG) $(DEPFLAGS) $(CFLAGS) $(INCLUDE) -c -o $@ $< $(CPPFLAGS)
					echo "(MINISHELL) COMPILING $@"

$(OBJDIR): 		Makefile
					mkdir -p $@

libft:
					make -C libft

clean:
					make -C libft fclean
					rm -rf $(OBJDIR)

fclean: clean
					rm -f $(NAME)

re: 				fclean all

-include $(DEPS)

.PHONY: 			all clean fclean re libft
.SILENT:
