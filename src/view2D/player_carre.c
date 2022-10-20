/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_carre.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:23:56 by vbarbier          #+#    #+#             */
/*   Updated: 2022/10/20 04:55:16 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

int	can_move(t_data *data, int pos, char c)
{
	int size;

	size = SIZE_PIXMAP;
	if (c == 'y' && (data->map->carte[pos / size][(int) data->player.x / size] == '1' \
	|| data->map->carte[(pos + SIZE_PLAYER) / size][(int) data->player.x / size] == '1'))
		return (0);
	if (c == 'x' && (data->map->carte[(int) data->player.y / size][pos / size] == '1' \
	|| data->map->carte[(int) data->player.y / size][(pos + SIZE_PLAYER) / size] == '1' \
	|| data->map->carte[(int) (data->player.y  + SIZE_PLAYER) / size][(pos + SIZE_PLAYER) / size] == '1' \
	|| data->map->carte[(int) (data->player.y  + SIZE_PLAYER) / size][pos / size] == '1'))
		return (0);
	return (1);
}

void	move_player(t_data *data, int key)
{
	if (key == TOP)
		if (can_move(data, data->player.y - 1, 'y'))
			data->player.y = data->player.y - 1;
	if (key == BOT)
		if (can_move(data, data->player.y + 1, 'y'))
			data->player.y = data->player.y + 1;
	if (key == LEFT)
		if (can_move(data, data->player.x - 1, 'x'))
			data->player.x = data->player.x - 1;
	if (key == RIGHT)
		if (can_move(data, data->player.x + 1, 'x'))
			data->player.x = data->player.x  + 1;
}

void	draw_player_c(t_data *data)
{
	int	x;
	int	y;
	int size;

	size = SIZE_PLAYER;
	x = POS_PX;
	y = POS_PY;
	while (y < POS_PY + size\
	&& POS_PY + size < HEIGHT)
	{
		while (x < POS_PX + size\
		&& POS_PX + size < WIDTH)
		{
			my_mlx_pixel_put(data, x, y, data->player.color);
			x++;
		}
		y++;
		x = POS_PX;
	}
}
