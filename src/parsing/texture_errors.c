/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:48:33 by mvue              #+#    #+#             */
/*   Updated: 2022/11/12 00:47:17 by mvue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

void	color_errors(int err_num)
{
	if (err_num == ERR_COLOR)
	{
		ft_putstr_fd("Error\nWrong color format\n", 2);
		ft_putstr_fd("Give the color in RGB separated by comas\n", 2);
		ft_putstr_fd("Ex : 100,10,50\n", 2);
	}
	if (err_num == ERR_COLOR_NUM)
	{
		ft_putstr_fd("Error\nWrong color number, ", 2);
		ft_putstr_fd("colors must be between 0 and 255\n", 2);
	}
	if (err_num == ERR_NUM_COLOR)
		ft_putstr_fd("Error\nMultiple colors given\n", 2);
	ft_garbage_collector(END, NULL);
	exit (1);
}

void	textures_errors(int err_num)
{
	if (err_num == ERR_TEXT_UNRECO)
	{
		ft_putstr_fd("Error\nTexture or color identifier unrecognized.\n", 2);
		ft_putstr_fd("Textures are identified by NO, SO, WE or EA ", 2);
		ft_putstr_fd("and colors by F or C\n", 2);
	}
	if (err_num == ERR_WRONG_FILE)
	{
		ft_putstr_fd("Error\nCoulnd't open texture file : ", 2);
		perror("");
	}
	if (err_num == ERR_NUM_PATH)
		ft_putstr_fd("Error\nMultiple paths given\n", 2);
	ft_garbage_collector(END, NULL);
	exit (1);
}

void	malloc_error(void)
{
	ft_garbage_collector(END, NULL);
	ft_putstr_fd("Error\nMalloc failed\n", 2);
	exit(1);
}
