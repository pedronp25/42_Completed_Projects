/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_executor_external.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 23:05:21 by pedromig          #+#    #+#             */
/*   Updated: 2026/02/23 23:05:38 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	perror_and_exit(char *cmd_path, char *msg,
				char **envp, int exit_stat);

void	ms_execute_child(t_ms *ms, t_command *cmd, char *cmd_path)
{
	char		**envp;
	struct stat	st_stat;

	if (ms_apply_redirections(cmd->redirects) == -1)
	{
		free(cmd_path);
		exit(1);
	}
	envp = ms_env_list_to_array(ms->env_vars);
	if (!envp)
	{
		free(cmd_path);
		exit(1);
	}
	stat(cmd_path, &st_stat);
	if (S_ISDIR(st_stat.st_mode))
		perror_and_exit(cmd_path, "Is a directory", envp, 126);
	execve(cmd_path, cmd->args, envp);
	perror_and_exit(cmd_path, strerror(errno), envp, 127);
}

char	*ms_find_command(t_ms *ms, char *cmd, t_env_list *env_vars)
{
	if (ft_strchr(cmd, '/'))
		return (handle_explicit_path(ms, cmd));
	return (search_path_env(ms, cmd, env_vars));
}

static void	perror_and_exit(char *cmd_path, char *msg, char **envp,
				int exit_status)
{
	ft_putstr_fd("meow: ", STDERR_FILENO);
	ft_putstr_fd(cmd_path, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	free(cmd_path);
	free_argv(envp);
	exit(exit_status);
}
