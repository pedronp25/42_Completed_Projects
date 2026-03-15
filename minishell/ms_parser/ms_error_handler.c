/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_error_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-te <mjoao-te@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 17:24:44 by mjoao-te          #+#    #+#             */
/*   Updated: 2026/03/11 20:02:18 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_parser.h"

int	validate_tokens_syntax(t_token *tokens)
{
	if (!tokens)
		return (ERR_MALLOC);
	if (has_unclosed_quotes(tokens->value))
		return (ERR_UNCLOSED_QUOTE);
	if (!is_valid_command_sequence(tokens))
		return (ERR_SYNTAX);
	return (ERR_NONE);
}

void	print_parse_error(t_parse_error err, char *context)
{
	(void)context;
	if (err == ERR_UNCLOSED_QUOTE)
		ft_printf("meow no: unclosed quote\n");
	else if (err == ERR_INVALID_PIPE)
		ft_printf("meow no: invalid pipe placement\n");
	else if (err == ERR_INVALID_REDIRECT)
		ft_printf("meow no: invalid redirection\n");
	else if (err == ERR_SYNTAX)
		ft_printf("meow no: syntax error\n");
}

void	ms_error(char *error_msg)
{
	ft_printf("error: %s\n", error_msg);
	exit (1);
}
