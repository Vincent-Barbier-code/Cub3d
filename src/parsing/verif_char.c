/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 19:21:03 by vbarbier          #+#    #+#             */
/*   Updated: 2022/09/18 20:08:23 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

int	is_player(char c)
{
	if (c == 'N' || c == 'W' || c == 'E' || c == 'S')
		return (1);
	return (0);
}

int	is_valid_char(t_map *map, int y, int x)
{
	static int i = 0;

	if (!is_near_empty(map->carte[y][x]) && map->carte[y][x] != '0'\
	&& !is_player(map->carte[y][x]))
		name_error(4);
	if (is_player(map->carte[y][x]))
		i++;
	if (i > 1)
		name_error(5);
	return (i);
}

void	verif_char(t_data *data)
{
	int x;
	int	y;

	x = 0;
	y = 0;
	while (data->map->carte[y])
	{
		while (data->map->carte[y][x])
			is_valid_char(data->map, y, x++);
		x = 0;
		y++;
	}
	if (!is_valid_char(data->map, y - 1, x))
		name_error(5);
}
