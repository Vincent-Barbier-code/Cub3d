/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:21:45 by mvue              #+#    #+#             */
/*   Updated: 2022/11/12 18:44:41 by mvue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

t_img	get_correct_texture(t_data *data)
{
	t_img	asset;

	if (data->textures.dir_looked == NO)
		asset = data->textures.asset_NO;
	if (data->textures.dir_looked == SO)
		asset = data->textures.asset_SO;
	if (data->textures.dir_looked == WE)
		asset = data->textures.asset_WE;
	if (data->textures.dir_looked == EA)
		asset = data->textures.asset_EA;
	return (asset);
}

void	texture_to_sreen(t_3d col_3d, t_data *data, t_img asset)
{
	data->addr[col_3d.pix_y * data->line_length + col_3d.pix_x * \
		data->bits_per_pixel / 8] = asset.addr[(int)col_3d.tex_y * \
		asset.line_length + (int)col_3d.tex_x * asset.bits_per_pixel / 8];
	data->addr[col_3d.pix_y * data->line_length + col_3d.pix_x * \
		data->bits_per_pixel / 8 + 1] = asset.addr[(int)col_3d.tex_y * \
		asset.line_length + (int)col_3d.tex_x * asset.bits_per_pixel / 8 + 1];
	data->addr[col_3d.pix_y * data->line_length + col_3d.pix_x * \
		data->bits_per_pixel / 8 + 2] = asset.addr[(int)col_3d.tex_y * \
		asset.line_length + (int)col_3d.tex_x * asset.bits_per_pixel / 8 + 2];
}
