# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/09 19:17:00 by amr21code         #+#    #+#              #
#    Updated: 2022/05/05 15:56:30 by anruland         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Config
NAME 	= minitalk
CC 		= gcc
CFLAGS	= -Werror -Wall -Wextra
LIBS	= -L./libft/ -lft

COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m

# Files
INCLUDE_SRV	= ./src_server
INCLUDE_CLN	= ./src_client
SRC_SRV		= ft_minitalk_server.c
SRC_CLN		= ft_minitalk_client.c

# Rules
all: $(NAME)

$(NAME): libft
	@echo "$(COM_COLOR)Compiling Server$(NO_COLOR)"
	@$(CC) $(CFLAGS) $(SRC_SRV) -o server $(LIBS)
	@echo "$(COM_COLOR)Compiling Client$(NO_COLOR)"
	@$(CC) $(CFLAGS) $(SRC_CLN) -o client $(LIBS)

libft:
	@echo "$(COM_COLOR)Compiling LibFT$(NO_COLOR)"
	@$(MAKE) -C ./libft
	@echo "$(OK_COLOR)done$(NO_COLOR)"

clean:
	@echo "$(COM_COLOR)Cleaning Object Files$(NO_COLOR)"
	@$(MAKE) -C ./libft clean

fclean: clean
	@echo "$(COM_COLOR)Cleaning all $(NO_COLOR)"
	@/bin/rm -f server
	@/bin/rm -f client
	@$(MAKE) -C ./libft fclean

re: fclean all

.PHONY: libft clean fclean re $(NAME) all