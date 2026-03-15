/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_helpers2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 17:44:44 by pedromig          #+#    #+#             */
/*   Updated: 2025/10/11 22:29:13 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ph_print(t_philo *philos, int id, char *msg)
{
	pthread_mutex_lock(&philos->data->print_mutex);
	if (!ph_get_sim_over(philos->data))
		printf("%ld %i %s\n", ph_elapsedtime(philos), id, msg);
	pthread_mutex_unlock(&philos->data->print_mutex);
}

int	ph_get_sim_over(t_data *data)
{
	int	ret;

	pthread_mutex_lock(&data->death_mutex);
	ret = data->simulation_over;
	pthread_mutex_unlock(&data->death_mutex);
	return (ret);
}

void	ph_set_sim_over(t_data *data)
{
	pthread_mutex_lock(&data->death_mutex);
	data->simulation_over = 1;
	pthread_mutex_unlock(&data->death_mutex);
}

long	ph_get_time_last_meal(t_philo *philos)
{
	long	time;

	pthread_mutex_lock(&philos->meal_mutex);
	time = philos->time_last_meal;
	pthread_mutex_unlock(&philos->meal_mutex);
	return (time);
}

void	ph_set_time_last_meal(t_philo *philos, long new_time)
{
	pthread_mutex_lock(&philos->meal_mutex);
	philos->time_last_meal = new_time;
	pthread_mutex_unlock(&philos->meal_mutex);
}
