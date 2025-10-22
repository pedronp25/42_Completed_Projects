/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:30:14 by pedromig          #+#    #+#             */
/*   Updated: 2025/07/04 18:23:07 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_check_path(t_game *sl)
{
	char	**map_copy;

	map_copy = sl_dup_map(sl);
	sl->found.collectible = 0;
	sl->found.exit = 0;
	sl_flood_fill(map_copy, sl->player_x, sl->player_y, sl);
	sl_free_map(map_copy);
	if (sl->found.collectible != sl->collectible_count || sl->found.exit == 0)
		sl_exit_error(sl, "Error: no valid path for the player\n");
}

char	**sl_dup_map(t_game *sl)
{
	char	**map_copy;
	int		y;

	map_copy = ft_calloc(sl->height + 1, sizeof(char *));
	if (!map_copy)
		sl_exit_error(sl, "Error: couldn't allocate memory\n");
	y = 0;
	while (sl->map[y])
	{
		map_copy[y] = ft_strdup(sl->map[y]);
		if (!map_copy[y])
			sl_exit_error(sl, "Error: couldn't allocate memory\n");
		y++;
	}
	return (map_copy);
}

void	sl_flood_fill(char **map, int x, int y, t_game *sl)
{
	if (y < 0 || y >= sl->height || x < 0 || x >= sl->width)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'X')
		return ;
	else if (map[y][x] == 'C')
		sl->found.collectible++;
	else if (map[y][x] == 'E')
		sl->found.exit++;
	map[y][x] = 'X';
	sl_flood_fill(map, x + 1, y, sl);
	sl_flood_fill(map, x - 1, y, sl);
	sl_flood_fill(map, x, y + 1, sl);
	sl_flood_fill(map, x, y - 1, sl);
}
