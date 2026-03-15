/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_executor_redirections.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 22:58:26 by pedromig          #+#    #+#             */
/*   Updated: 2026/02/22 22:58:33 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	open_redirect_file(t_redirect *redirect);
static void	redirect_fd(int fd, t_token_type type);
static int	redirect_files(t_redirect *current);

int	ms_apply_redirections(t_redirect *redirects)
{
	t_redirect	*current;

	current = redirects;
	while (current)
	{
		if (current->type == TOKEN_REDIR_HEREDOC)
		{
			if (current->fd == -1)
				return (-1);
			if (dup2(current->fd, STDIN_FILENO) == -1)
			{
				perror("dup2");
				return (-1);
			}
		}
		else if (redirect_files(current) == -1)
			return (-1);
		current = current->next;
	}
	return (0);
}

static int	redirect_files(t_redirect *current)
{
	int	fd;

	fd = open_redirect_file(current);
	if (fd == -1)
	{
		perror(current->file);
		return (-1);
	}
	redirect_fd(fd, current->type);
	close(fd);
	return (0);
}

static int	open_redirect_file(t_redirect *redirect)
{
	int	fd;

	if (redirect->type == TOKEN_REDIR_IN)
		fd = open(redirect->file, O_RDONLY);
	else if (redirect->type == TOKEN_REDIR_OUT)
		fd = open(redirect->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (redirect->type == TOKEN_REDIR_APPEND)
		fd = open(redirect->file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		return (-1);
	return (fd);
}

static void	redirect_fd(int fd, t_token_type type)
{
	if (type == TOKEN_REDIR_IN)
		dup2(fd, STDIN_FILENO);
	else
		dup2(fd, STDOUT_FILENO);
}
