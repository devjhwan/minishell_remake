# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/03 14:32:42 by junghwle          #+#    #+#              #
#    Updated: 2024/04/29 14:30:12 by junghwle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=minishell

SRCDIR			:=./mandatory/src

MAIN_SRCS		:=main.c signal_handler.c terminal_setting.c 
SHELL_SRCS		:=contains_env.c get_shell.c get_path_from_env.c \
				  manage_shlvl.c get_homepath.c contains_export.c \
				  search_environment.c init_shell.c free_shell.c
PARSER_SRCS		:=lexer.c syntax_analyzer.c parser.c
TOKEN_SRCS		:=create_new_token.c substr_argument1.c substr_argument2.c \
				  free_tokens.c push_back_token.c append_token.c \
				  check_token1.c check_token2.c print_tokens.c \
				  get_next_command_tokens.c
COMMAND_SRCS	:=create_new_cmd.c get_cmd_type.c print_cmds.c free_cmd.c \
				  get_cmd_enum_name.c
RD_SRCS			:=get_redir_enum_name.c get_redir_type.c free_redirections.c \
				  check_redirs.c
EXECUTOR_SRCS	:=execute.c create_new_executor.c print_executor.c \
				  free_executor.c set_exec_redirections.c
BUILTIN_SRCS	:=exec_export.c exec_export_utils.c exec_exit.c exec_cd.c \
				  exec_echo.c exec_pwd.c exec_unset.c exec_env.c exec_cd_utils.c \
				  execute_builtin.c
UTILS_SRCS		:=free_strarray.c print_strarray.c print_error.c isdir.c \
				  isbuiltin.c copy_strarray.c remove_quote.c
				  
SRCS			:=$(MAIN_SRCS) $(SHELL_SRCS) $(PARSER_SRCS) $(TOKEN_SRCS) \
				  $(COMMAND_SRCS) $(RD_SRCS) $(EXECUTOR_SRCS) $(BUILTIN_SRCS) \
				  $(UTILS_SRCS)

OBJDIR			:=.objs
OBJS			:=$(patsubst %.c, $(OBJDIR)/%.o, $(SRCS))

DEPS			:=$(OBJS:.o=.d)
DEPFLAGS		:=-MMD

INC				:=-I./mandatory/inc -I./libft -I./libft/gnl
CC				:=cc
CFLAGS			:=-Wall -Werror -Wextra

DEBUG			:=-fsanitize="address,undefined" -g

LDFLAGS			:=-L/home/linuxbrew/.linuxbrew/opt/readline/lib
CPPFLAGS		:=-I/home/linuxbrew/.linuxbrew/opt/readline/include
# LDFLAGS			:=-L${HOME}/homebrew/opt/readline/lib
# CPPFLAGS		:=-I${HOME}/homebrew/opt/readline/include

LIBS			:=libft/libft.a libft/gnl/gnl.a

all: 			$(OBJDIR) libft $(NAME)

$(NAME): 		$(OBJS) $(LIBS) Makefile
					$(CC) $(DEBUG) $(CFLAGS) -o $@ $(OBJS) $(LIBS) \
						-lreadline $(LDFLAGS)
					echo "(MINISHELL) COMPILING $@"

$(OBJDIR)/%.o: 	$(SRCDIR)/%.c $(LIBS) Makefile
					$(CC) $(DEBUG) $(DEPFLAGS) $(CFLAGS) $(INC) -c -o $@ $< $(CPPFLAGS)
					echo "(MINISHELL) COMPILING $@"

$(OBJDIR)/%.o: 	$(SRCDIR)/**/%.c $(LIBS) Makefile
					$(CC) $(DEBUG) $(DEPFLAGS) $(CFLAGS) $(INC) -c -o $@ $< $(CPPFLAGS)
					echo "(MINISHELL) COMPILING $@"

$(OBJDIR)/%.o: 	$(SRCDIR)/**/**/%.c $(LIBS) Makefile
					$(CC) $(DEBUG) $(DEPFLAGS) $(CFLAGS) $(INC) -c -o $@ $< $(CPPFLAGS)
					echo "(MINISHELL) COMPILING $@"

$(OBJDIR): 		Makefile
					mkdir -p $@

libft:
					make -C libft
					make -C libft/gnl

clean:
					make -C libft fclean
					make -C libft/gnl fclean
					rm -rf $(OBJDIR)

fclean: clean
					rm -f $(NAME)

re: 				fclean all

-include $(DEPS)

.PHONY: 			all clean fclean re libft
.SILENT:
