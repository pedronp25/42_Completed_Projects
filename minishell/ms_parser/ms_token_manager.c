/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_token_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-te <mjoao-te@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 12:00:00 by mjoao-te          #+#    #+#             */
/*   Updated: 2026/01/03 12:00:00 by mjoao-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_parser.h"

t_token	*create_token(t_token_type type, char *value)
{
	t_token	*token;

	if (!value)
		return (NULL);
	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->type = type;
	token->value = value;
	token->next = NULL;
	return (token);
}

void	add_token(t_token **head, t_token *new)
{
	t_token	*cursor;

	if (!new)
		return ;
	if (!*head)
	{
		*head = new;
		return ;
	}
	cursor = *head;
	while (cursor->next)
		cursor = cursor->next;
	cursor->next = new;
}

void	free_tokens(t_token *tokens)
{
	t_token	*tmp;

	while (tokens)
	{
		tmp = tokens->next;
		free(tokens->value);
		free(tokens);
		tokens = tmp;
	}
}

char	*join_and_free(char *base, const char *tail, size_t len)
{
	char	*joined;
	size_t	base_len;

	base_len = 0;
	if (base)
		base_len = ft_strlen(base);
	joined = malloc(base_len + len + 1);
	if (!joined)
	{
		free(base);
		return (NULL);
	}
	if (base && base_len)
		ft_memcpy(joined, base, base_len);
	if (tail && len)
		ft_memcpy(joined + base_len, tail, len);
	joined[base_len + len] = '\0';
	free(base);
	return (joined);
}

void	append_operator_token(t_token **tokens, char *input, int *i)
{
	int	start;

	start = *i;
	add_token(tokens, create_token(identify_operator(input, i),
			ft_substr(input, start, *i - start + 1)));
	(*i)++;
}
