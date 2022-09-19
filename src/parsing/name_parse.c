/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 02:20:22 by vbarbier          #+#    #+#             */
/*   Updated: 2022/09/18 22:34:20 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

void	name_error(int cas)
{
	if (cas == 0)
		ft_putstr_fd("Error\nName of the file is not valid", 2);
	if (cas == 1)
		ft_putstr_fd("Error\nThe file is not a .cub", 2);
	if (cas == 2)
		ft_putstr_fd("Error\nNumbers of arguments is invalid", 2);
	if (cas == 3)
		ft_putstr_fd("Error\nMap : not closed by walls", 2);
	if (cas == 4)
		ft_putstr_fd("Error\nMap : invalid character(s)", 2);
	if (cas == 5)
		ft_putstr_fd("Error\nMap : invalid number of player", 2);
	if (cas == 6)
		ft_putstr_fd("Error\nMlx : initializing new window", 2);
	ft_garbage_collector(END, NULL);
	exit(EXIT_FAILURE);
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
		while (*av)
		{
			if (*av != *ber)
				name_error(1);
			av++;
			ber++;
		}
	}
	else
		name_error(2);
}
