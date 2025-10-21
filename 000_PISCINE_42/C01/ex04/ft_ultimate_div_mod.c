/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:37:16 by pedromig          #+#    #+#             */
/*   Updated: 2025/02/26 19:15:27 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int*b)
{
	int	temp;

	temp = *a / *b;
	*b = *a % *b;
	*a = temp;
}
/*
int	main(void)
{
	int	x = 10;
	int	y = 3;

	printf("Value of '*a': %d\n", x);
	printf("Value of '*b': %d\n", y);

	ft_ultimate_div_mod(&x, &y);
	
	printf("Value of '*a': %d\n", x);
	printf("Value of '*b': %d\n", y);
}
*/
