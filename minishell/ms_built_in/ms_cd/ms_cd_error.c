/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cd_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 23:40:22 by pedromig          #+#    #+#             */
/*   Updated: 2026/02/14 23:40:31 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ms_chdir_error(char *path)
{
	ft_putstr_fd("meow: cd: ", STDERR_FILENO);
	ft_putstr_fd(path, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(strerror(errno), STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	return (1);
}

int	ms_getcwd_error(void)
{
	ft_putstr_fd("meow: cd: error retrieving current directory\n",
		STDERR_FILENO);
	return (1);
}
