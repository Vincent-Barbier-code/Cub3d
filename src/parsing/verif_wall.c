/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 22:51:48 by vbarbier          #+#    #+#             */
/*   Updated: 2022/09/18 15:29:40 by vbarbier         ###   ########.fr       */
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

int	verif_up(t_map *map, int y, int x)
{
	if (y)
	{
		if (is_near_empty(map->carte[y - 1][x]))
			return (1);
		else
		{
			printf("U");
			return (0);
		}
	}
	return (2);
	
}

int	verif_down(t_map *map, int y, int x)
{
	if (y < map->y_max - 1)
	{
		if (is_near_empty(map->carte[y + 1][x]))
			return (1);
		else
		{
			printf("D");
			return (0);
		}
	}
	return (2);
}

int	verif_right(t_map *map, int y, int x)
{
	if (x != map->x_max)
	{
		if (is_near_empty(map->carte[y][x + 1]))
			return (1);
		else
		{
			printf("R");
			return (0);
		}
	}
	return (2);
}

int	verif_left(t_map *map, int y, int x)
{
	if (x)
	{
		if (is_near_empty(map->carte[y][x - 1]))
			return (1);
		else
		{
			printf("L");
			return (0);
		}
	}
		return (2);
}


int	verif_w(t_map *map, int y, int x)
{
	if (ft_isspc(map->carte[y][x]))
	{
		if (!verif_up(map, y, x) || !verif_down(map, y, x)\
		|| !verif_right(map, y, x) || !verif_left(map, y, x))
		{
			name_error(3);
			return (0);
		}
		//printf("E%c", map->carte[y][x]);
	}
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
		{
			verif_w(data->map, y, x);
			printf("%c", data->map->carte[y][x]);
			x++;
		}
		x = 0;
		// printf("%s", data->map->carte[y]);
		y++;
	}
}