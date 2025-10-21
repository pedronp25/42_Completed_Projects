/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 04:09:14 by pedromig          #+#    #+#             */
/*   Updated: 2025/04/05 18:53:54 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int (*f)(char*))
{
	int	x;
	int	count;

	x = 0;
	count = 0;
	while (tab[x])
	{
		if ((*f)(tab[x]) == 1)
		{
			count++;
		}
		x++;
	}
	return (count);
}

/*
int	is_lower(char *arr)
{
	int	x;

	x = 0;
	while (arr[x])
	{
		if (arr[x] >= 65 && arr[x] <= 90)
			return (0);
		x++;
	}
	return (1);
}


#include <stdio.h>
int	main(int argc, char *argv[])
{
	if (argc)
	{
		printf("%i", ft_count_if(argv+1, &is_lower));
	}
}
*/
