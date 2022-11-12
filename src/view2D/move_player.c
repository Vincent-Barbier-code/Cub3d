/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:39:02 by vbarbier          #+#    #+#             */
/*   Updated: 2022/11/12 18:44:43 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

void	move_top(t_data *data)
{
	if (can_move(data, data->player.x + cos(data->player.front), 'x') \
	&& can_move(data, data->player.y + sin(data->player.front), 'y'))
	{
		data->player.x += cos(data->player.front);
		data->player.y += sin(data->player.front);
	}
}

void	move_bot(t_data *data)
{
	if (can_move(data, data->player.x - cos(data->player.front), 'x') \
	&& can_move(data, data->player.y - sin(data->player.front), 'y'))
	{
		data->player.x -= cos(data->player.front);
		data->player.y -= sin(data->player.front);
	}
}

void	move_left(t_data *data)
{
	if (can_move(data, data->player.x - \
	cos(data->player.front + M_PI / 2), 'x') \
	&& can_move(data, data->player.y - sin(data->player.front + M_PI / 2), 'y'))
	{
		data->player.x -= cos(data->player.front + M_PI / 2);
		data->player.y -= sin(data->player.front + M_PI / 2);
	}
}

void	move_right(t_data *data)
{
	if (can_move(data, data->player.x - \
	cos(data->player.front - M_PI / 2), 'x') \
	&& can_move(data, data->player.y - sin(data->player.front - M_PI / 2), 'y'))
	{
		data->player.x -= cos(data->player.front - M_PI / 2);
		data->player.y -= sin(data->player.front - M_PI / 2);
	}
}

void	move_player(t_data *data, int key)
{
	if (key == TOP)
		move_top(data);
	if (key == BOT)
		move_bot(data);
	if (key == LEFT)
		move_left(data);
	if (key == RIGHT)
		move_right(data);
}
