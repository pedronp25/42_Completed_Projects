/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cd_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 23:44:22 by pedromig          #+#    #+#             */
/*   Updated: 2026/02/14 23:44:32 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ms_set_or_update_env_var(t_ms *ms, char *name, char *value)
{
	t_env_list	*found;
	char		*new_content;

	found = ms_search_env_var(ms->env_vars, name);
	new_content = ms_build_content_string(name, value, 1);
	if (found)
	{
		free(found->content);
		found->content = new_content;
	}
	else
		ms_lstaddback(&ms->env_vars, ms_lstnewnode(new_content));
}

static char	*ms_extract_var_value_from_content(char *content)
{
	char	*equal_sign;

	equal_sign = ft_strchr(content, '=');
	if (!equal_sign)
		return (NULL);
	return (equal_sign + 1);
}

char	*ms_get_target_dir(t_ms *ms, char **args)
{
	char	*target_dir;

	if (!args[1])
	{
		target_dir = ms_get_env_value(ms->env_vars, "HOME");
		if (!target_dir)
		{
			ft_putstr_fd("meow: cd: HOME not set\n", STDERR_FILENO);
			return (NULL);
		}
		return (target_dir);
	}
	return (args[1]);
}

char	*ms_get_env_value(t_env_list *env_vars, char *var_name)
{
	char	*existing_name;
	char	*value;

	while (env_vars)
	{
		existing_name = ms_extract_var_name(env_vars->content);
		if (ft_strncmp(existing_name, var_name, ft_strlen(var_name) + 1) == 0)
		{
			free(existing_name);
			value = ms_extract_var_value_from_content(env_vars->content);
			return (value);
		}
		free(existing_name);
		env_vars = env_vars->next;
	}
	return (NULL);
}
