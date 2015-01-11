#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdrissi <mdrissi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/04/27 19:25:15 by mdrissi           #+#    #+#              #
#    Updated: 2015/01/11 06:30:41 by mdrissi          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = g++ -lcurses
CCFLAGS =  -Wall -Wextra -Werror

NAME = ft_retro
OBJ = Ennemy.o Obstacle.o Player.o Tir.o \
	gameEntity.class.o gameManager.class.o main.o

SRCS =  $(OBJ:.o=.cpp)
OBJS = $(OBJ)

all: $(NAME)


$(NAME): $(OBJS)
	$(CC) $(CCFLAGS) -o $(NAME) $(SRCS)

%.o: %.cpp
	$(CC) $(CCFLAGS) -o $(@) -c $(^)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
