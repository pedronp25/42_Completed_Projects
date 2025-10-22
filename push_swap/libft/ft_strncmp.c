/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:39:35 by pedromig          #+#    #+#             */
/*   Updated: 2025/04/12 18:37:55 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	x;

	x = 0;
	while (s1[x] && s2[x] && s1[x] == s2[x] && x < n)
		x++;
	if (x == n)
		return (0);
	return ((unsigned char)s1[x] - (unsigned char)s2[x]);
}

/*
#include <string.h>
int	main(int argc, char *argv[])
{
	if (argc == 3)
	{
		char	*str1 = argv[1];
		char	*str2 = argv[2];
		size_t	size = 5;
		printf("Return value of ft_strncmp: %i\n", ft_strncmp(str1, str2, size));
		printf("Return value of strncmp: %i\n", strncmp(str1, str2, size));
	}
}
*/
