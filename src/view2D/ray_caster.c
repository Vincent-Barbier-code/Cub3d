/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:17:51 by mvue              #+#    #+#             */
/*   Updated: 2022/11/12 01:20:46 by mvue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

void	set_pos_looked(t_data *data, t_trigo tri, int is_hori)
{

	if (tri.ray_angle < M_PI / 2)
	{
		if (is_hori)
			data->textures.dir_looked = SO;
		else
			data->textures.dir_looked = EA;
	}
	else if (tri.ray_angle < M_PI)
	{
		if (is_hori)
			data->textures.dir_looked = SO;
		else
			data->textures.dir_looked = WE;
	}
	else if (tri.ray_angle < 3 * M_PI / 2)
	{
		if (is_hori)
			data->textures.dir_looked = NO;
		else
			data->textures.dir_looked = WE;
	}
	else
	{
		if (is_hori)
			data->textures.dir_looked = NO;
		else
			data->textures.dir_looked = EA;
	}
}

double	trace_ray(t_data *data, double angle)
{
	t_trigo	hori;
	t_trigo	vert;
	double	dist_h;
	double	dist_v;

	hori = horizontal_check(data, angle);
	vert = vertical_check(data, angle);
	dist_h = distance(hori.start_ray, hori.end_ray);
	dist_v = distance(vert.start_ray, vert.end_ray);
	if (dist_v == 0)
		dist_v = WIDTH;
	if (dist_h == 0)
		dist_h = HEIGHT;
	if (dist_h < dist_v)
	{
		set_pos_looked(data, hori, 1);
		data->textures.x_wall_hit = hori.end_ray.x;
		return(dist_h);
	}
	else
	{
		set_pos_looked(data, vert, 0);
		data->textures.x_wall_hit = vert.end_ray.y;
		return(dist_v);
	}
}

void	trace_rays(t_data *data)
{
	double	angle_start;
	double	angle_end;
	double	step;
	double	angle_fish;
	double	len_ray;
	int		n_pix_col;
	int		ind_col;

	n_pix_col = round(WIDTH / NUM_RAYS);
	angle_start = data->player.front - M_PI / 6;
	angle_end = data->player.front + M_PI / 6;
	step = (angle_end - angle_start) / NUM_RAYS;
	ind_col = 0;
	while (angle_start < angle_end)
	{
		len_ray = trace_ray(data, abs_angle(angle_start));
		angle_fish = abs_angle(angle_start - data->player.front);
		len_ray *= cos(angle_fish);
		trace_pix_column(data, len_ray, n_pix_col, round(ind_col * n_pix_col));
		angle_start += step;
		ind_col++;
	}
}
