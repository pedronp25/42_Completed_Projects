/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_executor_pipeline.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 20:01:15 by pedromig          #+#    #+#             */
/*   Updated: 2026/02/25 20:01:33 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	execute_pipeline_command(t_ms *ms, t_pipeline_data *data, int x);
static void	handle_pipeline_child(t_ms *ms, t_pipeline_data *data,
				int pipe_fds[2], int x);
static void	execute_command_in_pipeline(t_ms *ms, t_command *cmd);

int	ms_execute_pipeline(t_ms *ms, t_command *cmds, int num_cmds)
{
	t_pipeline_data	data;
	int				x;

	init_pipeline_data(&data, cmds, num_cmds);
	x = 0;
	data.status = ms->exit_status;
	while (x < num_cmds)
	{
		if (execute_pipeline_command(ms, &data, x) == -1)
			return (1);
		data.cmds = data.cmds->next;
		x++;
	}
	wait_for_pipeline(num_cmds, data.pids, &data.status);
	free(data.pids);
	return (ms_extract_exit_status(data.status));
}

static int	execute_pipeline_command(t_ms *ms, t_pipeline_data *data, int x)
{
	int		pipe_fds[2];
	pid_t	pid;

	if (x < data->num_cmds - 1)
		if (pipe(pipe_fds) == -1)
			return (perror("pipe"), -1);
	pid = fork();
	data->pids[x] = pid;
	if (pid == -1)
		return (perror("fork"), -1);
	if (pid == 0)
		handle_pipeline_child(ms, data, pipe_fds, x);
	handle_pipeline_parent(data, pipe_fds, x);
	return (0);
}

static void	handle_pipeline_child(t_ms *ms, t_pipeline_data *data,
				int pipe_fds[2], int x)
{
	ms->in_child = 1;
	setup_child_redirections(data, pipe_fds, x);
	if (ms_apply_redirections(data->cmds->redirects) == -1)
		exit(1);
	execute_command_in_pipeline(ms, data->cmds);
	exit(ms->exit_status);
}

static void	execute_command_in_pipeline(t_ms *ms, t_command *cmd)
{
	char	*cmd_path;
	char	**envp;

	if (get_builtin_type(cmd->args[0]) != BUILTIN_NONE)
		exit(ms_execute_builtin(ms, cmd->args));
	if (!cmd->args || !cmd->args[0] || cmd->args[0][0] == '\0')
	{
		ms_print_file_error(127, cmd->args[0], 0);
		exit(127);
	}
	cmd_path = ms_find_command(ms, cmd->args[0], ms->env_vars);
	if (!cmd_path)
	{
		ms_print_file_error(ms->exit_status, cmd->args[0],
			ft_strchr(cmd->args[0], '/') != NULL);
		exit(127);
	}
	envp = ms_env_list_to_array(ms->env_vars);
	if (!envp)
		exit(1);
	execve(cmd_path, cmd->args, envp);
	perror(cmd_path);
	exit(127);
}
