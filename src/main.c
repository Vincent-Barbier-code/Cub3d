/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 18:05:35 by vbarbier          #+#    #+#             */
/*   Updated: 2022/11/12 22:36:33 by mvue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

int	y_max_map(t_data *data)
{
	int	i;
	int	x;

	x = 0;
	i = 0;
	while (data->map->carte[i])
		i++;
	while (data->map->carte[i - 1][x])
		x++;
	if (data->map->carte[i - 1][x - 1] != '\n')
		data->map->carte[i - 1][x - 1] = '\n';
	return (i);
}

void	init_size_map(t_data *data)
{
	data->pos_map_x = (WIDTH - (WIDTH / 5) - GAP_MAP);
	data->pos_map_y = (HEIGHT - (HEIGHT / 3.25) - GAP_MAP);
	data->pos_px = (WIDTH - ((WIDTH / 5) / 2) - GAP_MAP);
	data->pos_py = (HEIGHT - ((HEIGHT / 3.25) / 2) - GAP_MAP);
}

void	parsing(int ac, char *name, t_data *data)
{
	name_file(ac, name);
	init_file(data, name);
	init_textures(data);
	get_textures(data);
	set_default_textures(data);
	set_default_colors(data);
	data->map->carte = data->file;
	data->map->y_max = y_max_map(data);
	clean_map(data);
	verif_wall(data);
	verif_char(data);
}

int	main(int ac, char **av)
{
	t_data	data;

	ft_garbage_collector(INIT, NULL);
	parsing(ac, av[1], &data);
	init_size_map(&data);
	new_window(&data);
	load_imgs(&data);
	affiche_2d(&data);
	mlx_hook(data.mlx_win, 2, 1L << 0, key_press, &data);
	mlx_hook(data.mlx_win, 17, 1L << 0, win_close, &data);
	mlx_loop(data.mlx);
	ft_garbage_collector(END, NULL);
}
