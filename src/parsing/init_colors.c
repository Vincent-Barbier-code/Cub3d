/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:15:02 by mvue              #+#    #+#             */
/*   Updated: 2022/11/08 19:21:54 by mvue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

void	set_default_color_floor(t_data *data, int *color_tab)
{
	color_tab[0] = 75;
	color_tab[1] = 78;
	color_tab[2] = 82;
	data->textures.floor = color_tab;
}

void	set_default_color_ceiling(t_data *data, int *color_tab)
{
	color_tab[0] = 186;
	color_tab[1] = 212;
	color_tab[2] = 209;
	data->textures.ceiling = color_tab;
}

void	set_default_colors(t_data *data)
{
	int	*color_floor;
	int	*color_ceiling;

	if (!data->textures.ceiling)
	{
		color_ceiling = ft_malloc(sizeof(int) * 3);
		if (!color_ceiling)
		{
			ft_garbage_collector(END, NULL);
			exit(1);
		}
		set_default_color_ceiling(data, color_ceiling);
	}
	if (!data->textures.floor)
	{
		color_floor = ft_malloc(sizeof(int) * 3);
		if (!color_floor)
		{
			ft_garbage_collector(END, NULL);
			exit(1);
		}
		set_default_color_floor(data, color_floor);
	}
}