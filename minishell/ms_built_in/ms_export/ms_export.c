/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:48:54 by pedromig          #+#    #+#             */
/*   Updated: 2026/01/19 14:49:04 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static bool	ms_process_export_arg(t_ms *ms, char *arg);
static bool	ms_handle_export_variable(t_ms *ms,
				char *name, char *value, t_export_mode mode);
static bool	ms_create_env_var(t_env_list **env_vars, char *name,
				char *value, t_export_mode mode);

int	ms_export(t_ms *ms, char **args)
{
	int	x;
	int	exit_status;

	if (ms_n_args(args) == 1)
		return (ms_print_exported_envvars(ms->env_vars));
	exit_status = 0;
	x = 1;
	while (args[x])
	{
		if (!ms_env_var_valid(args[x]))
		{
			ms_print_export_error(args[x]);
			exit_status = 1;
		}
		else if (!ms_process_export_arg(ms, args[x]))
			exit(ERROR);
		x++;
	}
	return (exit_status);
}

static bool	ms_process_export_arg(t_ms *ms, char *arg)
{
	char			*var_name;
	char			*var_value;
	t_export_mode	mode;
	bool			success;

	var_name = ms_extract_var_name(arg);
	if (!var_name)
		return (false);
	var_value = ms_extract_var_value(arg, &mode);
	success = ms_handle_export_variable(ms, var_name, var_value, mode);
	free(var_name);
	if (var_value)
		free(var_value);
	return (success);
}

static bool	ms_handle_export_variable(t_ms *ms, char *name,
			char *value, t_export_mode mode)
{
	t_env_list	*found;

	found = ms_search_env_var(ms->env_vars, name);
	if (found)
		return (ms_update_env_var(found, name, value, mode));
	else
		return (ms_create_env_var(&ms->env_vars, name, value, mode));
}

t_env_list	*ms_search_env_var(t_env_list *env_vars, char *name)
{
	char	*existing_name;

	while (env_vars)
	{
		existing_name = ms_extract_var_name(env_vars->content);
		if (!existing_name)
			return (NULL);
		if (ft_strncmp(existing_name, name, ft_strlen(name) + 1) == 0)
		{
			free(existing_name);
			return (env_vars);
		}
		free(existing_name);
		env_vars = env_vars->next;
	}
	return (NULL);
}

static bool	ms_create_env_var(t_env_list **env_vars, char *name,
			char *value, t_export_mode mode)
{
	t_env_list	*new_node;
	char		*content;

	content = ms_build_content_string(name, value, mode);
	if (!content)
		return (false);
	new_node = ms_lstnewnode(content);
	if (!new_node)
	{
		free(content);
		return (false);
	}
	ms_lstaddback(env_vars, new_node);
	return (true);
}
