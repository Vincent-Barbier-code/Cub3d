/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_2D.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 00:20:37 by vbarbier          #+#    #+#             */
/*   Updated: 2022/10/29 15:46:58 by mvue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

void	move_cam(t_data *data, int key)
{
	if (key == CAM_LEFT)
		data->player.radian -= 11 * M_PI / 12;
	if (key == CAM_RIGHT)
		data->player.radian += 11 * M_PI / 12;
	if (data->player.radian >= M_PI * 2)
		data->player.radian = data->player.radian - (M_PI * 2);
	if (data->player.radian <= -(M_PI * 2))
		data->player.radian = data->player.radian + (M_PI * 2);
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
			if ((is_player(map->carte[y][x]) != -1) && c == 'x')
				return (x);
			if ((is_player(map->carte[y][x]) != -1) && c == 'y')
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
	data->player.x = get_player_pos(data->map, 'x') * SIZE_PIXMAP + SIZE_PIXMAP / 2 - SIZE_PLAYER / 2;
	data->player.y = get_player_pos(data->map, 'y') * SIZE_PIXMAP + SIZE_PIXMAP / 2 - SIZE_PLAYER / 2;
}

void    move_cam(t_data *data, int key)
{
    if (key == CAM_LEFT)
    {
	    data->player.front -= 0.05;
		if (data->player.front < 0)
        	data->player.front += M_PI * 2;
	}
	if (key == CAM_RIGHT)
    {
	    data->player.front += 0.05;
		if (data->player.front > 2 * M_PI)
			data->player.front -= M_PI * 2;
	}
}
