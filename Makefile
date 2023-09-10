# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/01 16:48:14 by garibeir          #+#    #+#              #
#    Updated: 2023/09/10 11:40:06 by garibeir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#----- Program name:
CLIENT	= Client
SERVER	= Server
COMMON	=  Common

#---- Compilation:
CC = cc
CFLAGS = -g -Wall -Werror -Wextra -fsanitize=address

#----- Printf:
FT_PRINTF_PATH	= ./includes/printf 
FT_PRINTF_NAME	= ./includes/printf/printf.a

#----- libft:
FT_LIBFT_PATH	= ./includes/libft
FT_LIBFT_NAME	= ./includes/libft/libft.a


#----- Colors:
DEFAULT = \033[0;92m


#----- Files:
SRC_CLIENT	=  ./srcs/client.c \

SRC_SERVER	=  ./srcs/server.c \

SRC_COMMON	= ./srcs/minitalk.c \

OBJ_CLIENT	= $(SRC_CLIENT:.c=.o)
OBJ_SERVER	= $(SRC_SERVER:.c=.o)
OBJ_COMMON	= $(SRC_COMMON:.c=.o)

all: $(COMMON) $(CLIENT) $(SERVER) 

$(COMMON): $(OBJ_COMMON)
	@echo "$(DEFAULT)\tBuilding project...\n"
	@echo "$(DEFAULT)\tCompiling Printf...\n"
	make -s -C $(FT_PRINTF_PATH)
	@echo "$(DEFAULT)\tDone Compiling.\n"
	@echo "$(DEFAULT)\tCompiling libft...\n"
	make -s -C $(FT_LIBFT_PATH)
	@echo "$(DEFAULT)\tDone Compiling.\n"

$(CLIENT):	$(OBJ_CLIENT) 

		@echo "$(DEFAULT)\tBuilding Client...\n"
		$(CC) $(CFLAGS) $(OBJ_CLIENT) $(OBJ_COMMON) $(FT_PRINTF_NAME) $(FT_LIBFT_NAME) -O3 -o $(CLIENT)
		mkdir objects_client && mv $(OBJ_CLIENT) objects_client
		@clear
		@echo "$(DEFAULT)\tDone Compiling Client.\n"

$(SERVER): $(OBJ_SERVER)
		@echo "$(DEFAULT)\tBuilding Server...\n"
		$(CC) $(CFLAGS) $(OBJ_SERVER) $(OBJ_COMMON) $(FT_PRINTF_NAME) $(FT_LIBFT_NAME) -O3 -o $(SERVER)
		mkdir objects_server && mv $(OBJ_SERVER) objects_server
		mkdir objects_common && mv $(OBJ_COMMON) objects_common
		@clear
		@echo "$(DEFAULT)\tDone Compiling Server.\n"
		@echo "$(DEFAULT)\tFinished project build.\n"
clean:
		@rm -rf objects_server
		@rm -rf objects_client
		@rm -rf objects_common
		make clean -s -C $(FT_PRINTF_PATH)
		make clean -s -C $(FT_LIBFT_PATH) 
		@echo "$(DEFAULT)\tDone cleaning.\n"

fclean:		clean
			$(RM) $(CLIENT) $(SERVER) $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_COMMON)
			make -s fclean -C $(FT_PRINTF_PATH)
			make -s fclean -C $(FT_LIBFT_PATH) 
			@echo "$(DEFAULT)\tDone function cleaning.\n"

re: fclean all

test:
		./fdf basictest.fdf

	
		