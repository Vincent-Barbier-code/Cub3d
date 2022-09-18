/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 22:51:48 by vbarbier          #+#    #+#             */
/*   Updated: 2022/09/18 17:47:18 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

int	ft_isspc(char c)
{
	if (c == ' ' || c == '\t' \
	|| c == '\r' || c == '\v' || c == '\f')
		return (1);
	return (0);
}

int is_near_empty(char c)
{
	if (c == '\n' || c == '1' || ft_isspc(c)\
	|| c == '\0')
		return (1);
	return (0);
}

int	verif_all_sides(t_map *map, int y, int x)
{
	if (ft_isspc(map->carte[y][x]))
	{
		if (!verif_up(map, y, x, &is_near_empty) \
		|| !verif_down(map, y, x, &is_near_empty) \
		|| !verif_right(map, y, x, &is_near_empty) \
		|| !verif_left(map, y, x, &is_near_empty))
			name_error(3);
	}
	if (y == map->y_max - 1 && !is_near_empty(map->carte[y][x]))
		name_error(3);
	return (1);
}

void	verif_wall(t_data *data)
{
	int x;
	int	y;

	x = 0;
	y = 0;
	while (data->map->carte[y])
	{
		while (data->map->carte[y][x])
			verif_all_sides(data->map, y, x++);
		x = 0;
		y++;
	}
}
