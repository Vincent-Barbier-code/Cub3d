/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:17:51 by mvue              #+#    #+#             */
/*   Updated: 2022/10/14 00:02:15 by mvue             ###   ########.fr       */
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

void	vertical_check(t_data	*data)
{
	t_trigo	tri;
	double	ntan;

	tri.ray_angle = data->player.front;
	ntan = -1 * tan(tri.ray_angle);
	tri.start_ray.x = data->player.x;
	tri.start_ray.y = data->player.y;
	if (tri.ray_angle == M_PI / 2 || tri.ray_angle == 3 * M_PI / 2)
	{
		tri.end_ray.x = data->player.x;
		tri.end_ray.y = data->player.y;
	}
	else
	{
		if (tri.ray_angle > M_PI / 2 && tri.ray_angle < 3 * M_PI / 2)
		{
			tri.end_ray.x = (((int)data->player.x >> 6) << 6) - 0.0001;
			tri.end_ray.y = (data->player.x - tri.end_ray.x) * ntan + data->player.y;
			launch_line(data, tri.start_ray, tri.end_ray);
		}
		if (tri.ray_angle < M_PI / 2 || tri.ray_angle > 3 * M_PI / 2)
		{
			tri.end_ray.x = (((int)data->player.x >> 6) << 6) + 64;
			tri.end_ray.y = (data->player.x - tri.end_ray.x) * ntan + data->player.y;
			launch_line(data, tri.start_ray, tri.end_ray);
		}
	}
}
//P2 = M_PI / 2
//P3 = 3 * M_PI / 2
void	launch_rays(t_data *data)
{
	t_trigo	tri;
	double	intan;

	tri.ray_angle = data->player.front;
	intan = -1 / tan(tri.ray_angle);
	tri.start_ray.x = data->player.x;
	tri.start_ray.y = data->player.y;
	if (tri.ray_angle == 0 || tri.ray_angle == M_PI || tri.ray_angle == 2 * M_PI)
	{
		tri.end_ray.x = data->player.x;
		tri.end_ray.y = data->player.y;
	}
	else
	{
		if (tri.ray_angle > M_PI)
		{
			tri.end_ray.y = (((int)data->player.y >> 6) << 6) - 0.0001;
			tri.end_ray.x = (data->player.y - tri.end_ray.y) * intan + data->player.x;
			launch_line(data, tri.start_ray, tri.end_ray);
		}
		if (tri.ray_angle < M_PI)
		{
			tri.end_ray.y = (((int)data->player.y >> 6) << 6) + 64;
			tri.end_ray.x = (data->player.y - tri.end_ray.y) * intan + data->player.x;
			launch_line(data, tri.start_ray, tri.end_ray);
		}
	}
}