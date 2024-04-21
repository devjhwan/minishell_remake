# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/03 14:32:42 by junghwle          #+#    #+#              #
#    Updated: 2024/04/22 00:50:07 by junghwle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=minishell

SRCDIR			:=./mandatory/src

MAIN_SRCS		:=main.c
COMMAND_SRCS	:=create_new_cmd.c free_cmds.c free_redirections.c \
				  get_cmd_type.c print_cmds.c
EXPANDER_SRCS	:=expand_dquote_env.c expand_node.c expand_singular_env.c
PARSER_SRCS		:=lexer.c parser.c syntax_analyzer.c expander.c
P_TOKEN_SRCS	:=append_token.c check_token1.c check_token2.c \
				  create_new_token.c free_tokens.c print_tokens.c \
				  push_back_token.c substr_argument1.c substr_argument2.c 
P_TREE_SRCS		:=create_parser_tree.c create_new_node.c free_tree.c \
				  print_parser_tree.c skip_space_tokens.c parse_command.c \
				  parse_content.c parse_argument.c parse_redirection.c
UTILS_SRCS		:=free_strarr.c print_error.c remove_quote.c \
				  search_environment.c check_environment.c
				  
SRCS			:=$(MAIN_SRCS) $(COMMAND_SRCS) $(EXPANDER_SRCS) \
				  $(PARSER_SRCS) $(P_TOKEN_SRCS) $(P_TREE_SRCS) \
				  $(UTILS_SRCS)

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
