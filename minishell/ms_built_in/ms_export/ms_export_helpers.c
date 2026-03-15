/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_export_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 19:47:46 by pedromig          #+#    #+#             */
/*   Updated: 2026/02/14 19:47:55 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

bool	ms_env_var_valid(char *var)
{
	int	x;

	x = 0;
	if (!ft_isalpha(var[x]) && var[x] != '_')
		return (false);
	x++;
	while (var[x] && var[x] != '=' && var[x] != '+')
	{
		if (!ft_isalnum(var[x]) && var[x] != '_')
			return (false);
		x++;
	}
	if (!var[x] || var[x] == '=' || (var[x] == '+' && var[x + 1] == '='))
		return (true);
	return (false);
}

void	ms_print_export_error(char *arg)
{
	ft_putstr_fd("meow: export: `", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO);
}

char	*ms_build_content_string(char *name, char *value, t_export_mode mode)
{
	char	*temp;
	char	*content;

	if (mode == MODE_NO_VALUE)
		return (ft_strdup(name));
	temp = ft_strjoin(name, "=");
	if (!temp)
		return (NULL);
	content = ft_strjoin(temp, value);
	free(temp);
	return (content);
}
