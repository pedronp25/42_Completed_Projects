/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:23:25 by pedromig          #+#    #+#             */
/*   Updated: 2025/02/22 16:10:59 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_putchar(char c);

void print(int x, int left, int mid, int right)
{
	ft_putchar(left);
	
	while (x > 2)
	{
		ft_putchar(mid);
		x--;
	}

	if (x > 1)
	{
		ft_putchar(right);
	}
	
	ft_putchar('\n');
}

void rush(int x, int y)
{
	if (x > 0 && y > 0)
	{
		print(x, '/', '*', '\\');
		y--;

		while (y > 1)
		{
			print(x, '*', ' ', '*');
			y--;
		}
		
		if (y > 0)
		{
			print(x, '\\', '*', '/');
		}
	}
}
