/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_helpers1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 15:52:30 by pedromig          #+#    #+#             */
/*   Updated: 2025/10/11 18:12:33 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

long	ph_gettime_ms(void)
{
	struct timeval	time;
	long			time_in_ms;

	gettimeofday(&time, NULL);
	time_in_ms = time.tv_sec * 1000L + time.tv_usec / 1000L;
	return (time_in_ms);
}

long	ph_elapsedtime(t_philo *philos)
{
	long	elapsed_time;

	elapsed_time = ph_gettime_ms() - philos->data->start_time;
	return (elapsed_time);
}

void	ph_usleep(long time)
{
	long	start;

	start = ph_gettime_ms();
	while ((ph_gettime_ms() - start) < time)
		usleep(1000);
}

int	ph_is_digit(char *num)
{
	int	x;

	x = 0;
	while (num[x])
	{
		if (num[x] < '0' || num[x] > '9')
			return (0);
		x++;
	}
	return (1);
}

long	ph_atol(char *str)
{
	long	result;
	int		digit;
	int		x;

	result = 0;
	x = 0;
	while (str[x])
	{
		digit = str[x] - '0';
		if (result > (LONG_MAX - digit) / 10)
			return (-1);
		result = result * 10 + (str[x] - '0');
		x++;
	}
	return (result);
}
