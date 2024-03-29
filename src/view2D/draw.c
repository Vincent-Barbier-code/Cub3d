/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:59:04 by vbarbier          #+#    #+#             */
/*   Updated: 2022/11/12 22:24:41 by mvue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

int	can_draw(t_data *data, int x, int y)
{
	if (x >= data->pos_map_x && y >= data->pos_map_y && \
	x < WIDTH - GAP_MAP && y < HEIGHT - GAP_MAP)
		return (1);
	return (0);
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
			if (can_draw(data, x, y))
				my_mlx_pixel_put(data, x, y, MUR);
			x++;
		}
		x = 0;
		y++;
	}
}

static void	init_draw(t_data *data, int x, int y)
{
	data->draw.size = SIZE_PIXMAP;
	data->draw.pos_x = get_player_pos(data->map, 'x');
	data->draw.pos_y = get_player_pos(data->map, 'y');
	data->draw.x = x * data->draw.size + data->pos_px - data->draw.pos_x \
	* data->draw.size - data->draw.size / 2 + SIZE_PLAYER / 2;
	data->draw.y = y * data->draw.size + data->pos_py - data->draw.pos_y \
	* data->draw.size - data->draw.size / 2 + SIZE_PLAYER / 2;
	data->draw.cp_x = data->draw.x;
	data->draw.cp_y = data->draw.y;
}

int	formule(t_data *data, t_draw draw, char c)
{
	if (c == 'x')
	{
		return (draw.x + draw.pos_x * SIZE_PIXMAP \
		+ SIZE_PIXMAP / 2 - SIZE_PLAYER / 2 - data->player.x / 2);
	}
	else
	{
		return (draw.y + draw.pos_y * SIZE_PIXMAP \
		+ SIZE_PIXMAP / 2 - SIZE_PLAYER / 2 - data->player.y / 2);
	}
}

void	draw_map_2d(t_data *data, int x, int y, int color)
{
	t_draw	draw;

	init_draw(data, x, y);
	draw = data->draw;
	while (draw.y < draw.cp_y + draw.size)
	{
		while (draw.x < draw.cp_x + draw.size)
		{
			data->draw = draw;
			if (can_draw(data, formule(data, draw, 'x'), \
			formule(data, draw, 'y')))
				my_mlx_pixel_put(data, formule(data, draw, 'x'), \
				formule(data, draw, 'y'), color);
			draw.x++;
		}
		draw.y++;
		draw.x = draw.cp_x;
	}
}
