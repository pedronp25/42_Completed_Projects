/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 23:54:47 by pedromig          #+#    #+#             */
/*   Updated: 2026/01/18 19:39:30 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_exit_error	ms_check_exit_args(char **args);
static bool			is_arg_num(char *arg);
static bool			is_long_overflow(char *arg);
static void			actual_exit(t_ms *ms, t_exit_error error_type, char *arg);

void	ms_exit(t_ms *ms, char **args)
{
	t_exit_error	error_type;

	error_type = ms_check_exit_args(args);
	if (error_type == NORMAL_ARGS)
		ms->exit_status = ft_atol(args[1]);
	else if (error_type != NO_ARGS)
		ms->exit_status = error_type;
	actual_exit(ms, error_type, args[1]);
}

static t_exit_error	ms_check_exit_args(char **args)
{
	t_exit_error	error_type;

	if (!args || !args[1])
		error_type = NO_ARGS;
	else if (!is_arg_num(args[1]) || is_long_overflow(args[1]))
		error_type = NOT_NUMERIC;
	else if (args[2])
		error_type = TOO_MANY_ARGS;
	else
		error_type = NORMAL_ARGS;
	return (error_type);
}

static bool	is_arg_num(char *arg)
{
	int	x;

	if (!arg || !arg[0])
		return (false);
	x = 0;
	while (arg[x] && ft_strchr(WHITESPACE, arg[x]))
		x++;
	if (arg[x] == '-' || arg[x] == '+')
		x++;
	while (arg[x])
	{
		if (!ft_isdigit(arg[x]))
			return (false);
		x++;
	}
	return (true);
}

static bool	is_long_overflow(char *arg)
{
	int		x;
	size_t	num_len;
	char	*long_max;

	x = 0;
	while (arg[x] && ft_strchr(WHITESPACE, arg[x]))
		x++;
	if (arg[x] == '-')
		long_max = "9223372036854775808";
	else
		long_max = "9223372036854775807";
	if (arg[x] == '-' || arg[x] == '+')
		x++;
	while (arg[x] == '0')
		x++;
	num_len = 0;
	while (ft_isdigit(arg[x + num_len]))
		num_len++;
	if ((num_len == ft_strlen(long_max)
			&& ft_strncmp(&arg[x], long_max, num_len) > 0)
		|| num_len > ft_strlen(long_max))
		return (true);
	return (false);
}

static void	actual_exit(t_ms *ms, t_exit_error error_type, char *arg)
{
	if (!ms->in_child && ms->is_interactive)
		ft_putstr_fd("exit\n", STDERR_FILENO);
	if (error_type == TOO_MANY_ARGS)
	{
		ft_putstr_fd("meow: exit: too many arguments\n",
			STDERR_FILENO);
		if (!ms->in_child)
			return ;
	}
	else if (error_type == NOT_NUMERIC)
	{
		ft_putstr_fd("meow: exit: ", STDERR_FILENO);
		ft_putstr_fd(arg, STDERR_FILENO);
		ft_putstr_fd(" : numeric argument required\n", STDERR_FILENO);
	}
	exit(ms->exit_status);
}
