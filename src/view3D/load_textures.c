/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:21:52 by mvue              #+#    #+#             */
/*   Updated: 2022/11/12 21:04:45 by mvue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

static void	error_destroy_imgs(t_data *data, int cmp)
{
	if (cmp > 0)
		mlx_destroy_image(data->mlx, data->textures.asset_no.pointer);
	if (cmp > 1)
		mlx_destroy_image(data->mlx, data->textures.asset_so.pointer);
	if (cmp > 2)
		mlx_destroy_image(data->mlx, data->textures.asset_we.pointer);
	if (cmp > 3)
		mlx_destroy_image(data->mlx, data->textures.asset_ea.pointer);
}

void	error_img(t_data *data, int cmp)
{
	error_destroy_imgs(data, cmp);
	mlx_destroy_image(data->mlx, data->img);
	mlx_clear_window(data->mlx, data->mlx_win);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	ft_garbage_collector(END, NULL);
	exit(1);
}

static t_img	load_img(t_data *data, char *path)
{
	t_img		texture;
	int			width;
	int			height;
	static int	cmp = 0;

	width = 0;
	height = 0;
	texture.pointer = mlx_xpm_file_to_image(data->mlx, path, &width, &height);
	if (texture.pointer == NULL)
	{
		ft_putstr_fd("Error\nChargement image xpm\n", 2);
		error_img(data, cmp);
	}
	if (!(width == 64) || !(height == 64))
	{
		ft_putstr_fd("Error\nTexture must be in 64x64 format\n", 2);
		mlx_destroy_image(data->mlx, texture.pointer);
		error_img(data, cmp);
	}
	cmp++;
	texture.addr = mlx_get_data_addr(texture.pointer, \
		&(texture.bits_per_pixel), &(texture.line_length), &(texture.endian));
	return (texture);
}

void	load_imgs(t_data *data)
{
	data->textures.asset_no = load_img(data, data->textures.path_no);
	data->textures.asset_so = load_img(data, data->textures.path_so);
	data->textures.asset_we = load_img(data, data->textures.path_we);
	data->textures.asset_ea = load_img(data, data->textures.path_ea);
}

void	destroy_imgs(t_data *data)
{
	if (data->textures.asset_no.pointer)
		mlx_destroy_image(data->mlx, data->textures.asset_no.pointer);
	if (data->textures.asset_so.pointer)
		mlx_destroy_image(data->mlx, data->textures.asset_so.pointer);
	if (data->textures.asset_we.pointer)
		mlx_destroy_image(data->mlx, data->textures.asset_we.pointer);
	if (data->textures.asset_ea.pointer)
		mlx_destroy_image(data->mlx, data->textures.asset_ea.pointer);
}
