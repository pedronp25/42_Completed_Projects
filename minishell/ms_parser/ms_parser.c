/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-te <mjoao-te@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 18:18:03 by mjoao-te          #+#    #+#             */
/*   Updated: 2026/01/12 19:25:19 by mjoao-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_parser.h"

static t_token	*validate_and_tokenize(char *input, t_env_list *env_vars,
	int last_exit_status)
{
	t_token			*tokens;
	t_parse_error	err;

	tokens = tokenize(input, env_vars, last_exit_status);
	if (!tokens)
	{
		if (has_unclosed_quotes(input))
			print_parse_error(ERR_UNCLOSED_QUOTE, input);
		free_tokens(tokens);
		return (NULL);
	}
	err = validate_tokens_syntax(tokens);
	if (err != ERR_NONE)
	{
		print_parse_error(err, input);
		free_tokens(tokens);
		return (NULL);
	}
	return (tokens);
}

static void	process_pipe_and_cmd(t_token **cursor, t_command_table *table)
{
	t_command	*cmd;

	if ((*cursor)->type == TOKEN_PIPE)
	{
		*cursor = (*cursor)->next;
		table->pipes_count++;
		return ;
	}
	cmd = malloc(sizeof(t_command));
	if (!cmd)
		return ;
	ft_bzero(cmd, sizeof(t_command));
	parse_command_segment(cursor, cmd);
	append_command(&table->commands, cmd);
	table->commands_count++;
}

t_command_table	*run_parser(char *input, t_env_list *env_vars,
	int last_exit_status)
{
	t_token			*tokens;
	t_command_table	*table;
	t_token			*cursor;

	tokens = validate_and_tokenize(input, env_vars, last_exit_status);
	if (!tokens)
		return (NULL);
	table = malloc(sizeof(t_command_table));
	if (!table)
	{
		free_tokens(tokens);
		return (NULL);
	}
	ft_bzero(table, sizeof(t_command_table));
	cursor = tokens;
	while (cursor && cursor->type != TOKEN_EOF)
		process_pipe_and_cmd(&cursor, table);
	free_tokens(tokens);
	return (table);
}
