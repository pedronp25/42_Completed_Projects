/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_executor_pipeline_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 20:01:15 by pedromig          #+#    #+#             */
/*   Updated: 2026/02/25 20:01:33 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	init_pipeline_data(t_pipeline_data *data,
				t_command *cmds, int num_cmds)
{
	data->cmds = cmds;
	data->num_cmds = num_cmds;
	data->prev_fd = -1;
	data->status = 0;
	data->pids = malloc(sizeof(pid_t) * num_cmds);
}

void	setup_child_redirections(t_pipeline_data *data,
				int pipe_fds[2], int x)
{
	if (x > 0)
	{
		dup2(data->prev_fd, STDIN_FILENO);
		close(data->prev_fd);
	}
	if (x < data->num_cmds - 1)
	{
		close(pipe_fds[0]);
		dup2(pipe_fds[1], STDOUT_FILENO);
		close(pipe_fds[1]);
	}
}

void	handle_pipeline_parent(t_pipeline_data *data,
				int pipe_fds[2], int x)
{
	if (data->prev_fd != -1)
		close(data->prev_fd);
	if (x < data->num_cmds - 1)
	{
		close(pipe_fds[1]);
		data->prev_fd = pipe_fds[0];
	}
}

void	wait_for_pipeline(int num_cmds, pid_t *pids, int *status)
{
	int	x;
	int	tmp;

	x = 0;
	while (x < num_cmds)
	{
		waitpid(pids[x], &tmp, 0);
		x++;
	}
	*status = tmp;
}
