/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-te <mjoao-te@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 16:25:11 by mjoao-te          #+#    #+#             */
/*   Updated: 2026/01/02 16:25:14 by mjoao-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_PARSER_H
# define MS_PARSER_H

# include "../libft/libft.h"

typedef struct s_env_list	t_env_list;

typedef enum e_token_type
{
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_REDIR_IN,
	TOKEN_REDIR_OUT,
	TOKEN_REDIR_APPEND,
	TOKEN_REDIR_HEREDOC,
	TOKEN_SQUOTE,
	TOKEN_DQUOTE,
	TOKEN_ENV_VAR,
	TOKEN_EXIT_STATUS,
	TOKEN_WHITESPACE,
	TOKEN_EOF
}	t_token_type;

typedef enum e_quote_state
{
	NO_QUOTE,
	IN_SINGLE_QUOTE,
	IN_DOUBLE_QUOTE
}	t_quote_state;

typedef enum e_parse_error
{
	ERR_NONE,
	ERR_UNCLOSED_QUOTE,
	ERR_INVALID_PIPE,
	ERR_INVALID_REDIRECT,
	ERR_SYNTAX,
	ERR_MALLOC
}	t_parse_error;

typedef struct s_token
{
	t_token_type		type;
	char				*value;
	struct s_token		*next;
}	t_token;

typedef struct s_redirect
{
	t_token_type		type;
	char				*file;
	int					fd;
	struct s_redirect	*next;
}	t_redirect;

typedef struct s_command
{
	char				**args;
	t_redirect			*redirects;
	struct s_command	*next;
}	t_command;

typedef struct s_command_table
{
	t_command	*commands;
	int			commands_count;
	int			pipes_count;
}	t_command_table;

t_token_type	identify_operator(char *str, int *i);
char			*get_exit_status_as_str(int last_exit_status);

char			**convert_to_argv(t_list *args);
t_command_table	*run_parser(char *inp, t_env_list *env, int lst_ex);

t_token			*tokenize(char *inp, t_env_list *env, int lst_ex);
t_token			*create_token(t_token_type type, char *value);
void			add_token(t_token **head, t_token *new);
void			free_tokens(t_token *tokens);
char			*join_and_free(char *base, const char *tail, size_t len);
void			append_operator_token(t_token **tokens, char *inp, int *i);

t_quote_state	update_quote_state(char c, t_quote_state current);
char			*extract_quoted_string(char *str, int *i, char quote);
int				has_unclosed_quotes(char *inp);

int				is_quote(char c);
int				is_operator(char c);
int				is_redirect(t_token_type type);
int				is_pipe(t_token_type type);
int				is_valid_command_sequence(t_token *tokens);

char			*collect_word(char *inp, int *i, t_env_list *env, int lst_ex);
char			*handle_regular_char(char *inp, int *i);
char			*handle_dollar_char(char *inp, int *i, t_env_list *env, int ex);
char			*handle_quote_char(char *inp, int *i, t_env_list *env, int ex);

char			*expand_env_var(char *inp, int *i, t_env_list *env, int lst_ex);

void			append_redirect(t_redirect **head, t_redirect *new_redir);
t_redirect		*parse_redirection(t_token **tokens);

void			append_command(t_command **head, t_command *new_cmd);
void			parse_command_segment(t_token **tokens, t_command *cmd);

int				validate_tokens_syntax(t_token *tokens);
void			print_parse_error(t_parse_error err, char *context);
void			ms_error(char *error_msg);

void			free_argv(char **argv);
void			free_redirects(t_redirect *redir);
void			free_command(t_command *cmd);
void			free_command_table(t_command_table *table);

#endif
