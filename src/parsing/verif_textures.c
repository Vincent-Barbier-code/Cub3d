/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 23:17:14 by mvue              #+#    #+#             */
/*   Updated: 2022/09/26 12:00:02 by mvue             ###   ########.fr       */
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
	if (err_num == ERR_COLOR)
	{
		ft_putstr_fd("Error\nWrong color format", 2);
		ft_putstr_fd("Give the color in RGB separated by comas\n", 2);
		ft_putstr_fd("Ex : 100,10,50\n", 2);
	}
	if (err_num == ERR_COLOR_NUM)
	{
		ft_putstr_fd("Error\nWrong color number, ", 2);
		ft_putstr_fd("colors must be between 0 and 255\n", 2);
	}
	exit (1);
}

void	skip_spaces(int *letter, char *str)
{
	while (str[*letter] == ' ')
		*letter += 1;
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
		data->textures.path_NO = path;
	if (!ft_strncmp(element, "SO", 2))
		data->textures.path_SO = path;
	if (!ft_strncmp(element, "WE", 2))
		data->textures.path_WE = path;
	if (!ft_strncmp(element, "EA", 2))
		data->textures.path_EA = path;
}

void	check_colors(char *RGB)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 3)
	{
		skip_spaces(&j, RGB);
		while (ft_isdigit(RGB[j]))
			j++;
		skip_spaces(&j, RGB);
		if (i == 2)
		{
			if (!(RGB[j] == '\n'))
				textures_errors(ERR_COLOR);
		}
		else
		{
			if (!(RGB[j] == ','))
				textures_errors(ERR_COLOR);
		}
		j++;
		i++;
	}
}

int	*get_colors(char *RGB)
{
	int	i;
	int	j;
	int	digit_len;
	int	*color_nums;

	color_nums = ft_malloc(sizeof(int) * 3);
	i = 0;
	j = 0;
	while (i < 3)
	{
		digit_len = 0;
		skip_spaces(&j, RGB);
		while (ft_isdigit(RGB[j]))
		{
			digit_len++;
			j++;
		}
		if (digit_len > 3)
			textures_errors(ERR_COLOR_NUM);
		RGB[j] = '\0';
		color_nums[i] = ft_atoi(&RGB[j - digit_len]);
		j++;
		skip_spaces(&j, RGB);
		i++;
	}
	return (color_nums);
}

void	get_colors_FC(char *RGB, t_data *data, char *element)
{
	int	*colors;
	int	i;

	check_colors(RGB);
	colors = get_colors(RGB);
	i = 0;
	while (i < 3)
	{
		if (!(colors[i] >= 0 && colors[i] <= 255))
			textures_errors(ERR_COLOR_NUM);
		i++;
	}
	if (!ft_strncmp(element, "F", 2))
		data->textures.floor = colors;
	if (!ft_strncmp(element, "C", 2))
		data->textures.ceiling = colors;
}

int	is_map_line(char *line)
{
	int	letter;

	letter = 0;
	if (line[letter] == '\n')
		return (0);
	while (line[letter] != '\n')
	{
		if (!(line[letter] == ' ' || line[letter] == '1' \
			|| line[letter] == '0' || line[letter] == '\t'))
			return (0);
		letter++;
	}
	return (1);
}
/*
void	trim_map(t_data *data, int start_line)
{
	char	**map;
	int		line;
	int		cnt_line;

	line = start_line;
	cnt_line = 0;
	while (data->file[line])
	{
		cnt_line++;
		line++;
	}
}
*/
void	get_textures(t_data *data)
{
	int		line;
	int		letter;
	char	*element;

	line = 0;
	while (!is_map_line(data->file[line]) && data->file[line])
	{
		letter = 0;
		if (data->file[line][letter] == '\n')
			line++;
		else
		{
			skip_spaces(&letter, data->file[line]);
			element = set_element(&letter, line, data->file);
			if (!element)
				textures_errors(ERR_TEXT_UNRECO);
			letter += ft_strlen(element);
			skip_spaces(&letter, data->file[line]);
			if (ft_strlen(element) == 2)
				get_texture_path(&data->file[line][letter], data, element);
			else
				get_colors_FC(&data->file[line][letter], data, element);
			line++;
		}
	}
	//trim_map(data, line);
}
