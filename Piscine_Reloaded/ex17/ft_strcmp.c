/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:10:02 by pedromig          #+#    #+#             */
/*   Updated: 2025/04/02 18:22:04 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	x;

	x = 0;
	while (s1[x] && s2[x] && s1[x] == s2[x])
		x++;
	return (s1[x] - s2[x]);
}

/*
#include <stdio.h>
#include <string.h>
int	main(int argc, char *argv[])
{
	if (argc == 3)
	{
		printf("ft_strcmp: %i\n", ft_strcmp(argv[1], argv[2]));
		printf("strcmp: %i\n", strcmp(argv[1], argv[2]));
	}
}
*/
