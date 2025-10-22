/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 00:14:39 by pedromig          #+#    #+#             */
/*   Updated: 2025/06/09 18:22:16 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	hex_size(unsigned long n);

char	*ft_ultoa(unsigned long n, int uppercase)
{
	char	*str;
	int		size;
	char	*digits;

	if (uppercase)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	size = hex_size(n);
	str = malloc(size + 1);
	if (!str)
		return (NULL);
	str[size] = '\0';
	if (n == 0)
		str[0] = '0';
	while (size > 0 && n != 0)
	{
		size--;
		str[size] = digits[n % 16];
		n /= 16;
	}
	return (str);
}

static int	hex_size(unsigned long n)
{
	int	x;

	x = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		x++;
	}
	return (x);
}
