/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 21:57:30 by pedromig          #+#    #+#             */
/*   Updated: 2025/03/09 22:22:49 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	x;

	x = 0;
	while (str[x])
		x++;
	return (x);
}

char	*ft_strcopy(char *dest, char *str)
{
	int	x;

	x = 0;
	while (str[x])
	{
		dest[x] = str[x];
		x++;
	}
	dest[x] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	int	x;
	char	*copy;

	copy  = malloc(ft_strlen(src) + 1);
	ft_strcopy(copy, src);
	return (copy);
}


#include <stdio.h>
int	main(void)
{
	char	a[] = "String linda!";

	printf("%s\n", ft_strdup(a));
}
