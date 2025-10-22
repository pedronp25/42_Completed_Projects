/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 02:39:54 by pedromig          #+#    #+#             */
/*   Updated: 2025/07/04 18:14:18 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_exit_error(t_game *sl, char *err_msg)
{
	if (err_msg)
		ft_printf(err_msg);
	sl_cleanup(sl);
	exit(1);
}

void	sl_exit_success(t_game *sl, int closed)
{
	sl_cleanup(sl);
	if (closed)
		exit (0);
	ft_printf("\n");
	ft_printf("\t\t╔═════════════════════╗\n");
	ft_printf("\t\t║                     ║\n");
	ft_printf("\t\t║   🎉 CONGRATS! 🎉   ║\n");
	ft_printf("\t\t║                     ║\n");
	ft_printf("\t\t║ You collected all   ║\n");
	ft_printf("\t\t║ the items and       ║\n");
	ft_printf("\t\t║ escaped the dungeon!║\n");
	ft_printf("\t\t║                     ║\n");
	ft_printf("\t\t║      🗝️     🏃       ║\n");
	ft_printf("\t\t║                     ║\n");
	ft_printf("\t\t║ Thanks for playing! ║\n");
	ft_printf("\t\t║                     ║\n");
	ft_printf("\t\t║         🌟          ║\n");
	ft_printf("\t\t║                     ║\n");
	ft_printf("\t\t╚═════════════════════╝\n");
	ft_printf("\n");
	exit (0);
}

void	sl_cleanup(t_game *sl)
{
	if (sl->map)
		sl_free_map(sl->map);
	if (sl->img.floor)
		mlx_destroy_image(sl->mlx, sl->img.floor);
	if (sl->img.wall)
		mlx_destroy_image(sl->mlx, sl->img.wall);
	if (sl->img.player)
		mlx_destroy_image(sl->mlx, sl->img.player);
	if (sl->img.collectible)
		mlx_destroy_image(sl->mlx, sl->img.collectible);
	if (sl->img.exit)
		mlx_destroy_image(sl->mlx, sl->img.exit);
	if (sl->win)
		mlx_destroy_window(sl->mlx, sl->win);
	if (sl->mlx)
	{
		mlx_destroy_display(sl->mlx);
		free(sl->mlx);
	}
	if (sl)
		free (sl);
}

void	sl_free_map(char **map)
{
	int	y;

	y = 0;
	while (map[y])
		free(map[y++]);
	free(map);
}
