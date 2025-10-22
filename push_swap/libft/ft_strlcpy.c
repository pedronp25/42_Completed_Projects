/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:52:07 by pedromig          #+#    #+#             */
/*   Updated: 2025/04/10 18:56:46 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	x;

	if (size <= 0)
		return (ft_strlen(src));
	x = 0;
	while (src[x] && x < (size - 1))
	{
		dst[x] = src[x];
		x++;
	}
	dst[x] = '\0';
	return (ft_strlen(src));
}

/*
#include <bsd/string.h>
int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		char	dst1[0];
		char	dst2[0];
		const char *src = argv[1];
		size_t	BUF_SIZE = 50;

		size_t	r_val1 = ft_strlcpy(dst1, src, BUF_SIZE);
		size_t	r_val2 = strlcpy(dst2, src, BUF_SIZE);

		printf("size of source: %zu\n", ft_strlen(src));
		printf("Destination string for ft_strlcpy: %s\n", dst1);
		printf("Return value of ft_strlcpy: %zu\n", r_val1);

		printf("\n");

		printf("size of source: %zu\n", ft_strlen(src));
		printf("Destination string for strlcpy: %s\n", dst2);
		printf("Return value of strlcpy: %zu\n", r_val2);
	}
}
*/
