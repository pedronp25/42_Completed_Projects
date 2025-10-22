/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 00:22:41 by pedromig          #+#    #+#             */
/*   Updated: 2025/04/14 00:49:28 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	x;

	x = 0;
	while (s[x])
	{
		f(x, &s[x]);
		x++;
	}
}

/*
void	ft_rot_13(unsigned int i, char *c)
{
	if ((*c >= 'A' && *c <= 'M') || (*c >= 'a' && *c <= 'm'))
		*c += 13;
	else if ((*c >= 'N' && *c <= 'Z') || (*c >= 'n' && *c <= 'z'))
		*c -= 13;
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (1);

	char	*meow = argv[1];

	ft_striteri(meow, ft_rot_13);

	printf("Returned String: %s\n", meow);
}
*/
