/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affiche_2D.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 22:23:32 by vbarbier          #+#    #+#             */
/*   Updated: 2022/10/04 14:10:08 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

void	quadrillage(t_data *data)
{
	int	x;
	int	y;
	
	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
			my_mlx_pixel_put(data, x++, y, FOND);
		y += SIZE_PIXEL;
		x = 0;
	}
	x = 0;
	y = 0;
	while (x < WIDTH)
	{
		while (y < HEIGHT)
			my_mlx_pixel_put(data, x, y++, FOND);
		y = 0;
		x += SIZE_PIXEL;
	}
}

void	draw_map_2D(t_data *data, int y, int x, int color)
{
	int size;
	int cp_x;
	int	cp_y;
	
	size = SIZE_PIXEL;
	x = x * size;
	y = y *size;
	cp_x = x;
	cp_y = y;
	while (y < cp_y + size && y + size < HEIGHT)
	{
		while (x < cp_x + size && x + size < WIDTH)
		{
			my_mlx_pixel_put(data, x, y, color);
			x++;
		}
		y++;
		x = cp_x;
	}
}

void	map_2D(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map->carte[y])
	{
		while (data->map->carte[y][x])
		{
			if (data->map->carte[y][x] == '0' || is_player(data->map->carte[y][x]))
				draw_map_2D(data, y, x, VIDE);
			if (data->map->carte[y][x] == '1')
				draw_map_2D(data, y, x, MUR); 
			x++;
		}
		x = 0;
		y++;
	}
}

void	refresh_2D(t_data *data)
{
	map_2D(data);
	quadrillage(data);
	draw_player(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

void	affiche_2D(t_data *data)
{
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, \
	&data->endian);
	init_player(data);
	refresh_2D(data);
}
