/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 03:31:29 by pedromig          #+#    #+#             */
/*   Updated: 2025/04/10 02:32:55 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	x;

	x = 0;
	while (s[x])
		x++;
	return (x);
}

/*
int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		printf("Length of %s: %zu", argv[1], ft_strlen(argv[1]));
	}
}
*/
