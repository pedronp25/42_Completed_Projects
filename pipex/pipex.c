/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 18:00:41 by pedromig          #+#    #+#             */
/*   Updated: 2025/06/24 23:28:16 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	*pp;
	int		return_status;

	pp = pipex_init(argc, argv);
	if (pipe(pp->pipe_fd) == -1)
		perror(strerror(errno));
	pp->id1 = fork();
	if (pp->id1 == -1)
		pipex_error(strerror(errno), pp);
	if (pp->id1 == 0)
		child1(pp, argv[2], envp);
	pp->id2 = fork();
	if (pp->id2 == -1)
		pipex_error(strerror(errno), pp);
	if (pp->id2 == 0)
		child2(pp, argv[3], envp);
	close(pp->pipe_fd[0]);
	close(pp->pipe_fd[1]);
	return_status = pipex_waitpid(pp);
	pipex_cleanup(pp);
	return (return_status);
}

t_pipex	*pipex_init(int argc, char **argv)
{
	t_pipex	*pp;	

	if (argc != 5)
	{
		ft_printf("Usage: ./pipex infile 'cmd1' 'cmd2' outfile\n");
		exit(EXIT_FAILURE);
	}
	pp = ft_calloc(1, sizeof(t_pipex));
	if (!pp)
		pipex_error(strerror(errno), pp);
	pp->pipe_fd[0] = -1;
	pp->pipe_fd[1] = -1;
	pp->id1 = -1;
	pp->id2 = -1;
	pp->fd1 = -1;
	pp->fd2 = -1;
	pp->fd1 = open(argv[1], O_RDONLY);
	if (pp->fd1 == -1)
		perror(strerror(errno));
	pp->fd2 = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (pp->fd2 == -1)
		perror(strerror(errno));
	return (pp);
}

int	pipex_waitpid(t_pipex *pp)
{
	waitpid(pp->id1, &pp->status, 0);
	waitpid(pp->id2, &pp->status, 0);
	return (WEXITSTATUS(pp->status));
}
