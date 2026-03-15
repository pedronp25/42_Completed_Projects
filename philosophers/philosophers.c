/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 22:39:46 by pedromig          #+#    #+#             */
/*   Updated: 2025/10/11 18:14:13 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	print_usage_error(void);

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	philos[200];

	if (argc == 1 || !argv[1])
		print_usage_error();
	if (!ph_init_data(argc, argv, &data))
		return (1);
	ph_init_philos(&data, philos);
	data.start_time = ph_gettime_ms();
	ph_create_threads(philos);
	ph_join_threads(philos);
	ph_cleanup(philos);
	return (0);
}

void	ph_cleanup(t_philo *philos)
{
	int	x;

	x = 0;
	while (x < philos->data->n_philos)
	{
		pthread_mutex_destroy(&philos->data->forks[x]);
		pthread_mutex_destroy(&philos[x].meal_mutex);
		x++;
	}
	pthread_mutex_destroy(&philos->data->print_mutex);
	pthread_mutex_destroy(&philos->data->death_mutex);
}

static void	print_usage_error(void)
{
		write(1, "\033[0;31mERROR!\033[0m\nUsage: \n", 27);
		write(1, " ./philo n_philos time_die time_eat time_sleep", 47);
		write(1, " max_n_times_philos_eat[optional]\n", 35);
}