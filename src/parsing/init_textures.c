/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:12:44 by mvue              #+#    #+#             */
/*   Updated: 2022/11/12 00:27:01 by mvue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

void	init_textures(t_data *data)
{
	data->textures.ceiling = NULL;
	data->textures.floor = NULL;
	data->textures.path_EA = NULL;
	data->textures.path_NO = NULL;
	data->textures.path_SO = NULL;
	data->textures.path_WE = NULL;
}

static char	*malloc_path(char *path, char *struct_path)
{
	char	*malloced_path;

	if (struct_path)
		textures_errors(ERR_NUM_PATH);
	malloced_path = ft_strdup(path);
	if (!malloced_path)
	{
		ft_garbage_collector(END, NULL);
		exit (1);
	}
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
	close(fd);
	if (!ft_strncmp(element, "NO", 2))
		data->textures.path_NO = malloc_path(path, data->textures.path_NO);
	if (!ft_strncmp(element, "SO", 2))
		data->textures.path_SO = malloc_path(path, data->textures.path_SO);
	if (!ft_strncmp(element, "WE", 2))
		data->textures.path_WE = malloc_path(path, data->textures.path_WE);
	if (!ft_strncmp(element, "EA", 2))
		data->textures.path_EA = malloc_path(path, data->textures.path_EA);
}

char	*check_default_path(char *path)
{
	char	*malloced_path;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		textures_errors(ERR_WRONG_FILE);
	close(fd);
	malloced_path = ft_strdup(path);
	if (!malloced_path)
	{
		ft_garbage_collector(END, NULL);
		exit(1);
	}
	return (malloced_path);
}

void	set_default_textures(t_data *data)
{
	if (!data->textures.path_EA)
		data->textures.path_EA \
			= check_default_path("./textures/EA.xpm");
	if (!data->textures.path_NO)
		data->textures.path_NO \
			= check_default_path("./textures/NO.xpm");
	if (!data->textures.path_SO)
		data->textures.path_SO \
			= check_default_path("./textures/SO.xpm");
	if (!data->textures.path_WE)
		data->textures.path_WE \
			= check_default_path("./textures/WE.xpm");
}
