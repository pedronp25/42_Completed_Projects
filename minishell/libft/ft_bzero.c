/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 23:27:25 by pedromig          #+#    #+#             */
/*   Updated: 2025/04/11 23:01:29 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	size_t	x;
	char	*temp;

	x = 0;
	temp = s;
	while (x < n)
	{
		temp[x] = '\0';
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
