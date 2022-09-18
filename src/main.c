/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 18:05:35 by vbarbier          #+#    #+#             */
/*   Updated: 2022/09/18 01:36:50 by vbarbier         ###   ########.fr       */
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
	// verif phrase du debut 
	// verif color
	name_file(ac, name);
	init_file(data, name);
	// marine
	data->map->carte = data->file;
	clean_map(data);
	//affiche_carte(data->map);
	verif_wall(data);
}

int	main(int ac, char **av)
{
	t_data	*data;

	ft_garbage_collector(INIT, NULL);
	data = ft_malloc(sizeof(t_data));
	parsing(ac, av[1], data);
	//affiche_file(data);
	ft_garbage_collector(END, NULL);
	//verif_open
	//use_gnl
	//verif_map
}