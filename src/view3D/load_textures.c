/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:21:52 by mvue              #+#    #+#             */
/*   Updated: 2022/11/04 12:58:49 by mvue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

static void	error_destroy_imgs(t_data *data, int cmp)
{
	if (cmp > 0)
		mlx_destroy_image(data->mlx, data->textures.asset_NO);
	if (cmp > 1)
		mlx_destroy_image(data->mlx, data->textures.asset_SO);
	if (cmp > 2)
		mlx_destroy_image(data->mlx, data->textures.asset_WE);
	if (cmp > 3)
		mlx_destroy_image(data->mlx, data->textures.asset_EA);
}

void    error_img(t_data *img, int cmp)
{
    error_destroy_imgs(img, cmp);
    mlx_destroy_image(img->mlx, img->mlx_win);
	mlx_clear_window(img->mlx, img->mlx_win);
    mlx_destroy_window(img->mlx, img->mlx_win);
    //mlx_destroy_display(img->mlx);
	free(img->mlx);
	ft_garbage_collector(END, NULL);
    exit(1);
}

static void	*load_img(t_data *data, char *path)
{
	void		*asset;
	int			width;
	int			height;
	static int	cmp = 0;

	width = 64;
	height = 64;
	asset = mlx_xpm_file_to_image(data->mlx, path, &width, &height);
	if (asset == NULL)
	{
		ft_putstr_fd("Error\nChargement image xpm", 2);
		error_img(data, cmp);
		exit(EXIT_FAILURE);
	}
	cmp++;
	return (asset);
}

void	load_imgs(t_data *data)
{
	printf("PATH TO NO : %s\n", data->textures.path_NO);
	data->textures.asset_NO = load_img(data, data->textures.path_NO);
	data->textures.asset_SO = load_img(data, data->textures.path_SO);
	data->textures.asset_WE = load_img(data, data->textures.path_WE);
	data->textures.asset_EA = load_img(data, data->textures.path_EA);
}

void	destroy_imgs(t_data *data)
{
	if (data->textures.asset_NO)
		mlx_destroy_image(data->mlx, data->textures.asset_NO);
	if (data->textures.asset_SO)
		mlx_destroy_image(data->mlx, data->textures.asset_SO);
	if (data->textures.asset_WE)
		mlx_destroy_image(data->mlx, data->textures.asset_WE);
	if (data->textures.asset_EA)
		mlx_destroy_image(data->mlx, data->textures.asset_EA);
}