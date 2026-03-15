/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_executor_builtin.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 22:20:04 by pedromig          #+#    #+#             */
/*   Updated: 2026/02/23 22:20:16 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ms_execute_builtin(t_ms *ms, char **args)
{
	t_builtin	type;

	type = get_builtin_type(args[0]);
	if (type == BUILTIN_PWD)
		ms->exit_status = ms_pwd();
	else if (type == BUILTIN_CD)
		ms->exit_status = ms_cd(ms, args);
	else if (type == BUILTIN_ECHO)
		ms->exit_status = ms_echo(args);
	else if (type == BUILTIN_ENV)
		ms->exit_status = ms_env(ms->env_vars);
	else if (type == BUILTIN_EXIT)
		ms_exit(ms, args);
	else if (type == BUILTIN_UNSET)
		ms->exit_status = ms_unset(&ms->env_vars, args);
	else if (type == BUILTIN_EXPORT)
		ms->exit_status = ms_export(ms, args);
	else
	{
		ft_printf("meow: %s: command not found\n", args[0]);
		ms->exit_status = 127;
	}
	return (ms->exit_status);
}
