/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 22:27:52 by pedromig          #+#    #+#             */
/*   Updated: 2025/03/09 23:43:35 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	x;
	int	*array;

	if (min >= max)
		return (NULL);

	array = malloc(sizeof(int) * (max - min));
	if (array == NULL)
		return (array);

	x = 0;
	while (min < max)
	{
		array[x] = min;
		x++;
		min++;
	}
	return (array);
}


#include <stdio.h>
int	main(void)
{
	int	x;
	int	max = 43;
	int	min = -43;
	int	*a = ft_range(min, max);

	x = 0;
	if (!a)
		return (1);
	while (x < (max - min))
	{
		printf("%i\n", a[x]);
		x++;
	}
	free(a);
}
