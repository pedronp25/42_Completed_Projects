/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 03:26:05 by pedromig          #+#    #+#             */
/*   Updated: 2025/10/13 19:58:31 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363
# define ESC 65307

# define TILE_SIZE 96

typedef struct s_found
{
	int	player;
	int	exit;
	int	collectible;
}	t_found;

typedef struct s_img
{
	void	*floor;
	void	*wall;
	void	*player;
	void	*collectible;
	void	*exit;
}	t_img;

typedef struct s_game
{
	char	**map;
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		collectible_count;
	int		collected;
	int		moves;
	t_found	found;
	t_img	img;
}	t_game;

void	sl_check_arg(int argc, char *file);
t_game	*sl_init(t_game *sl, char *file, int height);
int		sl_count_lines(t_game *sl, char *file);
void	sl_store_map(char *map_file, t_game *sl);
void	sl_validate_map(t_game *sl);
void	sl_check_chars(t_game *sl, t_found *found, int y, int x);
void	sl_check_walls(t_game *sl, int y, int x);
void	sl_check_path(t_game *sl);
char	**sl_dup_map(t_game *sl);
void	sl_flood_fill(char **map, int x, int y, t_game *sl);
void	sl_free_map(char **map);
int		sl_key_press(int keycode, t_game *sl);
void	sl_move(int y, int x, t_game *sl);
void	sl_move_update(int y, int x, t_game *sl);
void	sl_window(t_game *sl);
void	sl_draw_map(t_game *sl);
void	sl_draw_tile(t_game *sl, int y, int x);
int		sl_press_cross(t_game *sl);
void	sl_exit_error(t_game *sl, char *err_msg);
void	sl_exit_success(t_game *sl, int closed);
void	sl_cleanup(t_game *sl);
void	sl_xpm_to_image(t_game *sl);

#endif
