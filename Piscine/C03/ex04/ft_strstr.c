/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 19:41:03 by pedromig          #+#    #+#             */
/*   Updated: 2025/03/09 20:36:19 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	x;
	int	y;

	x = 0;
	if (!to_find[x])
		return (str);
	while (str[x])
	{
		y = 0;
		while (str[x + y] == to_find[y] && str[x + y])
		{
			if (!to_find[y + 1])
				return (&str[x]);
			y++;
		}
		x++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char    a[] = "This is a very long string.";
	char	b[] = "a lon";

	printf("%s\n", ft_strstr(a, b));

	char	c[] = "This is a very long string.";
	char	d[] = "a lon";

	printf("%s\n", strstr(c, d));
}
*/
