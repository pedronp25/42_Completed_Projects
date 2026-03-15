/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_char_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-te <mjoao-te@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:06:48 by mjoao-te          #+#    #+#             */
/*   Updated: 2026/02/17 15:07:04 by mjoao-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_parser.h"

char	*handle_dollar_char(char *input, int *i,
	t_env_list *env_vars, int last_exit_status)
{
	char	*exp;

	exp = expand_env_var(input, i, env_vars, last_exit_status);
	return (exp);
}

char	*handle_regular_char(char *input, int *i)
{
	char	*result;

	result = ft_substr(input, *i, 1);
	(*i)++;
	return (result);
}
