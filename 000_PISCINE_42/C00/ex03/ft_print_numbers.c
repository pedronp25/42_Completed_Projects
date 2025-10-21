/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:52:03 by pedromig          #+#    #+#             */
/*   Updated: 2025/02/23 18:27:07 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	char	y;

	y = '0';
	while (y <= '9')
	{
		write(1, &y, 1);
		y++;
	}
}

/*
int	main(void)
{
	ft_print_numbers();
}
*/
