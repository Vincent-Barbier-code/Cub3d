/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:17:51 by mvue              #+#    #+#             */
/*   Updated: 2022/10/21 18:12:49 by mvue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

void	launch_line(t_data *data, t_point a, t_point b)
{
	t_line	line;

	line.data = data;
	line.a = a;
	line.b = b;
	line.color = COLOR_RAY;
	trace_line(line);
}

int		is_wall(t_point p, t_map map)
{
	int	ind_x;
	int	ind_y;
	int	stop;

	ind_x = p.x >> 6;
	ind_y = p.y >> 6;
	stop = 0;
	if (ind_x >= map.x_max || ind_x < 1 || ind_y >= map.y_max || ind_y < 1)
		stop = 1;
	if (stop || map.carte[ind_y][ind_x] == '1')
		return (1);
	return (0);
}

t_trigo	vertical_check(t_data *data, double angle)
{
	int		stop;
	t_trigo	tri;
	double	ntan;
	double	dx;
	double	dy;

	stop = 0;
	dx = 0;
	dy = 0;
	tri.ray_angle = angle;
	ntan = -1 * tan(tri.ray_angle);
	tri.start_ray.x = data->player.x;
	tri.start_ray.y = data->player.y;
	if (tri.ray_angle > M_PI / 2 && tri.ray_angle < 3 * M_PI / 2) //regarde a gauche
	{
		tri.end_ray.x = (((int)data->player.x >> 6) << 6) - 0.0001;
		tri.end_ray.y = (data->player.x - tri.end_ray.x) * ntan + data->player.y;
		dx = -64;
		dy = -dx * ntan;
	}
	else if (tri.ray_angle < M_PI / 2 || tri.ray_angle > 3 * M_PI / 2) //regarde a droite
	{
		tri.end_ray.x = (((int)data->player.x >> 6) << 6) + 64;
		tri.end_ray.y = (data->player.x - tri.end_ray.x) * ntan + data->player.y;		
		dx =  64;
		dy = -dx * ntan;
	}
	else
	{
		stop = 1;
		tri.end_ray.x = data->player.x;
		tri.end_ray.y = data->player.y;
	}
	if (!stop)
	{
		while (!(is_wall(tri.end_ray, *data->map)))
		{
			tri.end_ray.x += dx;
			tri.end_ray.y += dy;
		}
	}
	return (tri);
}

t_trigo	horizontal_check(t_data *data, double angle)
{
	int		stop;
	t_trigo	tri;
	double	intan;
	double	dx;
	double	dy;

	stop = 0;
	dx = 0;
	dy = 0;
	tri.ray_angle = angle;
	intan = -1 / tan(tri.ray_angle);
	tri.start_ray.x = data->player.x;
	tri.start_ray.y = data->player.y;
	if (tri.ray_angle > M_PI) //regarde en bas
	{
		tri.end_ray.y = (((int)data->player.y >> 6) << 6) - 0.0001;
		tri.end_ray.x = (data->player.y - tri.end_ray.y) * intan + data->player.x;
		dy = -64;
		dx = -dy * intan;
	}
	else if (tri.ray_angle < M_PI && tri.ray_angle != 0) //regarde en haut
	{
		tri.end_ray.y = (((int)data->player.y >> 6) << 6) + 64;
		tri.end_ray.x = (data->player.y - tri.end_ray.y) * intan + data->player.x;
		dy = 64;
		dx = -dy * intan;
	}
	else
	{
		stop = 1;
		tri.end_ray.x = data->player.x;
		tri.end_ray.y = data->player.y;
	}
	if (!stop)
	{
		while (!(is_wall(tri.end_ray, *data->map)))
		{
			tri.end_ray.x += dx;
			tri.end_ray.y += dy;
		}
	}
	return (tri);
}

double	distance(t_point a, t_point b)
{
	return (sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y)));
}

void	trace_ray(t_data *data, double angle)
{
	t_trigo	hori;
	t_trigo	vert;
	double	dist_h;
	double	dist_v;

	hori = horizontal_check(data, angle);
	vert = vertical_check(data, angle);
	dist_h = distance(hori.start_ray, hori.end_ray);
	dist_v = distance(vert.start_ray, vert.end_ray);
	if (dist_h > 0 && dist_h < dist_v)
		launch_line(data, hori.start_ray, hori.end_ray);
	if (dist_v > 0 && dist_v < dist_h)
		launch_line(data, vert.start_ray, vert.end_ray);
}

double	abs_angle(double angle)
{
	if (angle < 0)
		angle += M_PI * 2;
	return (angle);
}

void	trace_rays(t_data *data)
{
	double	angle_start;
	double	angle_end;
	int		num_pix_width;
	double	step;

	num_pix_width = 50;
	angle_start = data->player.front - M_PI / 6;
	angle_end = data->player.front + M_PI / 6;
	step = (angle_end - angle_start) / num_pix_width;
	while (angle_start < angle_end)
	{
		trace_ray(data, abs_angle(angle_start));
		angle_start += step;
	}
}