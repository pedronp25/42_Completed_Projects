/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 20:16:38 by pedromig          #+#    #+#             */
/*   Updated: 2025/07/04 18:04:35 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"

int	main(int argc, char *argv[])
{
	t_game	*sl;
	int		height;

	sl_check_arg(argc, argv[1]);
	height = sl_count_lines(sl, argv[1]);
	if (!height)
	{
		ft_printf("Error: empty map file\n");
		exit (1);
	}
	sl = sl_init(sl, argv[1], height);
	sl_store_map(argv[1], sl);
	sl_validate_map(sl);
	sl_check_path(sl);
	sl_window(sl);
}
