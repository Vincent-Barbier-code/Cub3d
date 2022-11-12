/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 01:15:58 by mvue              #+#    #+#             */
/*   Updated: 2022/11/12 01:20:57 by mvue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

static int		is_wall(t_point_f p, t_map map)
{
	int	ind_x;
	int	ind_y;
	int	stop;

	ind_x = (int)p.x >> 6;
	ind_y = (int)p.y >> 6;
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
	if (tri.ray_angle > M_PI / 2 && tri.ray_angle < 3 * M_PI / 2)
	{
		tri.end_ray.x = (((int)data->player.x >> 6) << 6) - 0.0001;
		tri.end_ray.y = (data->player.x - tri.end_ray.x) * ntan + data->player.y;
		dx = -64;
		dy = -dx * ntan;
	}
	else if (tri.ray_angle < M_PI / 2 || tri.ray_angle > 3 * M_PI / 2)
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
	if (tri.ray_angle > M_PI)
	{
		tri.end_ray.y = (((int)data->player.y >> 6) << 6) - 0.0001;
		tri.end_ray.x = (data->player.y - tri.end_ray.y) * intan + data->player.x;
		dy = -64;
		dx = -dy * intan;
	}
	else if (tri.ray_angle < M_PI && tri.ray_angle != 0)
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
