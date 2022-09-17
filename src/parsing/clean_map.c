/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 22:48:09 by vbarbier          #+#    #+#             */
/*   Updated: 2022/09/17 23:09:43 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' \
	|| c == '\r' || c == '\v' || c == '\f')
		return (1);
	return (0);
}

// void	ft_new_map(t_data *data, int y, int x)
// {
// 	char *str;
// 	int	len;

// 	len = ft_strlen(data->map[y]);
// 	if (data->map[y][x + 1] == '\n')
// 		return ;
// 	str = ft_substr(data->map[y], x + 1, len);
// 	data->map[y] = ft_substr(data->map[y], 0, x);
// 	data->map[y] = ft_strjoin_2free(data->map[y], str);
// }

// void	clean_map(t_data *data)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	y = 0;
// 	while (data->map[y])
// 	{
// 		while (data->map[y][x])
// 		{
// 			if (ft_isspace(data->map[y][x]))
// 				ft_new_map(data, y, x);
// 			x++;
// 		}
// 		x = 0;
// 		y++;
// 	}
// }
