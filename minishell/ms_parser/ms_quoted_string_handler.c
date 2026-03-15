/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_quoted_string_handler.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-te <mjoao-te@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:06:48 by mjoao-te          #+#    #+#             */
/*   Updated: 2026/02/17 15:07:04 by mjoao-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_parser.h"

static char	*walk_quoted_segment(char *segment, t_env_list *env_vars,
	int last_exit_status)
{
	int		i;
	char	*exp;
	char	*out;

	i = 0;
	exp = NULL;
	out = NULL;
	while (segment[i])
	{
		if (segment[i] == '$')
		{
			exp = expand_env_var(segment, &i, env_vars, last_exit_status);
			if (exp)
			{
				out = join_and_free(out, exp, ft_strlen(exp));
				free(exp);
			}
		}
		else
		{
			out = join_and_free(out, &segment[i], 1);
			i++;
		}
	}
	return (out);
}

static char	*process_quoted_segment(char *segment, char quote,
	t_env_list *env_vars, int last_exit_status)
{
	char	*out;

	out = NULL;
	if (quote != '"')
		return (ft_strdup(segment));
	out = walk_quoted_segment(segment, env_vars, last_exit_status);
	if (!out)
		out = ft_strdup("");
	return (out);
}

static char	*handle_quoted_string(char *input, int *i,
	t_env_list *env_vars, int last_exit_status)
{
	char	quote;
	int		start;
	char	*segment;
	char	*result;

	quote = input[*i];
	(*i)++;
	start = *i;
	while (input[*i] && input[*i] != quote)
		(*i)++;
	if (input[*i] != quote)
		return (NULL);
	segment = ft_substr(input, start, *i - start);
	if (!segment)
		return (NULL);
	result = process_quoted_segment(segment, quote, env_vars, last_exit_status);
	free(segment);
	if (input[*i])
		(*i)++;
	return (result);
}

char	*handle_quote_char(char *input, int *i,
	t_env_list *env_vars, int last_exit_status)
{
	char	*quoted;

	quoted = handle_quoted_string(input, i, env_vars, last_exit_status);
	return (quoted);
}
