/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 21:18:12 by pedromig          #+#    #+#             */
/*   Updated: 2025/04/11 21:52:07 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	x;
	size_t	y;

	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	x = dest_len;
	y = 0;
	if (size == 0)
		return (src_len);
	while (src[y] && x < (size - 1))
	{
		dst[x] = src[y];
		x++;
		y++;
	}
	dst[x] = '\0';
	if (size <= dest_len)
		return (src_len + size);
	else
		return (src_len + dest_len);
}

/*
#define BUF_SIZE 9
#include <bsd/string.h>
int	main(void)
{
	char	d1[] = "Hello, ";
	//char	d2[] = "Hello, ";

	char	s1[] = "World!";
	//char	s2[] = "World!";

	//size_t	r_val2 = strlcat(d2, s2, BUF_SIZE);
	size_t	r_val1 = ft_strlcat(d1, s1, BUF_SIZE);


	printf("FT_STRLCAT:\nDestination String: %s\nReturn Value: %zu\n\n",
		d1, r_val1);
		
	//printf("STRLCAT:\nDestination String: %s\nReturn Value: %zu\n\n",
		d2, r_val2);

	return(0);
}
*/
