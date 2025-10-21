/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 23:00:31 by pedromig          #+#    #+#             */
/*   Updated: 2025/03/09 20:38:59 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	x;

	x = 0;
	while (s1[x] && s2[x] && s1[x] == s2[x] && x < n)
		x++;
	if (x == n)
		return (0);
	return (s1[x] - s2[x]);
}

/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	*a = "a";
	char	b[1] = {'a'};
	int	bytes = 0;

	printf("The return of ft_strncmp: %i\n", ft_strncmp(a, b, bytes));
	printf("The return of strncmp: %i\n", strncmp(a, b, bytes));
}
*/
