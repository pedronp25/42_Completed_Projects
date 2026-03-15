/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_executor_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-te <mjoao-te@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 18:18:03 by mjoao-te          #+#    #+#             */
/*   Updated: 2026/02/14 19:45:19 by mjoao-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_builtin	get_builtin_type(char *cmd)
{
	if (!cmd)
		return (BUILTIN_NONE);
	if (ft_strncmp(cmd, "cd", 3) == 0)
		return (BUILTIN_CD);
	if (ft_strncmp(cmd, "pwd", 4) == 0)
		return (BUILTIN_PWD);
	if (ft_strncmp(cmd, "echo", 5) == 0)
		return (BUILTIN_ECHO);
	if (ft_strncmp(cmd, "env", 4) == 0)
		return (BUILTIN_ENV);
	if (ft_strncmp(cmd, "exit", 5) == 0)
		return (BUILTIN_EXIT);
	if (ft_strncmp(cmd, "unset", 6) == 0)
		return (BUILTIN_UNSET);
	if (ft_strncmp(cmd, "export", 7) == 0)
		return (BUILTIN_EXPORT);
	return (BUILTIN_NONE);
}

int	ms_print_file_error(int exit_status, char *cmd, bool has_slash)
{
	ft_putstr_fd("meow: ", STDERR_FILENO);
	if (!cmd || !cmd[0])
		ft_putstr_fd("\'\'", STDERR_FILENO);
	else
		ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	if (has_slash)
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
	else
		ft_putstr_fd("command not found", STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	return (exit_status);
}

int	ms_extract_exit_status(int status)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	return (1);
}
