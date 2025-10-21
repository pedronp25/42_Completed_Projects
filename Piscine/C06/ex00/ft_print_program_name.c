/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:53:01 by pedromig          #+#    #+#             */
/*   Updated: 2025/03/12 21:57:54 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	x;

	if (argc > 0)
	{
		x = 0;
		while (argv[0][x])
		{
			write(1, &argv[0][x], 1);
			x++;
		}
		write(1, "\n", 1);
	}
}
