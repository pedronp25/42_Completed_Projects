/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:51:33 by pedromig          #+#    #+#             */
/*   Updated: 2025/04/14 01:09:27 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			x;
	unsigned char	*temp1;
	unsigned char	*temp2;

	temp1 = (unsigned char *)s1;
	temp2 = (unsigned char *)s2;
	x = 0;
	while (x < n && temp1[x] == temp2[x])
		x++;
	if (x == n)
		return (0);
	return (temp1[x] - temp2[x]);
}

/*
#include <string.h>
int	main(int argc, char *argv[])
{
	if (argc != 3)
		return (1);

	char	*str1 = argv[1];
	char	*str2 = argv[2];
	size_t size = 3;
	printf("Return value of ft_memcmp: %i\n", ft_memcmp(str1, str2, size));
	printf("Return value of memcmp: %i\n", memcmp(str1, str2, size));
}
*/
