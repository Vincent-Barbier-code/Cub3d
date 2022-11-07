/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:07:27 by mvue              #+#    #+#             */
/*   Updated: 2022/11/07 23:09:32 by mvue             ###   ########.fr       */
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
	double		col_h;
	double		save_col_h;
	double		col_offset;
	int			pix_x;
	int			pix_y;
	int			tex_x;
	int			tex_y;
	double		tex_pos;
	t_img		asset;
	float		tex_y_step;

	if (ind_col == WIDTH)
		return ;
	asset = get_correct_texture(data);
	col_h = SIZE_PIXEL * HEIGHT / len_ray;
	save_col_h = col_h;
	tex_y_step = 64.0 / col_h;
	if (col_h > HEIGHT)
		col_h = HEIGHT;
	col_offset = HEIGHT / 2 - col_h / 2;
	pix_x = ind_col;
	tex_x = (int) data->textures.x_wall_hit % 64;
	if (data->textures.dir_looked == SO || data->textures.dir_looked == WE)
		tex_x = 63 - tex_x;
	while (pix_x < n_pix_col + ind_col)
	{
		pix_y = col_offset;
		tex_pos = (pix_y - HEIGHT / 2 + save_col_h / 2) * tex_y_step;
		if (pix_y)
			draw_ceiling(data, pix_x, pix_y);
		while (pix_y < col_h + col_offset)
		{
			tex_y = (int) tex_pos & 63;
			tex_pos += tex_y_step;
			data->addr[pix_y * data->line_length + pix_x * data->bits_per_pixel / 8] \
				= asset.addr[(int)tex_y * asset.line_length + (int)tex_x * asset.bits_per_pixel / 8];
			data->addr[pix_y * data->line_length + pix_x * data->bits_per_pixel / 8 + 1] \
				= asset.addr[(int)tex_y * asset.line_length + (int)tex_x * asset.bits_per_pixel / 8 + 1];
			data->addr[pix_y * data->line_length + pix_x * data->bits_per_pixel / 8 + 2] \
				= asset.addr[(int)tex_y * asset.line_length + (int)tex_x * asset.bits_per_pixel / 8 + 2];
			pix_y++;
		}
		if (pix_y != HEIGHT)
			draw_floor(data, pix_x, pix_y);
		pix_x++;
	}
}