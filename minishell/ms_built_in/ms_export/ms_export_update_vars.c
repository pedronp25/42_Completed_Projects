/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_export_update_vars.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 19:30:02 by pedromig          #+#    #+#             */
/*   Updated: 2026/02/14 19:30:02 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static bool	ms_replace_var_value(char **content, char *name, char *value);
static bool	ms_append_var_value(char **content, char *value);

bool	ms_update_env_var(t_env_list *node, char *name,
			char *value, t_export_mode mode)
{
	if (mode == MODE_NO_VALUE)
	{
		node->exported = true;
		return (true);
	}
	if (mode == MODE_REPLACE)
	{
		if (!ms_replace_var_value(&node->content, name, value))
			return (false);
	}
	else if (mode == MODE_APPEND)
	{
		if (!ms_append_var_value(&node->content, value))
			return (false);
	}
	node->exported = true;
	return (true);
}

static bool	ms_replace_var_value(char **content, char *name, char *value)
{
	char	*new_content;

	new_content = ms_build_content_string(name, value, MODE_REPLACE);
	if (!new_content)
		return (false);
	free(*content);
	*content = new_content;
	return (true);
}

static bool	ms_append_var_value(char **content, char *value)
{
	char	*temp;

	temp = *content;
	*content = ft_strjoin(temp, value);
	free(temp);
	if (!*content)
		return (false);
	return (true);
}
