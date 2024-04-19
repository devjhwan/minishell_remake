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

NAME=minishell

SRCDIR=./src
OBJDIR=objs
MAIN_SRC=main.c parse_command.c lexer.c append_token.c create_new_token.c \
		free_tokens.c get_last_token.c print_token_list.c clean_tokens.c \
		delete_token.c join_consecutive_tokens.c clean_tokens2.c \
		syntax_analyzer.c print_error.c check_missing_argument.c \
		check_missing_argument2.c expander.c expand_env.c expand_wildcard.c \
		search_env.c contains_in_env.c free_cmds.c parser.c set_redirections.c \
		set_arguments.c signal_handler.c terminal_setting.c expand_quotes.c

SRCS=$(MAIN_SRC)
OBJS=$(patsubst %.c, $(OBJDIR)/%.o, $(SRCS))
DEPS=$(OBJS:.o=.d)

INCLUDE=-I./inc -I./libft
CC=cc
DEBUG=-fsanitize="address,undefined" -g
CFLAGS=-Wall -Werror -Wextra
DEPFLAGS=-MMD
LIBFT=libft/libft.a
LDFLAGS=-L/home/linuxbrew/.linuxbrew/opt/readline/lib
CPPFLAGS=-I/home/linuxbrew/.linuxbrew/opt/readline/include
# LDFLAGS=-L${HOME}/homebrew/opt/readline/lib
# CPPFLAGS=-I${HOME}/homebrew/opt/readline/include

all: $(OBJDIR) libft $(NAME)

$(NAME): $(OBJS) $(LIBFT) Makefile
	$(CC) $(DEBUG) $(CFLAGS) -o $@ $(OBJS) $(LIBFT) -lreadline $(LDFLAGS)
	echo "(MINISHELL) COMPILING $@"
	
$(OBJDIR)/%.o: $(SRCDIR)/%.c $(LIBFT) Makefile
	$(CC) $(DEBUG) $(DEPFLAGS) $(CFLAGS) $(INCLUDE) -c -o $@ $< $(CPPFLAGS)
	echo "(MINISHELL) COMPILING $@"
	
$(OBJDIR)/%.o: $(SRCDIR)/**/%.c $(LIBFT) Makefile
	$(CC) $(DEBUG) $(DEPFLAGS) $(CFLAGS) $(INCLUDE) -c -o $@ $< $(CPPFLAGS)
	echo "(MINISHELL) COMPILING $@"
	
$(OBJDIR)/%.o: $(SRCDIR)/**/**/%.c $(LIBFT) Makefile
	$(CC) $(DEBUG) $(DEPFLAGS) $(CFLAGS) $(INCLUDE) -c -o $@ $< $(CPPFLAGS)
	echo "(MINISHELL) COMPILING $@"

$(OBJDIR): Makefile
	mkdir -p $@

libft:
	make -C libft

clean:
	make -C libft fclean
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re libft
.SILENT:
