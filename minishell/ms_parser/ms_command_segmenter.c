/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_command_segmenter.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-te <mjoao-te@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:19:59 by mjoao-te          #+#    #+#             */
/*   Updated: 2026/02/17 15:20:01 by mjoao-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_parser.h"

static char	**duplicate_args(t_list *args, int count)
{
	char	**argv;
	t_list	*ptr;
	int		i;

	argv = malloc(sizeof(char *) * (count + 1));
	if (!argv)
		return (NULL);
	i = 0;
	ptr = args;
	while (ptr)
	{
		argv[i] = ft_strdup((char *)ptr->content);
		if (!argv[i])
		{
			while (i > 0)
				free(argv[--i]);
			free(argv);
			return (NULL);
		}
		i++;
		ptr = ptr->next;
	}
	argv[i] = NULL;
	return (argv);
}

char	**convert_to_argv(t_list *args)
{
	int			count;
	t_list		*tmp;

	count = 0;
	tmp = args;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (duplicate_args(args, count));
}

void	append_command(t_command **head, t_command *new_cmd)
{
	t_command	*ptr;

	if (!new_cmd)
		return ;
	if (!*head)
	{
		*head = new_cmd;
		return ;
	}
	ptr = *head;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new_cmd;
}

void	parse_command_segment(t_token **tokens, t_command *cmd)
{
	t_list	*args;

	if (!tokens || !*tokens || !cmd)
		return ;
	args = NULL;
	while (*tokens && (*tokens)->type != TOKEN_PIPE
		&& (*tokens)->type != TOKEN_EOF)
	{
		if (is_redirect((*tokens)->type))
			append_redirect(&cmd->redirects, parse_redirection(tokens));
		else if ((*tokens)->type == TOKEN_WORD)
		{
			ft_lstadd_back(&args, ft_lstnew(ft_strdup((*tokens)->value)));
			*tokens = (*tokens)->next;
		}
		else
			*tokens = (*tokens)->next;
	}
	cmd->args = convert_to_argv(args);
	ft_lstclear(&args, free);
}
