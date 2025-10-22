/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_hex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 23:50:21 by pedromig          #+#    #+#             */
/*   Updated: 2025/05/18 20:59:56 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex(unsigned long n, int uppercase)
{
	int		size;
	char	*str;

	str = ft_ultoa(n, uppercase);
	if (!str)
		return (-1);
	size = ft_putstr_size(str);
	return (free(str), size);
}

int	ft_putptr(void *p)
{
	unsigned long	n;

	if (!p)
		return (write(1, "(nil)", 5));
	n = (unsigned long)p;
	write(1, "0x", 2);
	return (ft_putnbr_hex(n, 0) + 2);
}
