/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_var_expander.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-te <mjoao-te@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:10:06 by mjoao-te          #+#    #+#             */
/*   Updated: 2026/02/17 17:10:48 by mjoao-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_parser.h"
#include "../minishell.h"

static int	find_var_end(char *input, int pos)
{
	while (input[pos] && (ft_isalnum(input[pos]) || input[pos] == '_'))
		pos++;
	return (pos);
}

static char	*expand_named_var(char *input, int *i, t_env_list *env_vars)
{
	int		end;
	char	*name;
	char	*value;

	end = find_var_end(input, *i + 1);
	name = ft_substr(input, *i + 1, end - (*i + 1));
	if (!name)
		return (NULL);
	value = ms_get_env_value(env_vars, name);
	free(name);
	*i = end;
	if (!value)
		return (NULL);
	return (ft_strdup(value));
}

char	*expand_env_var(char *input, int *i, t_env_list *env_vars,
	int last_exit_status)
{
	if (input[*i + 1] == '?')
	{
		(*i) += 2;
		return (get_exit_status_as_str(last_exit_status));
	}
	if (!(ft_isalnum(input[*i + 1]) || input[*i + 1] == '_'))
	{
		(*i)++;
		return (ft_strdup("$"));
	}
	return (expand_named_var(input, i, env_vars));
}
