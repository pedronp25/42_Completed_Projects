/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 01:04:51 by pedromig          #+#    #+#             */
/*   Updated: 2025/04/10 02:32:18 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	x;

	x = 0;
	while (s[x])
	{
		write(fd, &s[x], 1);
		x++;
	}
}

/*
int	main(int argc, char *argv[])
{
	int	fd = 1;

	if (argc == 2)
	{
		ft_putstr_fd(argv[1], fd);
	}
}
*/
