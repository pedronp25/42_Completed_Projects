/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_executor_heredoc_preprocess.c                    :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-te <mjoao-te@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 00:00:00 by mjoao-te          #+#    #+#             */
/*   Updated: 2026/03/08 00:00:00 by mjoao-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	process_command_heredocs(t_command *cmd)
{
	t_redirect	*redir;
	int			fd;

	if (!cmd || !cmd->redirects)
		return (0);
	redir = cmd->redirects;
	while (redir)
	{
		if (redir->type == TOKEN_REDIR_HEREDOC)
		{
			fd = setup_heredoc(redir->file);
			if (fd == -1)
				return (-1);
			redir->fd = fd;
		}
		redir = redir->next;
	}
	return (0);
}

int	ms_preprocess_heredocs(t_command_table *table)
{
	t_command	*cmd;

	if (!table || !table->commands)
		return (0);
	cmd = table->commands;
	while (cmd)
	{
		if (process_command_heredocs(cmd) == -1)
			return (-1);
		cmd = cmd->next;
	}
	return (0);
}
