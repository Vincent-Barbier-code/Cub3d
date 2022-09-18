/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 19:21:03 by vbarbier          #+#    #+#             */
/*   Updated: 2022/09/18 19:56:57 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

int	is_player(char c)
{
	static int i = 0;

	if (c == 'N' || c == 'W' || c == 'E' || c == 'S')
	{
		i++;
		return (i);
	}
	return (0);
}

void	is_valid_char(t_map *map, int y, int x)
{
	if (!is_near_empty(map->carte[y][x]) && map->carte[y][x] != '0'\
	&& !is_player(map->carte[y][x]))
		name_error(4);

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
}
