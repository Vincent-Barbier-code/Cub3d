/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:21:45 by mvue              #+#    #+#             */
/*   Updated: 2022/11/07 22:47:24 by mvue             ###   ########.fr       */
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