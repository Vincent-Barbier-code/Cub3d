/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_2D.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 00:20:37 by vbarbier          #+#    #+#             */
/*   Updated: 2022/09/27 18:16:57 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

int	can_move(t_data *data, int pos, char c)
{
	int size;

	size = SIZE_PIXEL;
	// printf("map = %c\n",data->map->carte[11][28]);
	// printf("pos = %d data->player.x / size = %d data->player.y / size = %d\n", pos / size ,data->player.x / size, data->player.y / size);
	if (c == 'y' && data->map->carte[pos / size][(int) data->player.x / size] == '1' )
	//&& data->map->carte[pos / size][data->player.x / size] == '1')
		return (0);
	if (c == 'x' && data->map->carte[(int) data->player.y / size][pos / size] == '1')
		return (0);
	return (1);
}

void	move_player(t_data *data, int key)
{
	if (key == TOP ) //&& data->player.y)
		if (can_move(data, data->player.y - 1, 'y'))
			data->player.y = data->player.y - 1;
	if (key == BOT)// && data->player.y + 1)
		if (can_move(data, data->player.y + 1, 'y'))
			data->player.y = data->player.y + 1;
	if (key == LEFT && data->player.x)
		if (can_move(data, data->player.x - 1, 'x'))
			data->player.x = data->player.x - 1;
	if (key == RIGHT)// && data->player.x + 1)
		if (can_move(data, data->player.x + 1, 'x'))
			data->player.x = data->player.x  + 1;
}

void	draw_player(t_data *data)
{
	int	x;
	int	y;
	int size;

	size = SIZE_PLAYER;
	x = data->player.x;
	y = data->player.y;
	while (y < data->player.y + size\
	&& data->player.y + size < HEIGHT)
	{
		while (x < data->player.x + size\
		&& data->player.x + size < WIDTH)
		{
			my_mlx_pixel_put(data, x, y, data->player.color);
			x++;
		}
		y++;
		x = data->player.x;
	}
}

double	get_player_pos(t_map *map, char c)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map->carte[y])
	{
		while (map->carte[y][x])
		{
			if (is_player(map->carte[y][x]) && c == 'x')
				return (x);
			if (is_player(map->carte[y][x]) && c == 'y')
				return (y);
			x++;
		}
		x = 0;
		y++;
	}
	return (-1);
}

void	init_player(t_data *data)
{
	data->player.color = 0x0000FF00; // green
	data->player.x = get_player_pos(data->map, 'x') * (SIZE_PIXEL) + SIZE_PIXEL / 2 - SIZE_PLAYER / 2;
	data->player.y = get_player_pos(data->map, 'y') * (SIZE_PIXEL) + SIZE_PIXEL / 2 - SIZE_PLAYER / 2;
}
