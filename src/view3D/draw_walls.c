/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:07:27 by mvue              #+#    #+#             */
/*   Updated: 2022/11/03 22:28:44 by mvue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

static int	create_color(int r, int g, int b)
{
	return (0 << 24 | r << 16 | g << 8 | b);
}

void	draw_ceiling(t_data *data, int pix_x, double end_ceil)
{
	int	pix_y;
	int	color;
	
	pix_y = 0;
	color = create_color(data->textures.ceiling[0], data->textures.ceiling[1], data->textures.ceiling[2]);
	while (pix_y < end_ceil)
	{
		my_mlx_pixel_put(data, pix_x, pix_y, color);
		pix_y++;
	}
}

void	draw_floor(t_data *data, int pix_x, double start_floor)
{
	int	pix_y;
	int	color;

	pix_y = start_floor;
	color = create_color(data->textures.floor[0], data->textures.floor[1], data->textures.floor[2]);
	while (pix_y < HEIGHT)
	{
		my_mlx_pixel_put(data, pix_x, pix_y, color);
		pix_y++;
	}
}

void	trace_pix_column(t_data *data, double len_ray, int n_pix_col, int ind_col)
{
	double	col_h;
	double	col_offset;
	int		pix_x;
	int		pix_y;

	if (ind_col == WIDTH)
		return ;
	col_h = SIZE_PIXEL * HEIGHT / len_ray;
	if (col_h > HEIGHT)
		col_h = HEIGHT;
	col_offset = HEIGHT / 2 - col_h / 2;
	pix_x = ind_col;
	while (pix_x < n_pix_col + ind_col)
	{
		pix_y = col_offset;
		if (pix_y)
			draw_ceiling(data, pix_x, pix_y);
		while (pix_y < col_h + col_offset)
		{
			my_mlx_pixel_put(data, pix_x, pix_y, COLOR_RAY);
			pix_y++;
		}
		if (pix_y != HEIGHT)
			draw_floor(data, pix_x, pix_y);
		pix_x++;
	}
}