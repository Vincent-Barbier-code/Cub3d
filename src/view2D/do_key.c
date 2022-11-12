/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:34:26 by vbarbier          #+#    #+#             */
/*   Updated: 2022/11/12 19:35:54 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

int	key_release(int key, t_data *data)
{
	if (key == data->buffer)
		data->buffer = 0;
	return (0);
}

int	do_key(int key, t_data *data)
{
	if (key == ESC)
	{	
		win_close(data);
		return (1);
	}
	if (key != TOP && key != BOT && key != RIGHT && key != LEFT && \
		key != CAM_LEFT && key != CAM_RIGHT)
		return (0);
	move_player(data, key);
	move_cam(data, key);
	refresh_2d(data);
	return (0);
}

int	key_press(int key, t_data *data)
{
	if (data->buffer == 0)
		data->buffer = key;
	do_key(key, data);
	return (0);
}
