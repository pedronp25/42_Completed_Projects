/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 02:27:36 by pedromig          #+#    #+#             */
/*   Updated: 2025/06/28 02:40:44 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1(t_pipex *pp, char *cmd, char **envp)
{
	if (dup2(pp->fd1, STDIN_FILENO) == -1)
		pipex_error(strerror(errno), pp);
	close(pp->fd1);
	if (dup2(pp->pipe_fd[1], STDOUT_FILENO) == -1)
		pipex_error(strerror(errno), pp);
	close(pp->pipe_fd[1]);
	close(pp->pipe_fd[0]);
	pp->cmd1_args = ft_split(cmd, ' ');
	if (!pp->cmd1_args || !pp->cmd1_args[0])
		pipex_error(strerror(errno), pp);
	pp->cmd1_path = pipex_find_path(pp, envp, pp->cmd1_args[0]);
	if (!pp->cmd1_path)
	{
		pipex_print_error(cmd, "command not found");
		pipex_cleanup(pp);
		exit (127);
	}
	execve(pp->cmd1_path, pp->cmd1_args, envp);
	if (errno == ENOENT)
		pipex_print_error(pp->cmd1_args[0], "command not found");
	else if (errno == EACCES)
		pipex_print_error(pp->cmd1_args[0], "Permission denied");
	else
		pipex_error(strerror(errno), pp);
}

void	child2(t_pipex *pp, char *cmd, char **envp)
{
	if (dup2(pp->pipe_fd[0], STDIN_FILENO) == -1)
		pipex_error(strerror(errno), pp);
	close(pp->pipe_fd[0]);
	if (dup2(pp->fd2, STDOUT_FILENO) == -1)
		pipex_error(strerror(errno), pp);
	close(pp->fd2);
	close(pp->pipe_fd[1]);
	pp->cmd2_args = ft_split(cmd, ' ');
	if (!pp->cmd2_args || !pp->cmd2_args[0])
		pipex_error(strerror(errno), pp);
	pp->cmd2_path = pipex_find_path(pp, envp, pp->cmd2_args[0]);
	if (!pp->cmd2_path)
	{
		pipex_print_error(cmd, "command not found");
		pipex_cleanup(pp);
		exit (127);
	}
	execve(pp->cmd2_path, pp->cmd2_args, envp);
	if (errno == ENOENT)
		pipex_print_error(pp->cmd2_args[0], "command not found");
	else if (errno == EACCES)
		pipex_print_error(pp->cmd2_args[0], "Permission denied");
	else
		pipex_error(strerror(errno), pp);
}

char	*pipex_find_path(t_pipex *pp, char **envp, char *cmd)
{
	int		x;
	char	*path;
	int		len;

	if (access(cmd, X_OK) == 0)
		return (cmd);
	len = ft_strlen("PATH=");
	x = 0;
	while (envp[x])
	{
		if (ft_strncmp(envp[x], "PATH=", len) == 0)
		{
			path = envp[x] + len;
			return (pipex_access_path(pp, path, cmd));
		}
		x++;
	}
	pipex_error(strerror(errno), pp);
	return (NULL);
}

char	*pipex_access_path(t_pipex *pp, char *path, char *cmd)
{
	int		x;
	char	**path_args;
	char	*exe_path;

	path_args = ft_split(path, ':');
	if (!path_args)
		pipex_error(strerror(errno), pp);
	x = 0;
	while (path_args[x])
	{
		exe_path = ft_double_strjoin(path_args[x], "/", cmd);
		if (!exe_path)
			pipex_error(strerror(errno), pp);
		if (access(exe_path, X_OK) == 0)
			return (pipex_free_arr(path_args), exe_path);
		free(exe_path);
		x++;
	}
	pipex_free_arr(path_args);
	return (NULL);
}

char	*ft_double_strjoin(char const *s1, char const *s2, char const *s3)
{
	char	*final_str;
	size_t	s1_len;
	size_t	s2_len;
	size_t	s3_len;
	size_t	total_size;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s3_len = ft_strlen(s3);
	total_size = s1_len + s2_len + s3_len + 1;
	final_str = malloc(total_size);
	if (!final_str)
		return (NULL);
	ft_strlcpy(final_str, s1, total_size);
	ft_strlcat(final_str, s2, total_size);
	ft_strlcat(final_str, s3, total_size);
	return (final_str);
}
