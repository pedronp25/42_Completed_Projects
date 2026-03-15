/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 23:19:16 by pedromig          #+#    #+#             */
/*   Updated: 2026/01/18 13:57:58 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define SUCCESS 0
# define ERROR -1

# define RED "\x1b[31m"
# define BLUE "\x1b[34m"
# define WHITE "\x1b[37m"

# define WHITESPACE " \f\n\r\t\v"

# include <stdio.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <limits.h>
# include <signal.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <string.h>

# include "ms_executor/ms_executor.h"

# include "libft/libft.h"
# include "ms_parser/ms_parser.h"

typedef enum e_exit_arg_error
{
	NO_ARGS = 101,
	NORMAL_ARGS = 102,
	TOO_MANY_ARGS = 1,
	NOT_NUMERIC = 2
}	t_exit_error;

typedef enum e_export_mode
{
	MODE_NO_VALUE,
	MODE_REPLACE,
	MODE_APPEND
}	t_export_mode;

typedef struct s_env_list
{
	char				*content;
	bool				exported;
	struct s_env_list	*next;
}	t_env_list;

typedef struct s_ms
{
	t_env_list		*env_vars;
	t_command_table	*command_table;
	int				exit_status;
	int				is_interactive;
	int				in_child;
}	t_ms;

// ms_input_handling.c
char		*ms_get_input(void);

// ms_builtin_implementations.c
int			ms_n_args(char **args);
int			ms_pwd(void);
int			ms_echo(char **args);
int			ms_env(t_env_list *env_vars);
int			ms_unset(t_env_list **envp_list, char **args);
int			ms_export(t_ms *ms, char **args);
int			ms_cd(t_ms *ms, char **args);
void		ms_exit(t_ms *ms, char **args);

// ms_parser.c
char		**ms_parse(char *input);

// ms_env_initialization.c
t_env_list	*ms_init_env_vars(char **envp);

// ms_memory_management.c
void		ms_free_args(char **args);

// ms_env_list_management.c
t_env_list	*ms_lstnewnode(char *arg);
void		ms_remove_lstnode(t_env_list *node);
void		ms_lstclear(t_env_list **env_vars);
void		ms_lstaddback(t_env_list **env_vars, t_env_list *new_node);

// ms_env_var_utils.c 
bool		ms_update_env_var(t_env_list *node,
				char *name, char *value, t_export_mode mode);
char		*ms_extract_var_name(char *arg);
char		*ms_extract_var_value(char *arg, t_export_mode *mode);
int			ms_print_exported_envvars(t_env_list *env_vars);
bool		ms_env_var_valid(char *var);
void		ms_print_export_error(char *arg);
char		*ms_build_content_string(char *name, char *value,
				t_export_mode mode);
t_env_list	*ms_search_env_var(t_env_list *env_vars, char *name);

// ms_env_operations.c
void		ms_set_or_update_env_var(t_ms *ms, char *name, char *value);
char		*ms_get_content_value(char *content);
char		*ms_get_target_dir(t_ms *ms, char **args);
char		*ms_get_env_value(t_env_list *env_vars, char *var_name);
int			ms_chdir_error(char *path);
int			ms_getcwd_error(void);

#endif
