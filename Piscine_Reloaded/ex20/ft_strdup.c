/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 22:51:02 by pedromig          #+#    #+#             */
/*   Updated: 2025/04/03 17:32:45 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char	*str)
{
	int	x;

	x = 0;
	while (str[x])
		x++;
	return (x);
}

char	*ft_strdup(char *src)
{
	int		x;
	char	*dest;

	dest = malloc(ft_strlen(src) + 1);
	if (dest == NULL)
		return (NULL);
	x = 0;
	while (src[x])
	{
		dest[x] = src[x];
		x++;
	}
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>
int	main(int argc, char *argv[])
{
	if (argc > 1)
	{
		printf("ft_strdup: %s\n", ft_strdup(argv[1]));
		printf("strdup: %s\n", strdup(argv[1]));
	}
}
*/
