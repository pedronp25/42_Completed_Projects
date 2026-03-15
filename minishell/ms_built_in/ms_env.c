/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 18:37:05 by pedromig          #+#    #+#             */
/*   Updated: 2026/01/18 21:13:24 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static bool	env_has_value(char *var);

int	ms_env(t_env_list *env_vars)
{
	if (!env_vars)
		return (SUCCESS);
	while (env_vars)
	{
		if (env_vars->content && env_vars->exported
			&& env_has_value(env_vars->content))
			ft_printf("%s\n", env_vars->content);
		env_vars = env_vars->next;
	}
	return (SUCCESS);
}

static bool	env_has_value(char *var)
{
	int	x;

	x = 0;
	while (var[x] && var[x] != '=')
		x++;
	if (!var[x])
		return (false);
	return (true);
}
