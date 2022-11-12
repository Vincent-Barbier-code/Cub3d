/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_2D.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 00:20:37 by vbarbier          #+#    #+#             */
/*   Updated: 2022/11/12 18:46:41 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

void	move_cam(t_data *data, int key)
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
	data->player.color = COLOR_PLAYER;
	data->player.x = get_player_pos(data->map, 'x') \
	* SIZE_PIXEL + SIZE_PIXEL / 2 - SIZE_PLAYER / 2;
	data->player.y = get_player_pos(data->map, 'y') \
	* SIZE_PIXEL + SIZE_PIXEL / 2 - SIZE_PLAYER / 2;
}
