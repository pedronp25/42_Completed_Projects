/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 22:54:48 by pedromig          #+#    #+#             */
/*   Updated: 2025/05/18 21:02:34 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"

int		ft_printf(const char *str, ...);
int		condition_check(char c, va_list args);
int		ft_putchar_size(int c);
int		ft_putstr_size(char *str);
int		ft_putnbr_size(int n);
int		ft_putunbr_size(unsigned int u);
char	*ft_uitoa(unsigned int n);
int		ft_putnbr_hex(unsigned long n, int uppercase);
int		ft_putptr(void *p);
char	*ft_ultoa(unsigned long n, int uppercase);

#endif
