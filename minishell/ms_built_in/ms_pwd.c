/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 22:14:45 by pedromig          #+#    #+#             */
/*   Updated: 2025/12/29 19:14:21 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// Print working directory
int	ms_pwd(void)
{
	char	current_directory[PATH_MAX];

	if (getcwd(current_directory, PATH_MAX))
	{
		ft_putstr_fd(current_directory, 1);
		ft_putchar_fd('\n', 1);
		return (SUCCESS);
	}
	else
		return (ERROR);
}
