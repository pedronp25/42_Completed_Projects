/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_executor_heredoc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 22:09:56 by pedromig          #+#    #+#             */
/*   Updated: 2026/03/03 22:10:08 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static bool	append_heredoc_line(char **content, char *line);
static char	*read_heredoc_content(char *delimiter);
static int	write_heredoc_to_pipe(int pipe_fds[2], char *content);

int	setup_heredoc(char *delimiter)
{
	char	*content;
	int		pipe_fds[2];
	int		result;

	content = read_heredoc_content(delimiter);
	if (!content)
		return (-1);
	if (pipe(pipe_fds) == -1)
	{
		perror("pipe");
		free(content);
		return (-1);
	}
	result = write_heredoc_to_pipe(pipe_fds, content);
	free(content);
	return (result);
}

static int	write_heredoc_to_pipe(int pipe_fds[2], char *content)
{
	write(pipe_fds[1], content, ft_strlen(content));
	close(pipe_fds[1]);
	return (pipe_fds[0]);
}

static char	*read_heredoc_content(char *delimiter)
{
	char	*line;
	char	*content;

	content = ft_strdup("");
	if (!content)
		return (NULL);
	while (1)
	{
		line = readline("> ");
		if (!line || (ft_strncmp(line, delimiter, ft_strlen(delimiter)) == 0
				&& ft_strlen(line) == ft_strlen(delimiter)))
		{
			free(line);
			break ;
		}
		if (!append_heredoc_line(&content, line))
			return (free(line), NULL);
		free(line);
	}
	return (content);
}

static bool	append_heredoc_line(char **content, char *line)
{
	char	*temp;
	char	*with_newline;

	temp = ft_strjoin(*content, line);
	if (!temp)
		return (false);
	with_newline = ft_strjoin(temp, "\n");
	free(temp);
	if (!with_newline)
		return (false);
	free(*content);
	*content = with_newline;
	return (true);
}
