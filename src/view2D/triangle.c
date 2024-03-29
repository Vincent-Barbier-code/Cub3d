/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:20:20 by mvue              #+#    #+#             */
/*   Updated: 2022/11/12 22:24:41 by mvue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

void	trace_triangle(t_point a, t_point b, t_point c, t_data *data)
{
	t_line	l1;
	t_line	l2;
	t_line	l3;

	l1.color = COLOR_PLAYER;
	l2.color = COLOR_PLAYER;
	l3.color = COLOR_PLAYER;
	l1.data = data;
	l2.data = data;
	l3.data = data;
	l1.a = b;
	l1.b = a;
	l2.a = c;
	l2.b = b;
	l3.a = a;
	l3.b = c;
	trace_line(l1);
	trace_line(l2);
	trace_line(l3);
}

void	trace_tilted(t_data *data)
{
	t_player	player;
	t_point		top;
	t_point		left;
	t_point		right;

	player = data->player;
	top.x = SIZE_PLAYER * cos(player.front) + data->pos_px;
	top.y = SIZE_PLAYER * sin(player.front) + data->pos_py;
	left.x = SIZE_PLAYER * cos(player.front + 3 * M_PI / 4) + data->pos_px;
	left.y = SIZE_PLAYER * sin(player.front + 3 * M_PI / 4) + data->pos_py;
	right.x = SIZE_PLAYER * cos(player.front - 3 * M_PI / 4) + data->pos_px;
	right.y = SIZE_PLAYER * sin(player.front - 3 * M_PI / 4) + data->pos_py;
	trace_triangle(top, right, left, data);
}
