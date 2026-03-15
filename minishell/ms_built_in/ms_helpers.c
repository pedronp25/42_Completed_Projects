/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 19:45:01 by pedromig          #+#    #+#             */
/*   Updated: 2026/01/09 15:55:12 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ms_n_args(char **args)
{
	int	x;

	x = 0;
	while (args && args[x])
		x++;
	return (x);
}

// t_env_list helpers
t_env_list	*ms_lstnewnode(char *arg)
{
	t_env_list	*new_node;

	new_node = malloc(sizeof(t_env_list));
	if (!new_node)
		return (NULL);
	new_node->content = arg;
	new_node->exported = true;
	new_node->next = NULL;
	return (new_node);
}

void	ms_remove_lstnode(t_env_list *node)
{
	free(node->content);
	free(node);
}

void	ms_lstclear(t_env_list **env_vars)
{
	t_env_list	*current;
	t_env_list	*tmp_node;

	if (!env_vars)
		return ;
	current = *env_vars;
	while (current)
	{
		tmp_node = current;
		current = current->next;
		ms_remove_lstnode(tmp_node);
	}
	*env_vars = NULL;
}

void	ms_lstaddback(t_env_list **env_vars, t_env_list *new_node)
{
	t_env_list	*last_node;
	t_env_list	*current;

	if (!env_vars)
		return ;
	if (!*env_vars)
	{
		*env_vars = new_node;
		return ;
	}
	current = *env_vars;
	while (current->next)
		current = current->next;
	last_node = current;
	last_node->next = new_node;
}
