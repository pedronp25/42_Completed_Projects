/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 23:12:25 by pedromig          #+#    #+#             */
/*   Updated: 2025/03/05 16:23:37 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	x;

	x = 0;
	while (str[x])
	{
		if (str[x] >= 'A' && str[x] <= 'Z')
		{
			str[x] += 32;
		}
		x++;
	}
	return (str);
}

/*
#include <stdio.h>
int	main(void)
{
	char	a[] = "tHIS IS ANOTHER TEST.";

	printf("%s\n", a);

	printf("%s\n", ft_strlowcase(a));
}
*/
