/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:05:21 by pedromig          #+#    #+#             */
/*   Updated: 2025/04/14 01:08:23 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			x;
	unsigned char	*temp_d;
	unsigned char	*temp_s;

	if (!dest && !src)
		return (NULL);
	x = 0;
	temp_d = (unsigned char *)dest;
	temp_s = (unsigned char *)src;
	while (x < n)
	{
		temp_d[x] = temp_s[x];
		x++;
	}
	return (dest);
}

/*
int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (1);

	char	*src = argv[1];
	char	*dst;
	size_t	size = 5;

	printf("Destination string: %s", ft_memcpy(dst, src, size));
}
*/
