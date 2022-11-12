/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:17:51 by mvue              #+#    #+#             */
/*   Updated: 2022/11/12 02:39:27 by mvue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

static void	top_dial(t_data *data, t_trigo tri, int is_hori)
{
	if (is_hori)
		data->textures.dir_looked = SO;
	else
	{
		if (tri.ray_angle < M_PI / 2)
			data->textures.dir_looked = EA;
		else
			data->textures.dir_looked = WE;
	}
}

static void	bot_dial(t_data *data, t_trigo tri, int is_hori)
{
	if (is_hori)
		data->textures.dir_looked = NO;
	else
	{
		if (tri.ray_angle < 3 * M_PI / 2)
			data->textures.dir_looked = WE;
		else
			data->textures.dir_looked = EA;
	}
}

void	set_pos_looked(t_data *data, t_trigo tri, int is_hori)
{
	if (tri.ray_angle < M_PI)
		top_dial(data, tri, is_hori);
	else
		bot_dial(data, tri, is_hori);
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
		return (dist_h);
	}
	else
	{
		set_pos_looked(data, vert, 0);
		data->textures.x_wall_hit = vert.end_ray.y;
		return (dist_v);
	}
}

void	trace_rays(t_data *data)
{
	t_rays	rays;
	double	angle_fish;
	int		n_pix_col;
	int		ind_col;

	n_pix_col = round(WIDTH / NUM_RAYS);
	rays.angle_start = data->player.front - M_PI / 6;
	rays.angle_end = data->player.front + M_PI / 6;
	rays.step = (rays.angle_end - rays.angle_start) / NUM_RAYS;
	ind_col = 0;
	while (rays.angle_start < rays.angle_end)
	{
		rays.len_ray = trace_ray(data, abs_angle(rays.angle_start));
		angle_fish = abs_angle(rays.angle_start - data->player.front);
		rays.len_ray *= cos(angle_fish);
		trace_pix_column(data, rays.len_ray, \
			n_pix_col, round(ind_col * n_pix_col));
		rays.angle_start += rays.step;
		ind_col++;
	}
}
