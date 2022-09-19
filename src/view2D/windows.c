/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 22:25:16 by vbarbier          #+#    #+#             */
/*   Updated: 2022/09/18 23:44:38 by vbarbier         ###   ########.fr       */
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
	// destroy_datas(data);
	// mlx_clear_window(data->mlx, data->mlx_win);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	ft_free(data->mlx);
	// 	free_map(data);
	// exit(0);
	return (0);
}

void	new_window(t_data *data)
{
	int	width;
	int	height;

	width = 1400;
	height = 700;
	data->mlx = mlx_init();
	if (!data->mlx)
		name_error(6);
	data->mlx_win = mlx_new_window(data->mlx, width, height, "so_long");
}
