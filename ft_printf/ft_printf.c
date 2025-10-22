/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 19:29:41 by pedromig          #+#    #+#             */
/*   Updated: 2025/05/18 21:28:10 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		x;

	if (!str)
		return (-1);
	va_start(args, str);
	count = 0;
	x = 0;
	while (str[x])
	{
		if (str[x] == '%' && str[x + 1])
		{
			count += condition_check(str[x + 1], args);
			x++;
		}
		else
		{
			ft_putchar_fd(str[x], 1);
			count++;
		}
		x++;
	}
	return (count);
}

int	condition_check(char c, va_list args)
{
	int	size;

	if (c == '%')
		size = ft_putchar_size('%');
	else if (c == 'c')
		size = ft_putchar_size(va_arg(args, int));
	else if (c == 's')
		size = ft_putstr_size(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		size = ft_putnbr_size(va_arg(args, int));
	else if (c == 'u')
		size = ft_putunbr_size(va_arg(args, unsigned int));
	else if (c == 'p')
		size = ft_putptr(va_arg(args, void *));
	else if (c == 'x')
		size = ft_putnbr_hex(va_arg(args, unsigned int), 0);
	else if (c == 'X')
		size = ft_putnbr_hex(va_arg(args, unsigned int), 1);
	else
		return (-1);
	return (size);
}

/*
int	main(void)
{
	int	return_value = 0;

	char	c = 'a';
	char	*str = NULL;
	int		i = -1234;
	unsigned int	u = 1234;
	void	*p = &u;
	unsigned int	x = 1234;

	return_value = printf("Printf: %c\n%s\n%d\n%i\n%u\n%p\n%x\n%X\n%%\n"
		, c, str, i, i, u, p, x, x);

	printf("Return value of printf: %i\n", return_value);	

	ft_putchar_fd('\n', 1);

	return_value = ft_printf("Ft_Printf: %c\n%s\n%d\n%i\n%u\n%p\n%x\n%X\n%%\n"
		, c, str, i, i, u, p, x, x);

	printf("Return value of ft_printf: %i (3 more because of 'Ft_')\n"
		, return_value);	
}
*/
