/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 02:20:22 by vbarbier          #+#    #+#             */
/*   Updated: 2022/09/17 21:14:54 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

static void	name_error(int cas)
{
	if (cas == 0)
		ft_putstr_fd("error : the name of the file is not a .cub", 2);
	if (cas == 1)
		ft_putstr_fd("error : the file is not a .cub", 2);
	if (cas == 2)
		ft_putstr_fd("error : numbers of arguments is invalid", 2);
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
