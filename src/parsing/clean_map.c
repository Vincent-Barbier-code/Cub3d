/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 22:48:09 by vbarbier          #+#    #+#             */
/*   Updated: 2022/09/18 19:58:15 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

void	ft_new_map(t_data *data, int y, int x)
{
	char *str;
	int	len;

	len = ft_strlen(data->map->carte[y]);
	if (data->map->carte[y][x + 1] == '\n')
		return ;
	str = ft_substr(data->map->carte[y], x + 1, len);
	data->map->carte[y] = ft_substr(data->map->carte[y], 0, x);
	data->map->carte[y] = ft_strjoin_2free(data->map->carte[y], str);
}

void	x_max_map(t_data *data)
{
	int	x;
	int	y;
	int max_x;

	max_x = 0;
	x = 0;
	y = 0;
	while (data->map->carte[y])
	{
		while (data->map->carte[y][x])
			x++;
		if (max_x < x)
			max_x = x;
		x = 0;
		y++;
	}
	data->map->x_max = max_x;
}

void	add_space(t_data *data, int y, int x)
{
	data->map->carte[y][x] = ' ';
	data->map->carte[y] = ft_strjoin_2free(data->map->carte[y], ft_strdup("\n"));
}

void	clean_map(t_data *data)
{
	int	x;
	int	y;

	x_max_map(data);
	x = 0;
	y = 0;
	while (data->map->carte[y])
	{
		while (data->map->carte[y][x])
		{	
			if (data->map->carte[y][x] == '\n' && x < data->map->x_max - 1)
				add_space(data, y, x); 
			x++;
		}
		x = 0;
		y++;
	}
}
