CC = cc -g 
AR = ar rcs
RM = rm -rf

NAME = minishell
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT_NAME = libft.a
LIBFT = $(LIBFT_DIR)/$(LIBFT_NAME)

PARSER_SRCS = ms_parser/ms_tokenizer.c ms_parser/ms_token_manager.c ms_parser/ms_type_checker.c \
			  ms_parser/ms_error_handler.c ms_parser/ms_quote_handler.c ms_parser/ms_operator_utils.c \
			  ms_parser/ms_word_collector.c ms_parser/ms_quoted_string_handler.c \
			  ms_parser/ms_var_expander.c ms_parser/ms_redirect_segmenter.c \
			  ms_parser/ms_command_segmenter.c ms_parser/ms_char_handler.c ms_parser/ms_parser.c

BUILT_IN_SRCS = ms_built_in/ms_pwd.c ms_built_in/ms_echo.c ms_built_in/ms_env.c \
				ms_built_in/ms_exit.c ms_built_in/ms_unset.c ms_built_in/ms_helpers.c \
				ms_built_in/ms_export/ms_export.c ms_built_in/ms_export/ms_export_extract_info.c \
				ms_built_in/ms_export/ms_export_print_vars.c ms_built_in/ms_export/ms_export_update_vars.c \
				ms_built_in/ms_export/ms_export_helpers.c \
				ms_built_in/ms_cd/ms_cd.c ms_built_in/ms_cd/ms_cd_helpers.c ms_built_in/ms_cd/ms_cd_error.c

EXECUTOR_SRCS = ms_executor/ms_executor_main.c ms_executor/ms_executor_builtin.c ms_executor/ms_executor_external.c \
				ms_executor/ms_executor_env.c ms_executor/ms_executor_redirections.c ms_executor/ms_executor_pipeline.c \
				ms_executor/ms_executor_pipeline_utils.c ms_executor/ms_executor_heredoc.c ms_executor/ms_find_utils.c \
				ms_executor/ms_executor_heredoc_preprocess.c ms_executor/ms_executor_signals.c ms_executor/ms_executor_utils.c

MINISHELL_SRCS = $(PARSER_SRCS) \
				 $(BUILT_IN_SRCS) \
				 $(EXECUTOR_SRCS) \
				 ms_utils/ms_mem_manager.c \
				 minishell.c

MINISHELL_OBJDIR = minishell_objs
MINISHELL_OBJS = $(MINISHELL_SRCS:%.c=$(MINISHELL_OBJDIR)/%.o)

TEST_OBJDIR = test_objs
TEST_SRCS = tests/parser_test_runner.c \
			tests/unclose_quotes_tester.c \
			tests/operator_tester.c \
			tests/basic_tokenizer_tester.c \
			tests/complex_tokenizer_tester.c \
			tests/redirection_tester.c \
			tests/command_segment_tester.c \
			tests/argv_tester.c \
			tests/var_expansion_tester.c \
			utils/mem_manager.c \
			$(PARSER_SRCS) \
			$(BUILT_IN_SRCS)
TEST_OBJS = $(TEST_SRCS:%.c=$(TEST_OBJDIR)/%.o)

DEPS = minishell.h $(LIBFT_DIR)/libft.h

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)


$(NAME): $(MINISHELL_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(MINISHELL_OBJS) $(LIBFT) -o $(NAME) -lreadline
	clear
	@echo MeowShell Compiled!

$(MINISHELL_OBJDIR)/%.o: %.c $(DEPS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST_OBJDIR)/%.o: %.c $(DEPS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I. -c $< -o $@

test_runner: $(LIBFT) $(TEST_OBJS)
	$(CC) $(CFLAGS) $(TEST_OBJS) $(LIBFT) -lreadline -o $@

valgrind: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --error-limit=no \
	--verbose --log-file=valgrind_report.txt ./$(NAME)
	@echo Valgrind report saved to valgrind_report.txt

valgrind-suppress: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --error-limit=no \
	--suppressions=.valgrindrc ./$(NAME)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(MINISHELL_OBJS)
	$(RM) $(MINISHELL_OBJDIR)
	$(RM) $(TEST_OBJS)
	$(RM) $(TEST_OBJDIR)
	clear

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) minishell.o
	$(RM) $(NAME)
	$(RM) test_runner
	clear

re: clean fclean all

.PHONY: all clean fclean re test_runner valgrind valgrind-suppress
