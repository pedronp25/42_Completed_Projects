/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:57:56 by pedromig          #+#    #+#             */
/*   Updated: 2025/03/09 14:31:05 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	x;
	int	y;

	x = 0;
	while (dest[x])
		x++;
	y = 0;
	while (src[y])
	{
		dest[x] = src[y];
		x++;
		y++;
	}
	dest[x] = '\0';
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	a[] = "Isto é o início. ";
	char	b[] = "And this is the end.";

	printf("%s\n", ft_strcat(a, b));

	char	c[] = "Isto é o início. ";
	char	d[] = "And this is the end.";

	printf("%s\n", strcat(c, d));
}
*/
