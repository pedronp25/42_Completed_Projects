CC = cc
CFLAGS = -Wall -Werror -Wextra

NAME = philo

SRCS = philosophers.c \
	   ph_init_validate.c \
	   ph_threads.c \
	   ph_actions.c \
	   ph_helpers/ph_helpers1.c \
	   ph_helpers/ph_helpers2.c \
	   ph_helpers/ph_helpers3.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
