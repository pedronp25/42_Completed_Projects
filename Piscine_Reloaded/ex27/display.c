/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 20:30:10 by pedromig          #+#    #+#             */
/*   Updated: 2025/04/07 00:52:23 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char *argv[])
{
	int		fd;
	int		bytes_r;
	char	buf[BUF_SIZE];

	if (argc < 2)
		return (ft_putstr("File name missing.\n"), 1);
	if (argc > 2)
		return (ft_putstr("Too many arguments.\n"), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_putstr("Cannot read file.\n"), 1);
	bytes_r = read(fd, buf, BUF_SIZE - 1);
	if (bytes_r == -1)
		return (1);
	while (bytes_r)
	{
		buf[bytes_r] = '\0';
		write(1, buf, bytes_r);
		bytes_r = read(fd, buf, BUF_SIZE - 1);
	}
	close(fd);
}

void	ft_putstr(char *str)
{
	int	x;

	x = 0;
	while (str[x])
	{
		write(1, &str[x], 1);
		x++;
	}
}
