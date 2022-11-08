/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:12:44 by mvue              #+#    #+#             */
/*   Updated: 2022/11/08 18:50:06 by mvue             ###   ########.fr       */
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

char	*set_element(int *letter, int line, char **file)
{
	int		i;

	i = 0;
	while (file[line][*letter + i] != ' ')
		i++;
	if (i == 1)
	{
		if (!ft_strncmp(&file[line][*letter], "F", 1))
			return ("F");
		if (!ft_strncmp(&file[line][*letter], "C", 1))
			return ("C");
	}
	if (i == 2)
	{
		if (!ft_strncmp(&file[line][*letter], "NO", 2))
			return ("NO");
		if (!ft_strncmp(&file[line][*letter], "SO", 2))
			return ("SO");	
		if (!ft_strncmp(&file[line][*letter], "WE", 2))
			return ("WE");
		if (!ft_strncmp(&file[line][*letter], "EA", 2))
			return ("EA");
	}
	return (NULL);
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
	{
		if (data->textures.path_NO)
			textures_errors(ERR_NUM_PATH);
		data->textures.path_NO = ft_strdup(path);
	}
	if (!ft_strncmp(element, "SO", 2))
	{
		if (data->textures.path_SO)
			textures_errors(ERR_NUM_PATH);
		data->textures.path_SO = ft_strdup(path);
	}
	if (!ft_strncmp(element, "WE", 2))
	{
		if (data->textures.path_WE)
			textures_errors(ERR_NUM_PATH);
		data->textures.path_WE = ft_strdup(path);
	}
	if (!ft_strncmp(element, "EA", 2))
	{
		if (data->textures.path_EA)
			textures_errors(ERR_NUM_PATH);
		data->textures.path_EA = ft_strdup(path);
	}
}

void	set_default_textures(t_data *data)
{
	char	*path;
	int		fd;
	
	if (!data->textures.path_EA)
	{
		path = "./textures/EA.xpm";
		fd = open(path, O_RDONLY);
		if (fd == -1)
			textures_errors(ERR_WRONG_FILE);
		close(fd);
		data->textures.path_EA = path;
	}
	if (!data->textures.path_NO)
	{
		path = "./textures/NO.xpm";
		fd = open(path, O_RDONLY);
		if (fd == -1)
			textures_errors(ERR_WRONG_FILE);
		close(fd);
		data->textures.path_NO = path;
	}
	if (!data->textures.path_SO)
	{
		path = "./textures/SO.xpm";
		fd = open(path, O_RDONLY);
		if (fd == -1)
			textures_errors(ERR_WRONG_FILE);
		close(fd);
		data->textures.path_SO = path;
	}
	if (!data->textures.path_WE)
	{
		path = "./textures/WE.xpm";
		fd = open(path, O_RDONLY);
		if (fd == -1)
			textures_errors(ERR_WRONG_FILE);
		close(fd);
		data->textures.path_WE = path;
	}
}