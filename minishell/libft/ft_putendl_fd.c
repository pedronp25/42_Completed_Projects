/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 01:08:17 by pedromig          #+#    #+#             */
/*   Updated: 2025/04/10 02:32:01 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	x;

	x = 0;
	while (s[x])
	{
		write(fd, &s[x], 1);
		x++;
	}
	write(fd, "\n", 1);
}

/*
int	main(int argc, char *argv[])
{
	int	fd = 1;

	if (argc == 2)
	{
		ft_putendl_fd(argv[1], fd);
	}
}
*/
