/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:09:38 by pedromig          #+#    #+#             */
/*   Updated: 2025/06/23 02:59:17 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			x;
	unsigned char	*temp;

	temp = (unsigned char *)s;
	x = 0;
	while (x < n)
	{
		if (temp[x] == (unsigned char)c)
		{
			return ((void *)(temp + x));
		}
		x++;
	}
	return (NULL);
}

/*
int	main(int argc,char *argv[])
{
	if (argc != 3)
		return (1);

	char	*str = argv[1];
	char	chr = argv[2][0];
	size_t	size = 5;

	printf("String: %s\nChar to find: %c\nReturned string: %s\n",
		str,
		chr,
		(char *)ft_memchr(str, chr, size));
}
*/
