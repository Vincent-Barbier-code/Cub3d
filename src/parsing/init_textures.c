/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:12:44 by mvue              #+#    #+#             */
/*   Updated: 2022/11/12 20:58:12 by mvue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

void	init_textures(t_data *data)
{
	data->textures.ceiling = NULL;
	data->textures.floor = NULL;
	data->textures.path_ea = NULL;
	data->textures.path_no = NULL;
	data->textures.path_so = NULL;
	data->textures.path_we = NULL;
}

static char	*malloc_path(char *path, char *struct_path)
{
	char	*malloced_path;

	if (struct_path)
		textures_errors(ERR_NUM_PATH);
	malloced_path = ft_strdup(path);
	if (!malloced_path)
		malloc_error();
	return (malloced_path);
}

void	get_texture_path(char *path, t_data *data, char *element)
{
	int	fd;
	int	i;

	i = 0;
	while (path[i] != '\n')
		i++;
	i--;
	while (path[i] == ' ')
		i--;
	i++;
	path[i] = '\0';
	fd = open(path, O_RDONLY);
	if (fd == -1)
		textures_errors(ERR_WRONG_FILE);
	fd_close_error(close(fd));
	if (!ft_strncmp(element, "NO", 2))
		data->textures.path_no = malloc_path(path, data->textures.path_no);
	if (!ft_strncmp(element, "SO", 2))
		data->textures.path_so = malloc_path(path, data->textures.path_so);
	if (!ft_strncmp(element, "WE", 2))
		data->textures.path_we = malloc_path(path, data->textures.path_we);
	if (!ft_strncmp(element, "EA", 2))
		data->textures.path_ea = malloc_path(path, data->textures.path_ea);
}

char	*check_default_path(char *path)
{
	char	*malloced_path;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		textures_errors(ERR_WRONG_FILE);
	fd_close_error(close(fd));
	malloced_path = ft_strdup(path);
	if (!malloced_path)
		malloc_error();
	return (malloced_path);
}

void	set_default_textures(t_data *data)
{
	if (!data->textures.path_ea)
		data->textures.path_ea \
			= check_default_path("./textures/EA.xpm");
	if (!data->textures.path_no)
		data->textures.path_no \
			= check_default_path("./textures/NO.xpm");
	if (!data->textures.path_so)
		data->textures.path_so \
			= check_default_path("./textures/SO.xpm");
	if (!data->textures.path_we)
		data->textures.path_we \
			= check_default_path("./textures/WE.xpm");
}
