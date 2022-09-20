/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 18:05:35 by vbarbier          #+#    #+#             */
/*   Updated: 2022/09/20 19:11:39 by vbarbier         ###   ########.fr       */
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

void	parsing(int ac, char *name, t_data *data)
{

	name_file(ac, name);
	init_file(data, name);
	// marine
	// verif phrase du debut 
	// verif color
	data->map->carte = data->file;
	clean_map(data);
	// affiche_carte(data->map);
	verif_wall(data);
	verif_char(data);
}

int	main(int ac, char **av)
{
	t_data	data;

	ft_garbage_collector(INIT, NULL);
	parsing(ac, av[1], &data);
	// affiche_file(&data);
	new_window(&data);
	affiche_2D(&data);

	mlx_key_hook(data.mlx_win, key_hook, &data); // bouger camera + ESCAPE
	mlx_hook(data.mlx_win, 17, 1L << 2, win_close, &data);
	mlx_loop(data.mlx);
	ft_garbage_collector(END, NULL);
}
