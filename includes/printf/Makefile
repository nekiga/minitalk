# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 16:17:42 by garibeir          #+#    #+#              #
#    Updated: 2023/09/10 11:42:24 by garibeir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
SRC = ft_printf sources aux unsigned
CFLAGS = -Wextra -Wall -Werror
NAME = printf.a

all: $(NAME)

$(NAME): $(SRC:=.o)
	ar rcs $(NAME) $(SRC:=.o)

clean:
	rm -f $(SRC:=.o)
fclean:
	rm -f $(SRC:=.o) $(NAME)

re: fclean all

