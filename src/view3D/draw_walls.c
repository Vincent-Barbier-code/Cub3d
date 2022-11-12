/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:07:27 by mvue              #+#    #+#             */
/*   Updated: 2022/11/12 18:43:54 by mvue             ###   ########.fr       */
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
	color = create_color(data->textures.ceiling[0], \
		data->textures.ceiling[1], data->textures.ceiling[2]);
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
	color = create_color(data->textures.floor[0], \
		data->textures.floor[1], data->textures.floor[2]);
	while (pix_y < HEIGHT)
	{
		my_mlx_pixel_put(data, pix_x, pix_y, color);
		pix_y++;
	}
}

void	draw_3d(t_data *data, t_3d col_3d, double save_col_h, t_img asset)
{
	while (col_3d.pix_x < col_3d.n_pix_col + col_3d.ind_col)
	{
		col_3d.pix_y = col_3d.col_offset;
		col_3d.tex_pos = (col_3d.pix_y - HEIGHT / 2 + save_col_h / 2) \
			* col_3d.tex_y_step;
		if (col_3d.pix_y)
			draw_ceiling(data, col_3d.pix_x, col_3d.pix_y);
		while (col_3d.pix_y < col_3d.col_h + col_3d.col_offset)
		{
			col_3d.tex_y = (int) col_3d.tex_pos & 63;
			col_3d.tex_pos += col_3d.tex_y_step;
			texture_to_sreen(col_3d, data, asset);
			col_3d.pix_y++;
		}
		if (col_3d.pix_y != HEIGHT)
			draw_floor(data, col_3d.pix_x, col_3d.pix_y);
		col_3d.pix_x++;
	}
}

void	trace_pix_column(t_data *data, double len_ray, \
	int n_pix_col, int ind_col)
{
	double		save_col_h;
	t_img		asset;
	t_3d		col_3d;

	if (ind_col == WIDTH)
		return ;
	asset = get_correct_texture(data);
	col_3d.col_h = SIZE_PIXEL * HEIGHT / len_ray;
	save_col_h = col_3d.col_h;
	col_3d.tex_y_step = 64.0 / col_3d.col_h;
	if (col_3d.col_h > HEIGHT)
		col_3d.col_h = HEIGHT;
	col_3d.col_offset = HEIGHT / 2 - col_3d.col_h / 2;
	col_3d.pix_x = ind_col;
	col_3d.tex_x = (int) data->textures.x_wall_hit % 64;
	if (data->textures.dir_looked == SO || data->textures.dir_looked == WE)
		col_3d.tex_x = 63 - col_3d.tex_x;
	col_3d.n_pix_col = n_pix_col;
	col_3d.ind_col = ind_col;
	draw_3d(data, col_3d, save_col_h, asset);
}
