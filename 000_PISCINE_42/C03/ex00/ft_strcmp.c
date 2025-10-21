/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 22:39:56 by pedromig          #+#    #+#             */
/*   Updated: 2025/03/09 14:24:24 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	x;

	x = 0;
	while (s1[x] && s2[x] && s1[x] == s2[x])
		x++;
	return (s1[x] - s2[x]);
}

/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	*a = "This string has a b";
	char	*b = "This string has a c";

	printf("The return of ft_strcmp: %i\n", ft_strcmp(a, b));
	printf("The return of strcmp: %i\n", strcmp(a, b));
}
*/
