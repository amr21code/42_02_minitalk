# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anruland <anruland@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/09 19:17:00 by amr21code         #+#    #+#              #
#    Updated: 2022/04/26 22:29:48 by anruland         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Config

NAME 	= minitalk
CC 		= gcc
CFLAGS	= -Werror -Wall -Wextra

COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m

# Server Files

INCLUDE_SRV	= ./src_server
INCLUDE_CLN	= ./src_client
SRC_SRV		= ft_minitalk_server.c
SRC_CLN		= ft_minitalk_client.c
#OBJ_SRV		= ${SRC_SRV:$(FILE_EXTENSION)=.o}

all: $(NAME)

$(NAME): printf
	@echo "$(COM_COLOR)Compiling Server$(NO_COLOR)"
	@$(CC) $(CFLAGS) $(SRC_SRV) -o server -L. -lprintf -lft
	@echo "$(COM_COLOR)Compiling Client$(NO_COLOR)"
	@$(CC) $(CFLAGS) $(SRC_CLN) -o client -L. -lprintf -lft

# libft:
	@echo "$(COM_COLOR)Compiling LibFT$(NO_COLOR)"
# 	@cd ./libft/ && make re
# 	@cp ./libft.a ../ft_printf/libftprintf.a
# 	@cd ..
	@cp ./libft/libft.a ./libft.a
	@echo "$(OK_COLOR)done$(NO_COLOR)"

printf: #libft
	@echo "$(COM_COLOR)Compiling ft_printf$(NO_COLOR)"
	@cd ./libprintf/ && make re
	@cd ..
	@cp ./libprintf/libftprintf.a ./libprintf.a
	@echo "$(OK_COLOR)done$(NO_COLOR)"

clean:
	@echo "$(COM_COLOR)Cleaning Object Files$(NO_COLOR)"
	@/bin/rm -f

fclean: clean
	@echo "$(COM_COLOR)Cleaning $(NAME)$(NO_COLOR)"
	@/bin/rm -f $(NAME)

# aclean: fclean
# 	@echo "$(COM_COLOR)Cleaning LibFT$(NO_COLOR)"
# 	@cd ./libft/ && make fclean
# 	@cd ..
# 	@echo "$(COM_COLOR)Cleaning ft_printf$(NO_COLOR)"
# 	@cd ./ft_printf/ && make fclean
# 	@cd ..

re: fclean all
