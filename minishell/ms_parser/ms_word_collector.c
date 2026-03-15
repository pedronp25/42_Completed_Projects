/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_word_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-te <mjoao-te@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:06:48 by mjoao-te          #+#    #+#             */
/*   Updated: 2026/02/17 15:07:04 by mjoao-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_parser.h"

char	*collect_word(char *input, int *i, t_env_list *env_vars,
	int last_exit_status)
{
	char	*word;
	char	*segment;

	word = NULL;
	while (input[*i] && !ft_isspace(input[*i]) && !is_operator(input[*i]))
	{
		if (is_quote(input[*i]))
			segment = handle_quote_char(input, i, env_vars, last_exit_status);
		else if (input[*i] == '$')
			segment = handle_dollar_char(input, i, env_vars, last_exit_status);
		else
			segment = handle_regular_char(input, i);
		if (!segment)
		{
			free(word);
			return (NULL);
		}
		word = join_and_free(word, segment, ft_strlen(segment));
		free(segment);
		if (!word)
			return (NULL);
	}
	return (word);
}
