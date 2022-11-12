/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 23:17:14 by mvue              #+#    #+#             */
/*   Updated: 2022/11/12 00:49:52 by mvue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

void	skip_spaces(int *letter, char *str)
{
	while (str[*letter] == ' ')
		*letter += 1;
}

static int	is_map_line(char *line)
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

static void	trim_map(t_data *data, int start_map)
{
	int	line;

	line = 0;
	while (line < start_map)
	{
		ft_free(data->file[line]);
		line++;
	}
	data->file = &data->file[start_map];
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

void	get_textures(t_data *data)
{
	int		line;
	int		letter;
	char	*element;

	line = 0;
	while (!is_map_line(data->file[line]) && data->file[line])
	{
		letter = 0;
		if (!(data->file[line][letter] == '\n'))
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
				get_colors_fc(&data->file[line][letter], data, element);
		}
		line++;
	}
	trim_map(data, line);
}
