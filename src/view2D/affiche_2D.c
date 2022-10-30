/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affiche_2D.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 22:23:32 by vbarbier          #+#    #+#             */
/*   Updated: 2022/10/29 16:01:28 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

void	quad_vertical(t_data *data, int x, int y)
{
	int	x1;
	int	y1;

	x1 = x;
	y1 = y;
	while (x1 < WIDTH)
	{
		while (y1 < HEIGHT)
		{
			if (can_draw(x1, y1))
				my_mlx_pixel_put(data, x1, y1, FOND);
			y1++;
		}
		y1 = y;
		x1 += SIZE_PIXMAP;
	}
}

void	quadrillage(t_data *data, int x, int y)
{
	int	x1;
	int	y1;

	x1 = x;
	y1 = y;
	while (y1 < HEIGHT)
	{
		while (x1 < WIDTH)
		{
			if (can_draw(x1, y1))
				my_mlx_pixel_put(data, x1, y1, FOND);
			x1++;
		}
		y1 += SIZE_PIXMAP;
		x1 = x;
	}
	quad_vertical(data, x, y);
}

void	map_2d(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map->carte[y])
	{
		while (data->map->carte[y][x])
		{
			if (data->map->carte[y][x] == '0' || \
			is_player(data->map->carte[y][x]) != -1)
				draw_map_2d(data, x, y, VIDE);
			if (data->map->carte[y][x] == '1')
				draw_map_2d(data, x, y, MUR);
			x++;
		}
		x = 0;
		y++;
	}
}

void	refresh_2d(t_data *data)
{
	init_map(data);
	map_2d(data);
	// quadrillage(data, - data->player.x + 4, -data->player.y);
	if (!PLAYER_FORM)
		draw_player_c(data);
	else
		draw_player_t(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

void	affiche_2d(t_data *data)
{
	data->addr = mlx_get_data_addr(data->img, \
	&data->bits_per_pixel, &data->line_length, &data->endian);
	init_player(data);
	refresh_2d(data);
}
