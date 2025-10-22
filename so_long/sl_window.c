/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 02:11:07 by pedromig          #+#    #+#             */
/*   Updated: 2025/10/13 19:57:17 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "so_long.h"

void	sl_window(t_game *sl)
{
	sl->mlx = mlx_init();
	if (!sl->mlx)
		sl_exit_error(sl, "Error: couldn't initiate mlx\n");
	sl->win = mlx_new_window(sl->mlx, sl->width * TILE_SIZE,
			sl->height * TILE_SIZE, "SO_LONG");
	if (!sl->win)
		sl_exit_error(sl, "Error: coudln't create window\n");
	sl_xpm_to_image(sl);
	sl_draw_map(sl);
	mlx_key_hook(sl->win, sl_key_press, sl);
	mlx_hook(sl->win, 17, 0, sl_press_cross, sl);
	mlx_loop(sl->mlx);
}

void	sl_xpm_to_image(t_game *sl)
{
	int	size;

	sl->img.floor = mlx_xpm_file_to_image(sl->mlx,
			"96x96_imgs/floor_96_img.xpm", &size, &size);
	if (!sl->img.floor)
		sl_exit_error(sl, "Error: couldn't create '0' image from xpm file\n");
	sl->img.wall = mlx_xpm_file_to_image(sl->mlx,
			"96x96_imgs/wall_96_img.xpm", &size, &size);
	if (!sl->img.wall)
		sl_exit_error(sl, "Error: couldn't create '1' image from xpm file\n");
	sl->img.player = mlx_xpm_file_to_image(sl->mlx,
			"96x96_imgs/cat_96_img.xpm", &size, &size);
	if (!sl->img.player)
		sl_exit_error(sl, "Error: couldn't create 'P' image from xpm file\n");
	sl->img.collectible = mlx_xpm_file_to_image(sl->mlx,
			"96x96_imgs/duck_96_img.xpm", &size, &size);
	if (!sl->img.collectible)
		sl_exit_error(sl, "Error: couldn't create 'C' image from xpm file\n");
	sl->img.exit = mlx_xpm_file_to_image(sl->mlx,
			"96x96_imgs/bed_96_img.xpm", &size, &size);
	if (!sl->img.exit)
		sl_exit_error(sl, "Error: couldn't create 'E' image from xpm file\n");
}

void	sl_draw_map(t_game *sl)
{
	int	y;
	int	x;

	y = 0;
	while (y < sl->height)
	{
		x = 0;
		while (x < sl->width)
		{
			sl_draw_tile(sl, y, x);
			x++;
		}
		y++;
	}
}

void	sl_draw_tile(t_game *sl, int y, int x)
{
	char	tile;
	void	*img;

	img = NULL;
	tile = sl->map[y][x];
	mlx_put_image_to_window(sl->mlx, sl->win, sl->img.floor,
		x * TILE_SIZE, y * TILE_SIZE);
	if (tile == '1')
		img = sl->img.wall;
	else if (tile == 'P')
		img = sl->img.player;
	else if (tile == 'C')
		img = sl->img.collectible;
	else if (tile == 'E')
		img = sl->img.exit;
	if (img)
		mlx_put_image_to_window(sl->mlx, sl->win, img,
			x * TILE_SIZE, y * TILE_SIZE);
}

int	sl_press_cross(t_game *sl)
{
	sl_exit_success(sl, 1);
	return (0);
}
