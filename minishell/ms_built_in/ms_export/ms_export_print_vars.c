/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_export_print_vars.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 19:42:30 by pedromig          #+#    #+#             */
/*   Updated: 2026/02/14 19:42:42 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	ms_print_var_with_quotes(char *name, char *equal_pos);

int	ms_print_exported_envvars(t_env_list *env_vars)
{
	char	*equal_pos;

	while (env_vars)
	{
		if (env_vars->exported)
		{
			ft_putstr_fd("declare -x ", STDOUT_FILENO);
			equal_pos = ft_strchr(env_vars->content, '=');
			if (equal_pos)
				ms_print_var_with_quotes(ms_extract_var_name(env_vars->content), equal_pos);
			else
				ft_printf("%s\n", env_vars->content);
		}
		env_vars = env_vars->next;
	}
	return (SUCCESS);
}

static void	ms_print_var_with_quotes(char *name, char *equal_pos)
{
	ft_putstr_fd(name, STDOUT_FILENO);
	ft_putstr_fd("=\"", STDOUT_FILENO);
	ft_putstr_fd(equal_pos + 1, STDOUT_FILENO);
	ft_putstr_fd("\"\n", STDOUT_FILENO);
}
