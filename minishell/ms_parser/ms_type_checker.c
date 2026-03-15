/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_type_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-te <mjoao-te@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 17:23:54 by mjoao-te          #+#    #+#             */
/*   Updated: 2026/01/02 17:24:05 by mjoao-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_parser.h"

int	is_quote(char c)
{
	return (c == '\'' || c == '\"');
}

int	is_operator(char c)
{
	return (c == '|' || c == '<' || c == '>');
}

int	is_redirect(t_token_type type)
{
	return (type == TOKEN_REDIR_IN || type == TOKEN_REDIR_OUT
		|| type == TOKEN_REDIR_APPEND || type == TOKEN_REDIR_HEREDOC);
}

int	is_pipe(t_token_type type)
{
	return (type == TOKEN_PIPE);
}

int	is_valid_command_sequence(t_token *tokens)
{
	if (!tokens || is_pipe(tokens->type))
		return (0);
	while (tokens && tokens->type != TOKEN_EOF)
	{
		if (is_pipe(tokens->type)
			&& (!tokens->next || is_pipe(tokens->next->type)
				|| tokens->next->type == TOKEN_EOF))
			return (0);
		if (is_redirect(tokens->type)
			&& (!tokens->next || tokens->next->type != TOKEN_WORD))
			return (0);
		tokens = tokens->next;
	}
	return (1);
}
