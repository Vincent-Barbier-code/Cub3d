/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_exceptions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 02:07:11 by mvue              #+#    #+#             */
/*   Updated: 2022/11/12 01:01:01 by mvue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

static void	horizontal_line(t_line l, int dx)
{
	if (dx > 0)
	{
		while (l.a.x != l.b.x)
		{
			my_mlx_pixel_put(l.data, l.a.x, l.a.y, l.color);
			l.a.x++;
		}
	}
	else
	{
		while (l.a.x != l.b.x)
		{
			my_mlx_pixel_put(l.data, l.a.x, l.a.y, l.color);
			l.a.x--;
		}
	}
	mlx_put_image_to_window(l.data->mlx, l.data->mlx_win, l.data->img, 0, 0);
}

static void	vertical_line(t_line l, int dy)
{
	if (dy > 0)
	{
		while (l.a.y != l.b.y)
		{
			my_mlx_pixel_put(l.data, l.a.x, l.a.y, l.color);
			l.a.y++;
		}
	}
	else
	{
		while (l.a.y != l.b.y)
		{
			my_mlx_pixel_put(l.data, l.a.x, l.a.y, l.color);
			l.a.y--;
		}
	}
	mlx_put_image_to_window(l.data->mlx, l.data->mlx_win, l.data->img, 0, 0);
}

int	line_exceptions(t_line l, int dx, int dy)
{
	if (dy == 0)
	{
		horizontal_line(l, dx);
		return (1);
	}
	if (dx == 0)
	{
		vertical_line(l, dy);
		return (1);
	}
	return (0);
}
