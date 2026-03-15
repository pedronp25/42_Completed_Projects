/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_redirect_segmenter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-te <mjoao-te@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:21:12 by mjoao-te          #+#    #+#             */
/*   Updated: 2026/02/17 17:24:58 by mjoao-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_parser.h"

void	append_redirect(t_redirect **head, t_redirect *new_redir)
{
	t_redirect	*tmp;

	if (!new_redir)
		return ;
	if (!*head)
	{
		*head = new_redir;
		return ;
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_redir;
}

t_redirect	*parse_redirection(t_token **tokens)
{
	t_redirect		*redir;
	t_token			*current;
	t_token			*file_token;

	if (!tokens || !*tokens || !is_redirect((*tokens)->type))
		return (NULL);
	current = *tokens;
	file_token = current->next;
	if (!file_token || file_token->type != TOKEN_WORD)
		return (NULL);
	redir = malloc(sizeof(t_redirect));
	if (!redir)
		return (NULL);
	redir->type = current->type;
	redir->file = ft_strdup(file_token->value);
	redir->fd = -1;
	redir->next = NULL;
	*tokens = file_token->next;
	return (redir);
}
