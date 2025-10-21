/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 19:59:26 by pedromig          #+#    #+#             */
/*   Updated: 2025/03/05 17:11:01 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	x;

	x = 0;
	while (x < (size - 1) && src[x])
	{
		dest[x] = src[x];
		x++;
	}
	dest[x] = '\0';
	while (src[x])
		x++;
	return (x);
}

/*
#include <stdio.h>
#include <bsd/string.h>
int	main(void)
{
	char	a[] = "Olá, muito boa tarde!";
	char	b[3];

	printf("Size of source string: %u\n", ft_strlcpy(b, a, sizeof(b)));
	printf("Copied string: %s\n", b);
}
*/
