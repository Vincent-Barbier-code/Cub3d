/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_triangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:26:37 by vbarbier          #+#    #+#             */
/*   Updated: 2022/10/14 00:23:10 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

// void	move_player_t(t_data *data, int key)
// {

// }

t_point	init_point(int x, int y)
{
	t_point	point;

	point.x = x;
	point.y = y;
	return (point);
}

void	init_triangle(t_data *data)
{
	t_point	left;
	t_point	right;
	t_line	line;
	t_line	line2;

	line.color = COLOR_PLAYER;
	line.data = data;
	right.x = data->player.x + SIZE_PLAYER;
	right.y = data->player.y + SIZE_PLAYER;
	left.x = data->player.x;
	left.y = right.y;
	line.a = right;
	line.b = left;
	// printf("data->player.x:%f\n", data->player.x);
	// printf("data->player.y x:%f\n", data->player.y);
	// printf("line A x:%d y:%d \n", line.a.x, line.a.y);
	// printf("line B x:%d y:%d \n", line.b.x, line.b.y);
	trace_line(line);
	line2 = line;
	right.x = data->player.x + SIZE_PLAYER / 2;
	right.y = data->player.y - SIZE_PLAYER / 2;
	line2.a = right;
	line2.b = line.a;
	// printf("line2 A x:%d y:%d \n", line2.a.x, line2.a.y);
	// printf("line2 B x:%d y:%d \n", line2.b.x, line2.b.y);
	trace_line(line2);
	line2.b = line.b;
	// printf("line2 A x:%d y:%d \n", line2.a.x, line2.a.y);
	// printf("line2 B x:%d y:%d \n", line2.b.x, line2.b.y);
	trace_line(line2);
}

void	draw_player_t(t_data *data)
{
	init_triangle(data);
}
