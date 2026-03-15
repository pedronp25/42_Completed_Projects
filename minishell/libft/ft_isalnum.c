/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 02:37:36 by pedromig          #+#    #+#             */
/*   Updated: 2025/04/10 18:54:30 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

/*
int	main(int argc, char *argv[])
{
	printf("Expected 1: %i\n", ft_isalnum('0'));
	printf("Expected 0: %i\n", ft_isalnum('*'));
}
*/
