/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 18:05:35 by vbarbier          #+#    #+#             */
/*   Updated: 2022/11/12 21:33:35 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void	affiche_file(t_data *data)
{
	int i;

	i = 0;
	while (data->file[i])
		printf("%s", data->file[i++]);
}

void	affiche_carte(t_map *map)
{
	int i;

	i = 0;
	while (map->carte[i])
		printf("%s", map->carte[i++]);
}

int	y_max_map(t_data *data)
{
	int i;
	int x;

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
	data->POS_MAP_X = (WIDTH - (WIDTH / 4) - GAP_MAP);
	data->POS_MAP_Y = (HEIGHT - (HEIGHT / 2.5) - GAP_MAP);
	data->POS_PX = (WIDTH - ((WIDTH / 4) / 2) - GAP_MAP);
	data->POS_PY = (HEIGHT - ((HEIGHT / 2.5) / 2) - GAP_MAP);
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
	printf(" LA= %d \n", data->map->y_max);
	affiche_carte(data->map);
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
	//trace_tilted(&data);
	mlx_hook(data.mlx_win, 2, 1L << 0, key_press, &data);
	mlx_hook(data.mlx_win, 17, 1L << 0, win_close, &data);
	// mlx_hook(data.mlx_win, 3, 1L << 1, key_release, &data);
	mlx_loop(data.mlx);
	ft_garbage_collector(END, NULL);
}
