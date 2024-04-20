# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/03 14:32:42 by junghwle          #+#    #+#              #
#    Updated: 2024/04/20 03:22:07 by junghwle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=minishell

SRCDIR			:=./mandatory/src
SRCS			:=main.c parser.c new_cmd.c get_cmd_type.c free_cmds.c \
				  is_pipe.c is_redir.c add_argument.c count_arg_length.c \
				  free_arguments.c set_argument.c set_redir.c print_command.c \
				  print_error.c is_arg.c

OBJDIR			:=.objs
OBJS			:=$(patsubst %.c, $(OBJDIR)/%.o, $(SRCS))

DEPS			:=$(OBJS:.o=.d)
DEPFLAGS		:=-MMD

INC				:=-I./mandatory/inc -I./libft
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
					$(CC) $(DEBUG) $(DEPFLAGS) $(CFLAGS) $(INC) -c -o $@ $< $(CPPFLAGS)
					echo "(MINISHELL) COMPILING $@"

$(OBJDIR)/%.o: 	$(SRCDIR)/**/%.c $(LIBFT) Makefile
					$(CC) $(DEBUG) $(DEPFLAGS) $(CFLAGS) $(INC) -c -o $@ $< $(CPPFLAGS)
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
