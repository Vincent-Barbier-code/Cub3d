/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affiche_2D.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 22:23:32 by vbarbier          #+#    #+#             */
/*   Updated: 2022/10/16 18:27:04 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

void	quadrillage(t_data *data, int x, int y)
{
	int	x1;
	int	y1;

	x1 = x;
	y1 = y;
	while (y1 < HEIGHT)
	{
		while (x1 < WIDTH)
			my_mlx_pixel_put(data, x1++, y1, FOND);
		y1 += SIZE_PIXMAP;
		x1 = x;
	}
	x1 = x;
	y1 = y;
	while (x1 < WIDTH)
	{
		while (y1 < HEIGHT)
			my_mlx_pixel_put(data, x1, y1++, FOND);
		y1 = y;
		x1 += SIZE_PIXMAP;
	}
}

void	draw_map_2D(t_data *data, int x, int y, int color)
{
	int size;
	int cp_x;
	int	cp_y;
	
	size = SIZE_PIXMAP;
	x = x * size;
	y = y *size;
	cp_x = x;
	cp_y = y;
	while (y < cp_y + size + POS_MAP_Y && y + size + POS_MAP_Y < HEIGHT)
	{
		while (x < cp_x + size + POS_MAP_X && x + size + POS_MAP_X < WIDTH)
		{
			my_mlx_pixel_put(data, x + POS_MAP_X , y + POS_MAP_Y, color);
			x++;
		}
		y++;
		x = cp_x;
	}
}

// double	pixel(int x)
// {
// 	return (x - floor(x));
// }

void	map_2D(t_data *data)
{
	int	x;
	int	y;
	int i = 0, j = 0;

	x = (data->player.x / SIZE_PIXEL) - 8;
	printf("x = %d\n", (int) data->player.x);
	y = (data->player.y / SIZE_PIXEL) - 7;
	printf("y = %d\n", (int) data->player.y);
	if (x < 0)
		x = 0;
	if (y < 0)
		x = 0;
	while (data->map->carte[y])
	{
		while (data->map->carte[y][x])
		{
			if (data->map->carte[y][x] == '0' || is_player(data->map->carte[y][x]) != -1)
				draw_map_2D(data, i++, j, VIDE);
			if (data->map->carte[y][x] == '1')
				draw_map_2D(data, i++, j, MUR);
			x++;
		}
		i = 0;
		x = (data->player.x / SIZE_PIXEL) - 8;
		j++;
		y++;
	}
}

void	refresh_2D(t_data *data)
{
	map_2D(data);
	quadrillage(data, POS_MAP_X , POS_MAP_Y);
	if (!PLAYER_FORM)
		draw_player_c(data);
	else
		draw_player_t(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

void	affiche_2D(t_data *data)
{
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, \
	&data->endian);
	init_player(data);
	refresh_2D(data);
}
