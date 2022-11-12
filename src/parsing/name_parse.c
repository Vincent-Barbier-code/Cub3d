/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 02:20:22 by vbarbier          #+#    #+#             */
/*   Updated: 2022/11/12 20:45:32 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

void	name_error(int cas)
{
	if (cas == 0)
		ft_putstr_fd("Error\nName of the file is not valid\n", 2);
	if (cas == 1)
		ft_putstr_fd("Error\nThe file is not a .cub\n", 2);
	if (cas == 2)
		ft_putstr_fd("Error\nNumber of arguments is invalid\n", 2);
	if (cas == 3)
		ft_putstr_fd("Error\nMap : not closed by walls\n", 2);
	if (cas == 4)
		ft_putstr_fd("Error\nMap : invalid character(s)\n", 2);
	if (cas == 5)
		ft_putstr_fd("Error\nMap : invalid number of player\n", 2);
	if (cas == 6)
		ft_putstr_fd("Error\nMlx : initializing new window\n", 2);
	ft_garbage_collector(END, NULL);
	exit(EXIT_FAILURE);
}

void	not_just_cub(char *av, char *ber)
{
	av--;
	if (*av == '/')
		name_error(0);
	av++;
	while (*av)
	{
		if (*av != *ber)
			name_error(1);
		av++;
		ber++;
	}
}

void	name_file(int ac, char *av)
{
	char	*ber;
	int		len;

	ber = ".cub";
	if (ac == 2)
	{
		len = ft_strlen(av);
		if (len <= 4)
			name_error(0);
		while (len - 4)
		{
			len--;
			av++;
		}
		not_just_cub(av, ber);
	}
	else
		name_error(2);
}
