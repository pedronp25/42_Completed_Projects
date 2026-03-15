/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_executor.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 20:53:06 by pedromig          #+#    #+#             */
/*   Updated: 2026/02/25 20:53:06 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_EXECUTOR_H
# define MS_EXECUTOR_H

# include "../ms_parser/ms_parser.h"
# include <stdbool.h>
# include <unistd.h>
# include <sys/wait.h>

// Forward declarations to avoid circular includes
typedef struct s_ms			t_ms;
typedef struct s_env_list	t_env_list;

typedef enum e_builtin
{
	BUILTIN_NONE,
	BUILTIN_PWD,
	BUILTIN_ECHO,
	BUILTIN_ENV,
	BUILTIN_EXIT,
	BUILTIN_UNSET,
	BUILTIN_CD,
	BUILTIN_EXPORT
}	t_builtin;

typedef struct s_pipeline_data
{
	t_command	*cmds;
	int			num_cmds;
	int			prev_fd;
	int			status;
	pid_t		*pids;
}	t_pipeline_data;

// ms_executor_main.c
int			ms_execute_command_table(t_ms *ms);

// ms_executor_builtin.c
int			ms_execute_builtin(t_ms *ms, char **args);

// ms_executor_external.c
void		ms_execute_child(t_ms *ms, t_command *cmd, char *cmd_path);
char		*ms_find_command(t_ms *ms, char *cmd, t_env_list *env_vars);

// ms_executor_pipeline.c
int			ms_execute_pipeline(t_ms *ms, t_command *cmds, int num_cmds);

// ms_executor_pipeline_utils.c
void		init_pipeline_data(t_pipeline_data *data, t_command *cmds,
				int n_cmds);
void		setup_child_redirections(t_pipeline_data *data,
				int pipe_fds[2], int x);
void		handle_pipeline_parent(t_pipeline_data *data,
				int pipe_fds[2], int x);
void		wait_for_pipeline(int num_cmds, pid_t *pids, int *status);

// ms_executor_redirections.c
int			ms_apply_redirections(t_redirect *redirects);

// ms_executor_heredoc.c
int			setup_heredoc(char *delimiter);

// ms_executor_heredoc_preprocess.c
int			ms_preprocess_heredocs(t_command_table *table);

// ms_executor_env.c
char		**ms_env_list_to_array(t_env_list *env_vars);

// ms_executor_signals.c
void		init_signal_handlers(void);
void		sigint_handler(int signum);
int			consume_signal_exit_status(void);

// ms_executor_utils.c
t_builtin	get_builtin_type(char *cmd);
int			ms_print_file_error(int exit_status, char *cmd, bool has_slash);
int			ms_extract_exit_status(int status);

// ms_find_utils.c
char		*search_in_paths(char **paths, char *cmd);
char		*build_path(char *dir, char *cmd);
char		*handle_explicit_path(t_ms *ms, char *cmd);
char		*search_path_env(t_ms *ms, char *cmd, t_env_list *env_vars);

#endif
