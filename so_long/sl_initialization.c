/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_initialization.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 21:57:48 by pedromig          #+#    #+#             */
/*   Updated: 2025/07/04 18:16:16 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

void	sl_check_arg(int argc, char *file)
{
	char	*extension;

	if (argc != 2)
	{
		ft_printf("Usage: ./so_long '.ber file'\n");
		exit (1);
	}
	extension = ft_strrchr(file, '.');
	if (!extension || ft_strncmp(extension, ".ber", 4) != 0)
	{
		ft_printf("'%s' isn't a valid file!\nValid map file: '*.ber'\n", file);
		exit (1);
	}
}

int	sl_count_lines(t_game *sl, char *file)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error: couldn't open map file\n");
		exit (1);
	}
	line = get_next_line(fd);
	height = 0;
	while (line != NULL)
	{
		free(line);
		height++;
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

t_game	*sl_init(t_game *sl, char *file, int height)
{
	sl = ft_calloc(1, sizeof(t_game));
	if (!sl)
		sl_exit_error(sl, "Error: couldn't allocate memory\n");
	sl->height = height;
	sl->map = ft_calloc(height + 1, sizeof(char *));
	if (!sl->map)
		sl_exit_error(sl, "Error: couldn't allocate memory\n");
	return (sl);
}

void	sl_store_map(char *map_file, t_game *sl)
{
	int	fd;
	int	y;
	int	x;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		sl_exit_error(sl, "Error: couldn't open map file\n");
	y = 0;
	while (y < sl->height)
	{
		sl->map[y] = get_next_line(fd);
		if (!sl->map[y])
			sl_exit_error(sl, "Error: unexpected EOF\n");
		sl->map[y][ft_strlen(sl->map[y])] = '\0';
		y++;
	}
	sl->width = ft_strlen(sl->map[0]) - 1;
}
