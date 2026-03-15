/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_operator_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-te <mjoao-te@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 12:00:00 by mjoao-te          #+#    #+#             */
/*   Updated: 2026/02/17 17:23:38 by mjoao-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_parser.h"

t_token_type	identify_operator(char *str, int *i)
{
	if (str[*i] == '>' && str[*i + 1] == '>')
	{
		(*i)++;
		return (TOKEN_REDIR_APPEND);
	}
	if (str[*i] == '<' && str[*i + 1] == '<')
	{
		(*i)++;
		return (TOKEN_REDIR_HEREDOC);
	}
	if (str[*i] == '>')
		return (TOKEN_REDIR_OUT);
	if (str[*i] == '<')
		return (TOKEN_REDIR_IN);
	return (TOKEN_PIPE);
}

char	*get_exit_status_as_str(int last_exit_status)
{
	char	*s;

	s = ft_itoa(last_exit_status);
	return (s);
}
