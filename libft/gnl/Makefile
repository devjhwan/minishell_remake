# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/03 14:32:42 by junghwle          #+#    #+#              #
#    Updated: 2024/04/22 11:06:40 by junghwle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=gnl.a

SRCDIR			:=.
OBJDIR			:=.objs
SRCS			:=get_next_line.c get_next_line_utils.c
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
					echo "(GNL) COMPILING $@"

$(OBJDIR)/%.o: 	$(SRCDIR)/%.c Makefile 
					$(COMPILE.c) $@ $<
					echo "(GNL) COMPILING $@"

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
