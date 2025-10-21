/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:23:39 by pedromig          #+#    #+#             */
/*   Updated: 2025/03/02 15:46:51 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*
#include <stdio.h>
int	main(void)
{
	int	x = 10;
	int	y = 3;
	int	d;
	int	m;

	ft_div_mod(x, y, &d, &m);

	printf("Value of 'a': %i\n", x);
	printf("Value of 'b': %i\n", y);
	printf("Value of 'div': %d\n", d);
	printf("Value of 'mod': %d\n", m);
}
*/
