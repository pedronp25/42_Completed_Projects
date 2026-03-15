/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 19:13:56 by pedromig          #+#    #+#             */
/*   Updated: 2026/01/14 20:12:30 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static bool	is_option_n(char *arg);

int	ms_echo(char **args)
{
	int		x;
	bool	option_n;

	x = 1;
	option_n = false;
	while (args[x] && is_option_n(args[x]))
	{
		option_n = true;
		x++;
	}
	while (args[x])
	{
		ft_putstr_fd(args[x], 1);
		x++;
		if (args[x])
			ft_putchar_fd(' ', 1);
	}
	if (!option_n)
		ft_putchar_fd('\n', 1);
	return (SUCCESS);
}

static bool	is_option_n(char *arg)
{
	int	x;

	x = 0;
	if (!arg)
		return (false);
	if (arg[x] != '-')
		return (false);
	x = 1;
	while (arg[x])
	{
		if (arg[x] != 'n')
			return (false);
		x++;
	}
	return (true);
}
