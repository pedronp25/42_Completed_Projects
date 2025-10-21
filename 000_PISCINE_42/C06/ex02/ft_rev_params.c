/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 21:22:47 by pedromig          #+#    #+#             */
/*   Updated: 2025/03/12 21:06:24 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	x;
	int	y;

	if (argc > 1)
	{
		x = argc - 1;
		while (x > 0)
		{
			y = 0;
			while (argv[x][y])
			{
				write(1, &argv[x][y], 1);
				y++;
			}
			write(1, "\n", 1);
			x--;
		}
	}
}
