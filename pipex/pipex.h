/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 22:12:20 by pedromig          #+#    #+#             */
/*   Updated: 2025/06/28 00:12:15 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>
# include <wait.h>
# include <string.h>
# include <errno.h>

typedef struct s_pipex
{
	int		fd1;
	int		fd2;
	int		pipe_fd[2];
	int		id1;
	int		id2;
	int		status;
	char	**cmd1_args;
	char	**cmd2_args;
	char	**envp;
	char	*cmd1_path;
	char	*cmd2_path;
}	t_pipex;

void	child1(t_pipex *pp, char *cmd1, char **envp);
void	child2(t_pipex *pp, char *cmd2, char **envp);
t_pipex	*pipex_init(int argc, char **argv);
char	*pipex_find_path(t_pipex *pp, char **envp, char *cmd);
int		pipex_waitpid(t_pipex *pp);
char	*pipex_access_path(t_pipex *pp, char *path, char *cmd);
char	*ft_double_strjoin(char const *s1, char const *s2, char const *s3);
void	pipex_error(char *err_msg, t_pipex *pp);
void	pipex_cleanup(t_pipex *pp);
void	pipex_free_arr(char **str);
void	pipex_print_error(char *cmd, char *err_msg);

#endif
