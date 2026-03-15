/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_find_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 22:58:26 by pedromig          #+#    #+#             */
/*   Updated: 2026/03/04 18:52:33 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*search_in_paths(char **paths, char *cmd)
{
	char	*full_path;
	int		x;

	x = 0;
	while (paths[x])
	{
		full_path = build_path(paths[x], cmd);
		if (!full_path)
			return (NULL);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		x++;
	}
	return (NULL);
}

char	*build_path(char *dir, char *cmd)
{
	char	*temp;
	char	*path;

	temp = ft_strjoin(dir, "/");
	if (!temp)
		return (NULL);
	path = ft_strjoin(temp, cmd);
	free(temp);
	return (path);
}

char	*handle_explicit_path(t_ms *ms, char *cmd)
{
	if (access(cmd, F_OK) == -1)
	{
		ms->exit_status = 127;
		return (NULL);
	}
	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	ms->exit_status = 126;
	return (NULL);
}

char	*search_path_env(t_ms *ms, char *cmd, t_env_list *env_vars)
{
	char	*path_env;
	char	**paths;
	char	*full_path;

	path_env = ms_get_env_value(env_vars, "PATH");
	if (!path_env)
	{
		ms->exit_status = 127;
		return (NULL);
	}
	paths = ft_split(path_env, ':');
	if (!paths)
		return (NULL);
	full_path = search_in_paths(paths, cmd);
	free_argv(paths);
	if (!full_path)
		ms->exit_status = 127;
	return (full_path);
}
