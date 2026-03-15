/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_init_validate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 17:03:12 by pedromig          #+#    #+#             */
/*   Updated: 2025/10/15 22:26:43 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ph_init_data(int argc, char **argv, t_data *data)
{
	int		x;

	if (!ph_validate_arguments(argc, argv, data))
		return (0);
	data->start_time = 0;
	pthread_mutex_init(&data->print_mutex, NULL);
	pthread_mutex_init(&data->death_mutex, NULL);
	x = 0;
	while (x < data->n_philos)
	{
		pthread_mutex_init(&data->forks[x], NULL);
		x++;
	}
	data->simulation_over = 0;
	return (1);
}

int	ph_validate_arguments(int argc, char **argv, t_data *data)
{
	if (argc != 5 && argc != 6)
		return (0);
	if (ph_atol(argv[1]) > 200 || !ph_is_digit(argv[1]) || !ph_is_digit(argv[2])
		|| !ph_is_digit(argv[3]) || !ph_is_digit(argv[4]))
		return (0);
	data->n_philos = ph_atol(argv[1]);
	data->time_die = ph_atol(argv[2]);
	data->time_eat = ph_atol(argv[3]);
	data->time_sleep = ph_atol(argv[4]);
	if (argc == 6)
	{
		if (!ph_is_digit(argv[5]) || ph_atol(argv[5]) == -1)
			return (0);
		data->n_meals = ph_atol(argv[5]);
	}
	else
		data->n_meals = -1;
	if (data->n_philos <= 0 || data->time_die <= 0
		|| data->time_eat <= 0 || data->time_sleep <= 0)
		return (0);
	return (1);
}

void	ph_init_philos(t_data *data, t_philo *philos)
{
	int		x;

	x = 0;
	while (x < data->n_philos)
	{
		philos[x].id = x + 1;
		philos[x].meals_eaten = 0;
		philos[x].left_fork = &data->forks[x];
		philos[x].right_fork = &data->forks[(x + 1) % data->n_philos];
		pthread_mutex_init(&philos[x].meal_mutex, NULL);
		philos[x].data = data;
		philos[x].time_last_meal = 0;
		x++;
	}
}
