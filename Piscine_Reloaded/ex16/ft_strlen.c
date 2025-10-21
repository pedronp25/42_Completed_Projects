/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:07:21 by pedromig          #+#    #+#             */
/*   Updated: 2025/06/30 02:48:02 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	x;

	x = 0;
	while (str[x])
		x++;
	return (x);
}


#include <stdio.h>
int	main(int argc, char *argv[])
{
	if (argc == 2)
		printf("%i", ft_strlen(argv[1]));
}

