/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:19:43 by pedromig          #+#    #+#             */
/*   Updated: 2026/01/14 20:06:53 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	ms_change_dir(t_ms *ms, char *target_dir);
static void	ms_update_pwd_vars(t_ms *ms, char *old_pwd, char *new_pwd);

int	ms_cd(t_ms *ms, char **args)
{
	char	*target_dir;

	if (args[1] && args[2])
	{
		ft_putstr_fd("meow: cd: too many arguments\n", STDERR_FILENO);
		return (1);
	}
	target_dir = ms_get_target_dir(ms, args);
	if (!target_dir)
		return (1);
	return (ms_change_dir(ms, target_dir));
}

static int	ms_change_dir(t_ms *ms, char *target_dir)
{
	char	*old_pwd;
	char	new_pwd[PATH_MAX];

	old_pwd = ms_get_env_value(ms->env_vars, "PWD");
	if (chdir(target_dir) == -1)
		return (ms_chdir_error(target_dir));
	if (getcwd(new_pwd, PATH_MAX) == NULL)
		return (ms_getcwd_error());
	ms_update_pwd_vars(ms, old_pwd, new_pwd);
	return (SUCCESS);
}

static void	ms_update_pwd_vars(t_ms *ms, char *old_pwd, char *new_pwd)
{
	if (old_pwd)
		ms_set_or_update_env_var(ms, "OLDPWD", old_pwd);
	ms_set_or_update_env_var(ms, "PWD", new_pwd);
}
