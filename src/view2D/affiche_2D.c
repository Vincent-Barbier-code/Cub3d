/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affiche_2D.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 22:23:32 by vbarbier          #+#    #+#             */
/*   Updated: 2022/10/20 04:55:16 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

int	can_draw(int x, int y)
{
	if (x >= POS_MAP_X && y >= POS_MAP_Y && x < WIDTH - GAP_MAP && y < HEIGHT - GAP_MAP)
		return (1);
	return (0);
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
	x1 = x;
	y1 = y;
	while (x1 < WIDTH)
	{
		while (y1 < HEIGHT)
		{
			if(can_draw(x1, y1))
				my_mlx_pixel_put(data, x1, y1, FOND);
			y1++;
		}
		y1 = y;
		x1 += SIZE_PIXMAP;
	}
}

void	init_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			if (can_draw(x, y))
				my_mlx_pixel_put(data, x, y , MUR);
			x++;
		}
		x = 0;
		y++;
	}
}
void	draw_map_2D(t_data *data, int x, int y, int color)
{
	int size;
	int cp_x;
	int	cp_y;
	double pos_x;
	double pos_y;
	
	size = SIZE_PIXMAP;
	pos_x = get_player_pos(data->map, 'x');
	pos_y = get_player_pos(data->map, 'y');
	x = x * size + POS_PX - pos_x * size - size / 2 + SIZE_PLAYER / 2;
	y = y * size + POS_PY - pos_y * size - size / 2 + SIZE_PLAYER / 2;
	cp_x = x;
	cp_y = y;
	while (y < cp_y + size)
	{
		while (x < cp_x + size)
		{
			if (can_draw(x + pos_x * SIZE_PIXMAP + SIZE_PIXMAP / 2 - SIZE_PLAYER / 2 - data->player.x,
			y + pos_y * SIZE_PIXMAP + SIZE_PIXMAP / 2 - SIZE_PLAYER / 2 - data->player.y))
				my_mlx_pixel_put(data, x + pos_x * SIZE_PIXMAP + SIZE_PIXMAP / 2 - SIZE_PLAYER / 2 - data->player.x , \
			 y + pos_y * SIZE_PIXMAP + SIZE_PIXMAP / 2 - SIZE_PLAYER / 2 - data->player.y, color);
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
			if (data->map->carte[y][x] == '0' || is_player(data->map->carte[y][x]) != -1)
				draw_map_2D(data, x, y, VIDE);
			if (data->map->carte[y][x] == '1')
				draw_map_2D(data, x, y, MUR);
			x++;
		}
		x = 0;
		y++;
	}
}

void	refresh_2D(t_data *data)
{
	init_map(data);
	map_2D(data);
	quadrillage(data, - data->player.x + 4, - data->player.y);
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
