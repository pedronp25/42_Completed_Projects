CC = cc

SRCS = srcs/ft_putstr.c \
	srcs/ft_putchar.c \
	srcs/ft_strcmp.c \
	srcs/ft_strlen.c \
	srcs/ft_swap.c

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

NAME = libft.a

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) -Iincludes -c $< -o $@	
