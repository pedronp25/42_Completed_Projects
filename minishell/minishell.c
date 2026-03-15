/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 22:53:16 by pedromig          #+#    #+#             */
/*   Updated: 2026/01/18 21:11:31 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	main_loop(t_ms *ms, char *input);

int	main(int argc, char **argv, char **envp)
{
	char	*input;
	t_ms	ms;

	ft_bzero(&ms, sizeof(t_ms));
	if (argc != 1 && !argv[1])
	{
		ft_putstr_fd("Too many arguments!\nUsage: ./minishell", STDERR_FILENO);
		exit(1);
	}
	ms.is_interactive = isatty(STDIN_FILENO);
	init_signal_handlers();
	ms.env_vars = ms_init_env_vars(envp);
	while (1)
	{
		input = ms_get_input();
		main_loop(&ms, input);
	}
}

static void	main_loop(t_ms *ms, char *input)
{
	if (consume_signal_exit_status() != 0)
		ms->exit_status = 130;
	if (!input)
	{
		ft_printf("exit\n");
		exit(ms->exit_status);
		return ;
	}
	if (*input)
	{
		ms->command_table = run_parser(input, ms->env_vars, ms->exit_status);
		if (ms->command_table)
		{
			if (ms_preprocess_heredocs(ms->command_table) == 0)
				ms_execute_command_table(ms);
			free_command_table(ms->command_table);
			ms->command_table = NULL;
		}
		add_history(input);
	}
	free(input);
}

char	*ms_get_input(void)
{
	char	*input;

	input = readline("\001\e[1;31m\002 meow🙀shell> \001\e[0m\002");
	return (input);
}

t_env_list	*ms_init_env_vars(char **envp)
{
	t_env_list	*env_vars;
	t_env_list	*new_node;
	int			x;

	if (!envp || !envp[0])
		return (NULL);
	env_vars = NULL;
	x = 0;
	while (envp[x])
	{
		new_node = ms_lstnewnode(ft_strdup(envp[x]));
		if (!new_node)
		{
			ms_lstclear(&env_vars);
			return (NULL);
		}
		ms_lstaddback(&env_vars, new_node);
		x++;
	}
	return (env_vars);
}
