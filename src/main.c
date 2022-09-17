/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 18:05:35 by vbarbier          #+#    #+#             */
/*   Updated: 2022/09/17 23:14:45 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void	affiche_map(t_data *data)
{
	int i;

	i = 0;
	while (data->map[i])
		printf("%s", data->map[i++]);
}

void	parsing(int ac, char *name, t_data *data)
{
	// verif phrase du debut 
	// verif color
	name_file(ac, name);
	init_map(data, name);
	// clean_map(data);
	// verif_wall(data);
}

int	main(int ac, char **av)
{
	t_data	*data;

	ft_garbage_collector(INIT, NULL);
	data = ft_malloc(sizeof(t_data));
	parsing(ac, av[1], data);
	affiche_map(data);
	ft_garbage_collector(END, NULL);
	//verif_open
	//use_gnl
	//verif_map
}