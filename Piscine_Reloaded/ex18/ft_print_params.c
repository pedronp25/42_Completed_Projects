/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:22:29 by pedromig          #+#    #+#             */
/*   Updated: 2025/04/03 17:30:16 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

int	main(int argc, char *argv[])
{
	int	x;
	int	y;

	if (argc > 1)
	{
		x = 1;
		while (argv[x])
		{
			y = 0;
			while (argv[x][y])
			{
				ft_putchar(argv[x][y]);
				y++;
			}
			x++;
			ft_putchar('\n');
		}
	}
}

/*
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
*/
