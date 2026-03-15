/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_tokenizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-te <mjoao-te@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 17:21:21 by mjoao-te          #+#    #+#             */
/*   Updated: 2026/01/02 17:21:23 by mjoao-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_parser.h"

static int	skip_whitespaces(char *input, int i)
{
	while (input[i] && ft_isspace(input[i]))
		i++;
	return (i);
}

static void	add_if_valid_token(t_token **tokens, t_token *token)
{
	if (token && token->value)
		add_token(tokens, token);
	else
		free(token);
}

t_token	*tokenize(char *input, t_env_list *env_vars, int last_exit_status)
{
	t_token	*tokens;
	int		i;

	tokens = NULL;
	i = 0;
	if (!input || !input[0] || has_unclosed_quotes(input))
		return (NULL);
	while (input[i])
	{
		i = skip_whitespaces(input, i);
		if (!input[i])
			break ;
		if (is_operator(input[i]))
			append_operator_token(&tokens, input, &i);
		else
			add_if_valid_token(&tokens, create_token(TOKEN_WORD,
					collect_word(input, &i, env_vars, last_exit_status)));
	}
	add_token(&tokens, create_token(TOKEN_EOF, NULL));
	return (tokens);
}
