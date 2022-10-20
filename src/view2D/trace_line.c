/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 22:01:33 by mvue              #+#    #+#             */
/*   Updated: 2022/10/12 20:30:03 by mvue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

static void	fith_octal(t_line l, int dx, int dy)
{
	int	e;
	
	e = dx;
	dx = e * 2;
	dy *= 2;
	while (l.a.x != l.b.x)
	{
		my_mlx_pixel_put(l.data, l.a.x, l.a.y, l.color);
		e -= dy;
		if (e >= 0)
		{
			l.a.y -= 1;
			e += dx;
		}
		l.a.x -= 1;
	}
}

static void	third_dial(t_line l, int dx, int dy)
{
	int	e;
	
	if (dx <= dy)
		fith_octal(l, dx, dy);
	else
	{
		e = dy;
		dy = e * 2;
		dx *= 2;
		while (l.a.y != l.b.y)
		{
			my_mlx_pixel_put(l.data, l.a.x, l.a.y, l.color);
			e -= dx;
			if (e >= 0)
			{
				l.a.x -= 1;
				e += dy;
			}
			l.a.y -= 1;
		}
	}
	mlx_put_image_to_window(l.data->mlx, l.data->mlx_win, l.data->img, 0, 0);
}

static void	eigth_octal(t_line l, int dx, int dy)
{
	int	e;
	
	e = dx;
	dx = e * 2;
	dy *= 2;
	while (l.a.x != l.b.x)
	{
		my_mlx_pixel_put(l.data, l.a.x, l.a.y, l.color);
		e += dy;
		if (e < 0)
		{
			l.a.y -= 1;
			e += dx;
		}
		l.a.x += 1;
	}
}

static void	fourth_dial(t_line l, int dx, int dy)
{
	int	e;
	
	if (dx >= -dy)
		eigth_octal(l, dx, dy);
	else
	{
		e = dy;
		dy = e * 2;
		dx *= 2;
		while (l.a.y != l.b.y)
		{
			my_mlx_pixel_put(l.data, l.a.x, l.a.y, l.color);
			e += dx;
			if (e > 0)
			{
				l.a.x += 1;
				e += dy;
			}
			l.a.y -= 1;
		}
	}
	mlx_put_image_to_window(l.data->mlx, l.data->mlx_win, l.data->img, 0, 0);
}

void	trace_line(t_line l)
{
	int dx;
	int dy;

	dx = l.b.x - l.a.x;
	dy = l.b.y - l.a.y;
	if (line_exceptions(l, dx, dy))
		return ;
	if (dx > 0)
	{
		if (dy > 0)
			first_dial(l, dx, dy);
		else
			fourth_dial(l, dx, dy);
	}
	else
	{
		if (dy > 0)
			second_dial(l, dx, dy);
		else
			third_dial(l, dx, dy);
	}
}