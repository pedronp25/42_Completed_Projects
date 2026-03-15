/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_export_extract_info.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 19:39:38 by pedromig          #+#    #+#             */
/*   Updated: 2026/02/14 19:39:51 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ms_extract_var_name(char *arg)
{
	int	len;

	len = 0;
	while (arg[len] && arg[len] != '=' && arg[len] != '+')
		len++;
	return (ft_substr(arg, 0, len));
}

char	*ms_extract_var_value(char *arg, t_export_mode *mode)
{
	int	x;

	x = 0;
	while (arg[x] && arg[x] != '=' && arg[x] != '+')
		x++;
	if (!arg[x])
	{
		*mode = MODE_NO_VALUE;
		return (NULL);
	}
	if (arg[x] == '+' && arg[x + 1] == '=')
	{
		*mode = MODE_APPEND;
		x += 2;
	}
	else
	{
		*mode = MODE_REPLACE;
		x++;
	}
	if (arg[x])
		return (ft_strdup(&arg[x]));
	return (ft_strdup(""));
}
