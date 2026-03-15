/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_executor_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 22:20:04 by pedromig          #+#    #+#             */
/*   Updated: 2026/02/23 22:20:16 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	ms_execute_single_command(t_ms *ms, t_command *cmd);
static int	ms_execute_external(t_ms *ms, t_command *cmd);
static void	restore_stdio(int saved_stdin, int saved_stdout);
static int	handle_redirects(t_command *cmd,
				int *saved_stdin, int *saved_stdout);

int	ms_execute_command_table(t_ms *ms)
{
	int	exit_status;

	if (!ms->command_table || !ms->command_table->commands)
		return (0);
	if (ms->command_table->pipes_count == 0)
	{
		exit_status = ms_execute_single_command(ms,
				ms->command_table->commands);
		ms->exit_status = exit_status;
		return (exit_status);
	}
	exit_status = ms_execute_pipeline(ms, ms->command_table->commands,
			ms->command_table->commands_count);
	ms->exit_status = exit_status;
	return (exit_status);
}

static int	ms_execute_single_command(t_ms *ms, t_command *cmd)
{
	int	saved_stdin;
	int	saved_stdout;
	int	exit_status;

	if (!cmd)
		return (0);
	if (!cmd->args || !cmd->args[0] || !cmd->args[0][0])
	{
		if (!cmd->redirects)
			return (0);
		if (handle_redirects(cmd, &saved_stdin, &saved_stdout) == -1)
			return (1);
		restore_stdio(saved_stdin, saved_stdout);
		return (0);
	}
	if (get_builtin_type(cmd->args[0]) == BUILTIN_NONE)
		return (ms_execute_external(ms, cmd));
	if (handle_redirects(cmd, &saved_stdin, &saved_stdout) == -1)
		return (1);
	exit_status = ms_execute_builtin(ms, cmd->args);
	restore_stdio(saved_stdin, saved_stdout);
	return (exit_status);
}

static int	handle_redirects(t_command *cmd,
			int *saved_stdin, int *saved_stdout)
{
	*saved_stdin = dup(STDIN_FILENO);
	*saved_stdout = dup(STDOUT_FILENO);
	if (*saved_stdin < 0 || *saved_stdout < 0)
		return (-1);
	if (ms_apply_redirections(cmd->redirects) == -1)
	{
		restore_stdio(*saved_stdin, *saved_stdout);
		return (-1);
	}
	return (0);
}

static int	ms_execute_external(t_ms *ms, t_command *cmd)
{
	char	*cmd_path;
	pid_t	pid;
	int		status;

	cmd_path = ms_find_command(ms, cmd->args[0], ms->env_vars);
	if (!cmd_path)
		return (ms_print_file_error(ms->exit_status,
				cmd->args[0], ft_strchr(cmd->args[0], '/') != NULL));
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free(cmd_path);
		return (1);
	}
	if (pid == 0)
		ms_execute_child(ms, cmd, cmd_path);
	free(cmd_path);
	waitpid(pid, &status, 0);
	return (ms_extract_exit_status(status));
}

static void	restore_stdio(int saved_stdin, int saved_stdout)
{
	dup2(saved_stdin, STDIN_FILENO);
	dup2(saved_stdout, STDOUT_FILENO);
	close(saved_stdin);
	close(saved_stdout);
}
