/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 22:25:16 by vbarbier          #+#    #+#             */
/*   Updated: 2022/09/20 19:36:08 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

int	key_hook(int key, t_data *data)
{
	if (key == ESC)
	{
		win_close(data);
		return (1);
	}
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
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "so_long");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
}
