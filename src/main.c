/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 18:05:35 by vbarbier          #+#    #+#             */
/*   Updated: 2022/10/29 15:56:31 by vbarbier         ###   ########.fr       */
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

int	y_max_map(t_map *map)
{
	int i;

	i = 0;
	while (map->carte[i])
		i++;
	return (i);
}

void	parsing(int ac, char *name, t_data *data)
{

	name_file(ac, name);
	init_file(data, name);
	init_textures(data);
	get_textures(data);
	// verif color
	data->map->carte = data->file;
	data->map->y_max = y_max_map(data->map);
	// affiche_carte(data->map);
	// affiche_file(data);
	clean_map(data);
	verif_wall(data);
	verif_char(data);
}

int	main(int ac, char **av)
{
	t_data	data;

	ft_garbage_collector(INIT, NULL);
	parsing(ac, av[1], &data);
	new_window(&data);
	affiche_2d(&data);

	mlx_key_hook(data.mlx_win, key_press, &data); // bouger camera + ESCAPE
	mlx_hook(data.mlx_win, 17, 1L << 0, win_close, &data);
	// mlx_hook(data.mlx_win, 3, 1L << 1, key_release, &data);
	
	mlx_loop(data.mlx);
	ft_garbage_collector(END, NULL);
}
