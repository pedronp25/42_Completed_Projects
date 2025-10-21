/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:05:08 by pedromig          #+#    #+#             */
/*   Updated: 2025/03/08 18:01:54 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	x;

	x = 0;
	while (str[x])
		x++;
	return (x);
}

/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	a[] = "This has 23 characters.";

	printf("The string has %i characters.", ft_strlen(a));
}
*/
