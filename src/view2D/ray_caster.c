/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:17:51 by mvue              #+#    #+#             */
/*   Updated: 2022/10/20 17:01:53 by mvue             ###   ########.fr       */
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

int		is_wall(t_point p, char **map)
{
	int	ind_x;
	int	ind_y;

	ind_x = round(p.x / SIZE_PIXEL);
	ind_y = round(p.y / SIZE_PIXEL);
	if (map[ind_y][ind_x] == '1')
		return (1);
	else
		return (0);
}

void	vertical_check(t_data *data)
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
			printf("end_ray x : %d\n", tri.end_ray.x);
			printf("end_ray y : %d\n", tri.end_ray.y);
			if (is_wall(tri.end_ray, data->map->carte))
				printf("WALL\n");
			launch_line(data, tri.start_ray, tri.end_ray);
		}
		if (tri.ray_angle < M_PI / 2 || tri.ray_angle > 3 * M_PI / 2)
		{
			tri.end_ray.x = (((int)data->player.x >> 6) << 6) + 64;
			tri.end_ray.y = (data->player.x - tri.end_ray.x) * ntan + data->player.y;
			printf("end_ray x : %d\n", tri.end_ray.x);
			printf("end_ray y : %d\n", tri.end_ray.y);
			if (is_wall(tri.end_ray, data->map->carte))
				printf("WALL\n");			
			launch_line(data, tri.start_ray, tri.end_ray);
		}
	}
}

void	horizontal_check(t_data *data)
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