/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_t_dial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 02:09:49 by mvue              #+#    #+#             */
/*   Updated: 2022/10/12 20:31:29 by mvue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

static void	first_octal(t_line l, int dx, int dy)
{
	int	e;

	e = dx;
	dx = e * 2;
	dy *= 2;
	while (l.a.x != l.b.x)
	{
		my_mlx_pixel_put(l.data, l.a.x, l.a.y, l.color);
		e -= dy;
		if (e < 0)
		{
			l.a.y += 1;
			e += dx;
		}
		l.a.x += 1;
	}
}

void	first_dial(t_line l, int dx, int dy)
{
	int	e;
	if (dx >= dy)
		first_octal(l, dx, dy);
	else
	{
		e = dy;
		dy = e * 2;
		dx *= 2;
		while (l.a.y != l.b.y)
		{
			my_mlx_pixel_put(l.data, l.a.x, l.a.y, l.color);
			e -= dx;
			if (e < 0)
			{
				l.a.x += 1;
				e += dy;
			}
			l.a.y += 1;
		}
	}
	mlx_put_image_to_window(l.data->mlx, l.data->mlx_win, l.data->img, 0, 0);
}

static void	fourth_octal(t_line l, int dx, int dy)
{
	int	e;
	
	e = dx;
	dx = e * 2;
	dy *= 2;
	while (l.a.x != l.b.x)
	{
		my_mlx_pixel_put(l.data, l.a.x, l.a.y, l.color);
		e += dy;
		if (e >= 0)
		{
			l.a.y += 1;
			e += dx;
		}
		l.a.x -= 1;
	}
}

void	second_dial(t_line l, int dx, int dy)
{
	int	e;
	
	if (-dx >= dy)
		fourth_octal(l, dx, dy);
	else
	{
		e = dy;
		dy = e * 2;
		dx *= 2;
		while (l.a.y != l.b.y)
		{
			my_mlx_pixel_put(l.data, l.a.x, l.a.y, l.color);
			e += dx;
			if (e <= 0)
			{
				l.a.x -= 1;
				e += dy;
			}
			l.a.y += 1;
		}
	}
	mlx_put_image_to_window(l.data->mlx, l.data->mlx_win, l.data->img, 0, 0);
}
