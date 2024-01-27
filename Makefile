# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 11:32:37 by bberthod          #+#    #+#              #
#    Updated: 2023/02/20 12:56:08 by bberthod         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
CC			=	gcc
CFLAGS		=	-g -Wall -Wextra -Werror
RM			=	rm -f
HEADDIR		=	./includes/
SRCDIR		=	./srcs/
LIBDIR		=	./lib
LIBS		=	-lmlx -lXext -lX11 -lft

GREEN=\033[0;32m
RED=\033[0;31m
YELLOW=\033[0;43m
PINK=\033[0;35m
BLUE=\033[0;34m
END=\033[0m

SRCS		=	$(SRCDIR)ft_check_filemap.c \
				$(SRCDIR)ft_check_format.c \
				$(SRCDIR)ft_create_game.c \
				$(SRCDIR)ft_so_long.c \
				$(SRCDIR)ft_valid_path.c \
				$(SRCDIR)ft_move.c \
				$(SRCDIR)ft_free.c \
				$(SRCDIR)ft_handle_p.c \
				$(SRCDIR)ft_die_counter.c \


OBJS		=	$(SRCS:.c=.o)

%.o:		%.c
		@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(HEADDIR) -L$(LIBDIR)

$(NAME): $(OBJS)
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -I$(HEADDIR) -L$(LIBDIR) $(LIBS)
		@echo "	  $(GREEN)-- $(NAME) compiled --$(END) "

all:	$(NAME)


bonus:	$(NAME)

clean:
		@$(RM) $(OBJS)
		@echo "	$(PINK)--   All objects removed   --$(END) "

fclean:		clean
		@$(RM) $(NAME)
		@echo "	$(RED)-- All executables removed --$(END)"

scan:
		@echo "	$(PINK)-- Scan-build running --$(END) "
		@scan-build-12 make --no-print-directory
		@echo "	$(GREEN)--    Scan finished   --$(END) "

re:			fclean all

.PHONY:		all re clean fclean bonus scan
