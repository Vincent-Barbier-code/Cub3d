/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 19:21:03 by vbarbier          #+#    #+#             */
/*   Updated: 2022/11/08 23:34:33 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

double	is_player(char c)
{
	if (c == 'N' || c == 'W' || c == 'E' || c == 'S')
	{
		if (c == 'N')
			return ((3 * M_PI) / 2);
		if (c == 'W')
			return (M_PI);
		if (c == 'E')
			return (0);
		if (c == 'S')
			return (M_PI / 2);
	}
	return (-1);
}

double	is_valid_char(t_map *map, int y, int x)
{
	static int	i = 0;

	if (!is_near_empty(map->carte[y][x]) && map->carte[y][x] != '0'\
	&& is_player(map->carte[y][x]) == -1)
		name_error(4);
	if (is_player(map->carte[y][x]) != -1)
	{
		i++;
		if (i > 1)
			name_error(5);
		return (is_player(map->carte[y][x]));
	}
	return (-1);
}

void	verif_char(t_data *data)
{
	int		x;
	int		y;
	double	front;

	x = 0;
	y = 0;
	data->player.front = -1;
	while (data->map->carte[y])
	{
		while (data->map->carte[y][x])
		{
			front = is_valid_char(data->map, y, x);
			if (front != -1)
				data->player.front = front;
			x++;
		}
		x = 0;
		y++;
	}
	if (data->player.front == -1)
		name_error(5);
}
