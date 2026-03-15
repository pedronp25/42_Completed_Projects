/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_mem_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-te <mjoao-te@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 14:17:50 by mjoao-te          #+#    #+#             */
/*   Updated: 2026/01/25 14:17:53 by mjoao-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_parser/ms_parser.h"

void	free_argv(char **argv)
{
	int	i;

	if (!argv)
		return ;
	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	free_redirects(t_redirect *redir)
{
	t_redirect	*next;

	while (redir)
	{
		next = redir->next;
		free(redir->file);
		if (redir->fd >= 0)
			close(redir->fd);
		free(redir);
		redir = next;
	}
}

void	free_command(t_command *cmd)
{
	free_argv(cmd->args);
	free_redirects(cmd->redirects);
}

void	free_command_table(t_command_table *table)
{
	t_command	*current;
	t_command	*next;

	if (!table)
		return ;
	current = table->commands;
	while (current)
	{
		next = current->next;
		free_command(current);
		free(current);
		current = next;
	}
	free(table);
	table = NULL;
}
