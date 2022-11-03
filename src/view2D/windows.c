/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 22:25:16 by vbarbier          #+#    #+#             */
/*   Updated: 2022/11/03 22:02:11 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

// int	key_release(int key, t_data *data)
// {
// 	if (key == TOP || key == BOT || key == RIGHT || key == LEFT)
// 	{
// 		printf("blabla,%d", data->player.x);
// 		return (1);
// 	}
// 	else
// 		return (0);
// }

int key_release(int key, t_data *data)
{
    if (key == data->buffer)
        data->buffer = 0;
    return(0);
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

int key_press(int key, t_data *data)
{
	if (data->buffer == 0)
		data->buffer = key;
	// else if (data->buffer != key)
	// 	do_key(data->buffer, data);
	do_key(key, data);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	win_close(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_clear_window(data->mlx, data->mlx_win);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	ft_garbage_collector(END, NULL);
	exit(0);
	return (0);
}

void	new_window(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		name_error(6);
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Cub3d");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
}
