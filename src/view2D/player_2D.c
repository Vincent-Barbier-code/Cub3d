/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_2D.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 00:20:37 by vbarbier          #+#    #+#             */
/*   Updated: 2022/10/13 23:04:35 by mvue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

int	can_move(t_data *data, int pos, char c)
{
	int size;

	size = SIZE_PIXEL;
	// printf("pos = %d data->player.x / size = %f data->player.y / size = %f\n", pos / size ,data->player.x / size, data->player.y / size);
	// printf("pos = %d\n", (pos / size) + SIZE_PLAYER);
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
	if (key == TOP )
		if (can_move(data, data->player.x + cos(data->player.front), 'x') && \
			can_move(data, data->player.y + sin(data->player.front), 'y'))
		{
			data->player.x += cos(data->player.front);
			data->player.y += sin(data->player.front);
		}
	if (key == BOT)
		if (can_move(data, data->player.x + cos(data->player.front), 'x') && \
			can_move(data, data->player.y + sin(data->player.front), 'y'))
		{
			data->player.x -= cos(data->player.front);
			data->player.y -= sin(data->player.front);
		}
	if (key == LEFT)
		if (can_move(data, data->player.x + cos(data->player.front + M_PI / 2), 'x') && \
			can_move(data, data->player.y + sin(data->player.front + M_PI / 2), 'y'))
		{
			data->player.x -= cos(data->player.front + M_PI / 2);
			data->player.y -= sin(data->player.front + M_PI / 2);
		}
	if (key == RIGHT)
		if (can_move(data, data->player.x + cos(data->player.front - M_PI / 2), 'x') && \
			can_move(data, data->player.y + sin(data->player.front - M_PI / 2), 'y'))
		{
			data->player.x -= cos(data->player.front - M_PI / 2);
			data->player.y -= sin(data->player.front - M_PI / 2);
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
	data->player.color = COLOR_PLAYER; // green
	data->player.x = get_player_pos(data->map, 'x') * SIZE_PIXEL + SIZE_PIXEL / 2 - SIZE_PLAYER / 2;
	data->player.y = get_player_pos(data->map, 'y') * SIZE_PIXEL + SIZE_PIXEL / 2 - SIZE_PLAYER / 2;
}

void    move_cam(t_data *data, int key)
{
    if (key == CAM_LEFT)
    {
	    data->player.front -= 0.1;
		if (data->player.front < 0)
        	data->player.front += M_PI * 2;
		printf("front angle : %f\n", data->player.front);
	}
	if (key == CAM_RIGHT)
    {
	    data->player.front += 0.1;
		if (data->player.front > 2 * M_PI)
			data->player.front -= M_PI * 2;
		printf("front angle : %f\n", data->player.front);
	}
}
