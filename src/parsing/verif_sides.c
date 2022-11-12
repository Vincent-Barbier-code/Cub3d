/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_sides.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:38:57 by vbarbier          #+#    #+#             */
/*   Updated: 2022/11/12 21:30:53 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

int	verif_up(t_map *map, int y, int x, int (*f)(char))
{
	if (y)
	{
		if (f(map->carte[y - 1][x]))
			return (1);
		else
			return (0);
	}
	return (2);
}

int	verif_down(t_map *map, int y, int x, int (*f)(char))
{
	if (y < map->y_max - 1)
	{
		if (f(map->carte[y + 1][x]))
			return (1);
		else
			return (0);
	}
	return (2);
}

int	verif_right(t_map *map, int y, int x, int (*f)(char))
{
	if (x != map->x_max)
	{
		if (f(map->carte[y][x + 1]))
			return (1);
		else
			return (0);
	}
	return (2);
}

int	verif_left(t_map *map, int y, int x, int (*f)(char))
{
	if (x)
	{
		if (f(map->carte[y][x - 1]))
			return (1);
		else
			return (0);
	}
	return (2);
}
