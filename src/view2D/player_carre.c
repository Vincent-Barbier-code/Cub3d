/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_carre.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:23:56 by vbarbier          #+#    #+#             */
/*   Updated: 2022/11/12 19:31:35 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

int	can_move(t_data *data, int pos, char c)
{
	int	size;

	size = SIZE_PIXEL;
	if (c == 'y' && (data->map->carte[pos / size] \
	[(int) data->player.x / size] == '1' \
	|| data->map->carte[(pos + SIZE_PLAYER) / size] \
	[(int) data->player.x / size] == '1'))
		return (0);
	if (c == 'x' && (data->map->carte[(int) data->player.y / size] \
	[pos / size] == '1' \
	|| data->map->carte[(int) data->player.y / size] \
	[(pos + SIZE_PLAYER) / size] == '1' \
	|| data->map->carte[(int)(data->player.y + SIZE_PLAYER) / size] \
	[(pos + SIZE_PLAYER) / size] == '1' \
	|| data->map->carte[(int)(data->player.y + SIZE_PLAYER) / size] \
	[pos / size] == '1'))
		return (0);
	return (1);
}
