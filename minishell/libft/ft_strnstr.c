/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 23:27:08 by pedromig          #+#    #+#             */
/*   Updated: 2025/04/12 19:39:14 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	x;
	size_t	y;

	x = 0;
	if (little[0] == '\0')
		return ((char *)&big[x]);
	while (big[x] && x < len)
	{
		y = 0;
		while (big[x + y] == little[y] && big[x + y] && (x + y) < len)
		{
			if (!little[y + 1])
				return ((char *)&big[x]);
			y++;
		}
		x++;
	}
	return (NULL);
}

/*
#define BUF_SIZE 10
#include <bsd/string.h>
int	main(void)
{
	char	a1[] = "This is a very long string.";
	char	a2[] = "This is a very long string.";

	char	b1[] = "";
	char	b2[] = "";

	printf("Return value of ft_strnstr: %s\n\n", ft_strnstr(a1, b1, BUF_SIZE));
//	printf("Return value of strnstr: %s\n", strnstr(a2, b2, BUF_SIZE));
}
*/
