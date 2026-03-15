/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_helpers3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 17:44:54 by pedromig          #+#    #+#             */
/*   Updated: 2025/10/11 18:08:22 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ph_get_meals_eaten(t_philo *philos)
{
	int	meals;

	pthread_mutex_lock(&philos->meal_mutex);
	meals = philos->meals_eaten;
	pthread_mutex_unlock(&philos->meal_mutex);
	return (meals);
}

void	ph_inc_meals_eaten(t_philo *philos)
{
	pthread_mutex_lock(&philos->meal_mutex);
	philos->meals_eaten++;
	pthread_mutex_unlock(&philos->meal_mutex);
}

void	ph_set_meals_eaten(t_philo *philos, int value)
{
	pthread_mutex_lock(&philos->meal_mutex);
	philos->meals_eaten = value;
	pthread_mutex_unlock(&philos->meal_mutex);
}

int	ph_is_dead(t_philo *philos)
{
	long	time_since_meal;
	int		ret;

	pthread_mutex_lock(&philos->meal_mutex);
	time_since_meal = ph_elapsedtime(philos) - philos->time_last_meal;
	if (time_since_meal >= philos->data->time_die)
		ret = 1;
	else
		ret = 0;
	pthread_mutex_unlock(&philos->meal_mutex);
	return (ret);
}
