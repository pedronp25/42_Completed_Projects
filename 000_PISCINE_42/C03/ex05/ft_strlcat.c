/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 22:38:26 by pedromig          #+#    #+#             */
/*   Updated: 2025/04/10 22:43:41 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *string)
{
	unsigned int	i;

	i = 0;
	while (string[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	dest_len;
	unsigned int	src_len;

	dest_len = ft_strlen(dest);
	x = dest_len;
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	y = 0;
	while (src[y] && x < (size - 1))
	{
		dest[x] = src[y];
		x++;
		y++;
	}
	dest[x] = '\0';
	if (size <= dest_len)
		return (src_len + size);
	else
		return (src_len + dest_len);
}


#include <stdio.h>
#include <bsd/string.h>
int	main(void)
{
	char	a[] = "Hello, ";
	char	b[] = "World!";
	int	size = 9;

	printf("Return value of ft_strlcat: %u\n", ft_strlcat(a, b, size));
	printf("%s\n", a);

	char	c[] = "Hello, ";
	char    d[] = "World!";

	printf("Return value of strlcat: %zu\n", strlcat(c, d, size));
	printf("%s\n", c);
}

