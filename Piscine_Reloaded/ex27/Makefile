# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/06 19:39:35 by pedromig          #+#    #+#              #
#    Updated: 2025/04/06 23:02:42 by pedromig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

NAME = ft_display_file

SRC = display.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
