CC = cc -g 
AR = ar rcs
RM = rm -f

NAME = push_swap
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT_NAME = libft.a
LIBFT = $(LIBFT_DIR)/$(LIBFT_NAME)

PUSH_SWAP_SRCS = push_swap.c \
				 ps_exit.c \
				 check_init/ps_init_stacks.c \
				 check_init/ps_quicksort_intarr.c \
				 check_init/ps_validate_nums_01.c \
				 check_init/ps_validate_nums_02.c \
				 operations/ps_push.c \
				 operations/ps_reverse_rotate.c \
				 operations/ps_rotate.c \
				 operations/ps_swap.c \
				 smallstack_sort/ps_smallstack_sort.c \
				 smallstack_sort/ps_sort_x.c \
				 turk_algorithm/ps_calculate_cost.c \
				 turk_algorithm/ps_find_cheapest_node.c \
				 turk_algorithm/ps_move_cheapest_node.c \
				 turk_algorithm/ps_turk.c

PUSH_SWAP_OBJDIR = push_swap_objs
PUSH_SWAP_OBJS = $(PUSH_SWAP_OBJDIR)/$(PUSH_SWAP_SRCS:.c=.o)

DEPS = push_swap.h $(LIBFT_DIR)/libft.h

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(PUSH_SWAP_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(PUSH_SWAP_OBJS) $(LIBFT) -o $(NAME)

$(PUSH_SWAP_OBJDIR)/%.o: %.c $(DEPS)
	@mkdir -p $(PUSH_SWAP_OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(PUSH_SWAP_OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all
