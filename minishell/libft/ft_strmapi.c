/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 23:49:43 by pedromig          #+#    #+#             */
/*   Updated: 2025/04/14 01:07:16 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		x;
	char	*str;

	str = malloc(ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	x = 0;
	while (s[x])
	{
		str[x] = f(x, s[x]);
		x++;
	}
	str[x] = '\0';
	return (str);
}

/*
char	ft_rot_13(unsigned int x, char c)
{
	if ((c >= 'A' && c <= 'M') || (c >= 'a' && c <= 'm'))
		c += 13;
	else if ((c >= 'N' && c <= 'Z') || (c >= 'n' && c <= 'z'))
		c -= 13;
	return (c);
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (1);

	printf("Returned String: %s\n", ft_strmapi(argv[1], ft_rot_13));
}
*/
