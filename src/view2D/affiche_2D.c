/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affiche_2D.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 22:23:32 by vbarbier          #+#    #+#             */
/*   Updated: 2022/09/20 20:19:23 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

// void	draw_rectangle()

int	get_player_pos(t_map *map, char c)
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
	data->player.x = get_player_pos(data->map, 'x') * SIZE_PIXEL;
	data->player.y = get_player_pos(data->map, 'y') * SIZE_PIXEL;
	// printf("x%d  y%d\n", data->player.x, data->player.y);
	my_mlx_pixel_put(data, data->player.x, data->player.x, data->player.color);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

// void	affiche_player(t_data *data)
// {
// 	0x0000FF00 //green
// }

void	affiche_2D(t_data *data)
{
	// test
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, \
	&data->endian);
	init_player(data);
	// my_mlx_pixel_put(data, 100, 100, 0x00FF0000);
	// mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	

	
}
