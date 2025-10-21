/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 21:14:35 by pedromig          #+#    #+#             */
/*   Updated: 2025/03/11 20:06:48 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	x;
	int	y;

	if (argc > 1)
	{
		x = 1;
		while (x != argc)
		{
			y = 0;
			while (argv[x][y])
			{
				write(1, &argv[x][y], 1);
				y++;
			}
			write(1, "\n", 1);
			x++;
		}
	}
}
