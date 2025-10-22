/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:35:45 by pedromig          #+#    #+#             */
/*   Updated: 2025/04/11 21:50:04 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	x;

	x = 0;
	if (!(char)c)
		return ((char *)&s[ft_strlen(s)]);
	while (s[x])
	{
		if (s[x] == (char)c)
			return ((char *)&s[x]);
		x++;
	}
	return (NULL);
}

/*
int	main(int argc, char *argv[])
{
	if (argc == 3)
	{
		printf("%c\n", *ft_strchr(argv[1], argv[2][0]));
	}
}
*/
