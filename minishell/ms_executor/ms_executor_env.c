/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_executor_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 19:53:45 by pedromig          #+#    #+#             */
/*   Updated: 2026/02/24 19:53:57 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	count_env_nodes(t_env_list *env_vars);

char	**ms_env_list_to_array(t_env_list *env_vars)
{
	char		**envp;
	int			count;
	int			x;
	t_env_list	*current;

	count = count_env_nodes(env_vars);
	envp = malloc(sizeof(char *) * (count + 1));
	if (!envp)
		return (NULL);
	x = 0;
	current = env_vars;
	while (current)
	{
		envp[x] = ft_strdup(current->content);
		if (!envp[x])
			return (free_argv(envp), NULL);
		current = current->next;
		x++;
	}
	envp[x] = NULL;
	return (envp);
}

static int	count_env_nodes(t_env_list *env_vars)
{
	int			count;
	t_env_list	*current;

	count = 0;
	current = env_vars;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}
