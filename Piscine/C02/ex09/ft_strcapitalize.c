/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 23:17:03 by pedromig          #+#    #+#             */
/*   Updated: 2025/03/05 21:01:08 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_alphanum(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (1);
	else if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	x;

	x = 0;
	while (str[x])
	{
		if (str[x] >= 'A' && str[x] <= 'Z')
			str[x] += 32;
		x++;
	}
	x = 0;
	if (str[x] >= 'a' && str[x] <= 'z')
		str[x] -= 32;
	while (str[x])
	{
		if (ft_is_alphanum(str[x]) == 0
			&& (str[x + 1] >= 'a' && str[x + 1] <= 'z'))
		{
			str[x + 1] = str[x + 1] - 32;
		}
		x++;
	}
	return (str);
}

/*
#include <stdio.h>
int	main(void)
{
	char	a[] = "salut, comment tu VAS ?
	 42mots quarante-deux; cinquante+et+un";

	printf("%s\n", ft_strcapitalize(a));
}
*/
