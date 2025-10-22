/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 18:36:07 by pedromig          #+#    #+#             */
/*   Updated: 2025/06/28 02:41:24 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"
#include <unistd.h>

void	pipex_error(char *err_msg, t_pipex *pp)
{
	perror(err_msg);
	pipex_cleanup(pp);
	exit(EXIT_FAILURE);
}

void	pipex_print_error(char *cmd, char *err_msg)
{
	write(2, cmd, ft_strlen(cmd));
	write(2, ": ", 2);
	write(2, err_msg, ft_strlen(err_msg));
	write(2, "\n", 1);
}

void	pipex_cleanup(t_pipex *pp)
{
	if (!pp)
		return ;
	if (pp->fd1 != -1)
		close(pp->fd1);
	if (pp->fd2 != -1)
		close(pp->fd2);
	if (pp->pipe_fd[0] != -1)
		close(pp->pipe_fd[0]);
	if (pp->pipe_fd[1] != -1)
		close(pp->pipe_fd[1]);
	if (pp->cmd1_args)
		pipex_free_arr(pp->cmd1_args);
	if (pp->cmd2_args)
		pipex_free_arr(pp->cmd2_args);
	free(pp);
}

void	pipex_free_arr(char **arr)
{
	int	x;

	x = 0;
	while (arr[x])
	{
		free(arr[x]);
		x++;
	}
	free(arr);
}
