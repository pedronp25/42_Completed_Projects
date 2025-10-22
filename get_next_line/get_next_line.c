/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 20:40:37 by pedromig          #+#    #+#             */
/*   Updated: 2025/06/08 17:33:55 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	int			bytes_read;
	char		*return_str;
	int			nl_check;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	ft_ultimate_initializer(&bytes_read, &nl_check, &return_str);
	while (!nl_check)
	{
		if (!buf[0])
		{
			bytes_read = read(fd, buf, BUFFER_SIZE);
			if (bytes_read == -1)
				return (free(return_str), NULL);
			if (bytes_read == 0)
				break ;
			buf[bytes_read] = '\0';
		}
		return_str = ft_strjoin_nl(return_str, buf);
		if (!return_str)
			return (NULL);
		nl_check = ft_cleanup_str(buf);
	}
	return (return_str);
}

/*
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc != 2)
	{
		printf("Usage: %s <filename>\n", argv[0]);
		return (1);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf("Error opening file");
		return (1);
	}

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line); // line includes newline if present
		free(line);
	}

	close(fd);
	return (0);
}
*/
