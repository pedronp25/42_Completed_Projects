/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:39:41 by pedromig          #+#    #+#             */
/*   Updated: 2025/04/14 01:09:03 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*temp_d;
	unsigned char	*temp_s;

	if (dest < src)
		return (ft_memcpy(dest, src, n));
	if (!dest && !src)
		return (NULL);
	temp_d = (unsigned char *)dest;
	temp_s = (unsigned char *)src;
	while (n)
	{
		temp_d[n - 1] = temp_s[n - 1];
		n--;
	}
	return (dest);
}

/*
int     main(int argc, char *argv[])
{
	if (argc != 2)
		return (1);

	char    *src = argv[1];
	char    *dst = &argv[1][1];
	size_t  size = 5;

	printf("Destination string: %s", (char *)ft_memmove(dst, src, size));
}
*/
