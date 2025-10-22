/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 22:14:28 by pedromig          #+#    #+#             */
/*   Updated: 2025/04/11 23:01:29 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	x;
	char	*temp;

	x = 0;
	temp = s;
	while (x < n)
	{
		temp[x] = (unsigned char)c;
		x++;
	}
	return (s);
}

/*
int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (1);

	char	*str = argv[1];
	
	printf("ft_memset return: %s", str);
	printf("memset return: %s", str);
}
*/
