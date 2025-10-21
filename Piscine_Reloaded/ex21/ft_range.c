/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:40:12 by pedromig          #+#    #+#             */
/*   Updated: 2025/04/03 17:15:09 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	x;
	int	*arr;

	if (min >= max)
		return (NULL);
	arr = malloc((max - min) * sizeof(int));
	if (arr == NULL)
		return (NULL);
	x = 0;
	while (min < max)
	{
		arr[x] = min;
		x++;
		min++;
	}
	return (arr);
}

/*
#include <stdio.h>
int	sort_of_atoi(char *ascii);

int	main(int argc, char *argv[])
{
	if (argc == 3)
	{
		int	x = 0;
		int	min = sort_of_atoi(argv[1]);
		int	max = sort_of_atoi(argv[2]);
		int	*arr = ft_range(min, max);

		while (min < max)
		{
			printf("%i\n", arr[x]);
			x++;
			min++;
		}
	}
}

int	sort_of_atoi(char *ascii)
{
	int	x;
	int	res = 0;
	int	neg = 0;

	x = 0;

	if (ascii[x] == '-')
	{
		neg = 1;
		x++;
	}

	while (ascii[x] >= '0' && ascii[x] <= '9')
	{
		res = (ascii[x] - '0') + res * 10;
		x++;
	}

	if (neg == 1)
		res = -res;

	return (res);
}
*/
