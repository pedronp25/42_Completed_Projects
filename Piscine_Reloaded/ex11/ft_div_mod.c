/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:21:34 by pedromig          #+#    #+#             */
/*   Updated: 2025/04/02 17:27:15 by pedromig         ###   ########.fr       */
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
	printf("a: %i\n", x);
	printf("b: %i\n", y);
	printf("div: %i\n", d);
	printf("mod: %i\n", m);
}
*/
