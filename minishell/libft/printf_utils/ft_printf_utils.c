/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 19:08:48 by pedromig          #+#    #+#             */
/*   Updated: 2025/06/09 18:22:32 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putchar_size(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr_size(char *str)
{
	int	x;

	x = 0;
	if (!str)
		return (ft_putstr_size("(null)"));
	while (str && str[x])
	{
		write(1, &str[x], 1);
		x++;
	}
	return (x);
}

int	ft_putnbr_size(int i)
{
	char	*str;
	int		size;

	str = ft_itoa(i);
	if (!str)
		return (-1);
	size = ft_putstr_size(str);
	return (free(str), size);
}

int	ft_putunbr_size(unsigned int u)
{
	char	*str;
	int		size;

	str = ft_uitoa(u);
	if (!str)
		return (-1);
	size = ft_putstr_size(str);
	return (free(str), size);
}
