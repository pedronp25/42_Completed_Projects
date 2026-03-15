/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 13:08:28 by pedromig          #+#    #+#             */
/*   Updated: 2026/01/19 13:18:27 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static bool	envp_matches_arg(char *env_content, char *arg_remove);
static void	remove_envp_node(t_env_list **env_vars, char *arg_remove);

int	ms_unset(t_env_list **envp_list, char **args)
{
	int	x;

	x = 1;
	while (args[x])
	{
		remove_envp_node(envp_list, args[x]);
		x++;
	}
	return (SUCCESS);
}

static void	remove_envp_node(t_env_list **env_vars, char *arg_remove)
{
	t_env_list	*current;
	t_env_list	*previous;

	current = *env_vars;
	previous = NULL;
	while (current)
	{
		if (envp_matches_arg(current->content, arg_remove))
		{
			if (previous)
				previous->next = current->next;
			else
				*env_vars = current->next;
			ms_remove_lstnode(current);
			return ;
		}
		previous = current;
		current = current->next;
	}
}

static bool	envp_matches_arg(char *env_content, char *arg_remove)
{
	int	x;

	x = 0;
	while (env_content[x] && arg_remove[x])
	{
		if (env_content[x] != arg_remove[x])
			return (false);
		x++;
	}
	if (!arg_remove[x] && env_content[x] == '=')
		return (true);
	return (false);
}
