/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_quote_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-te <mjoao-te@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 12:00:00 by mjoao-te          #+#    #+#             */
/*   Updated: 2026/01/03 12:00:00 by mjoao-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_parser.h"

t_quote_state	update_quote_state(char c, t_quote_state current)
{
	if (c == '\'' && current != IN_DOUBLE_QUOTE)
	{
		if (current == IN_SINGLE_QUOTE)
			return (NO_QUOTE);
		return (IN_SINGLE_QUOTE);
	}
	if (c == '\"' && current != IN_SINGLE_QUOTE)
	{
		if (current == IN_DOUBLE_QUOTE)
			return (NO_QUOTE);
		return (IN_DOUBLE_QUOTE);
	}
	return (current);
}

char	*extract_quoted_string(char *str, int *i, char quote)
{
	int		start;
	char	*result;

	(*i)++;
	start = *i;
	while (str[*i] && str[*i] != quote)
		(*i)++;
	if (str[*i] != quote)
		return (NULL);
	result = ft_substr(str, start, *i - start);
	return (result);
}

int	has_unclosed_quotes(char *input)
{
	int				i;
	t_quote_state	state;

	state = NO_QUOTE;
	i = 0;
	while (input && input[i])
	{
		state = update_quote_state(input[i], state);
		i++;
	}
	return (state != NO_QUOTE);
}
