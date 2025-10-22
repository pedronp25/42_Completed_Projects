CC = cc
AR = ar rcs
RM = rm -f

NAME = pipex
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT_NAME = libft_printf.a
LIBFT = $(LIBFT_DIR)/$(LIBFT_NAME)

PIPEX_SRCS = pipex.c pipex_utils.c pipex_error_utils.c

PIPEX_OBJDIR = pipex_objs
PIPEX_OBJS = $(PIPEX_SRCS:%.c=$(PIPEX_OBJDIR)/%.o)

DEPS = pipex.h $(LIBFT_DIR)/libft.h

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(PIPEX_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(PIPEX_OBJS) $(LIBFT) -o $(NAME)

$(PIPEX_OBJDIR)/%.o: %.c $(DEPS)
	@mkdir -p $(PIPEX_OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(PIPEX_OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all
