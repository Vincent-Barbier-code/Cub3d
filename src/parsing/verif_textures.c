/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 23:17:14 by mvue              #+#    #+#             */
/*   Updated: 2022/11/08 12:13:44 by mvue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

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
		ft_putstr_fd("Error\nWrong color format\n", 2);
		ft_putstr_fd("Give the color in RGB separated by comas\n", 2);
		ft_putstr_fd("Ex : 100,10,50\n", 2);
	}
	if (err_num == ERR_COLOR_NUM)
	{
		ft_putstr_fd("Error\nWrong color number, ", 2);
		ft_putstr_fd("colors must be between 0 and 255\n", 2);
	}
	if (err_num == ERR_NUM_PATH)
		ft_putstr_fd("Error\nMultiple paths given\n", 2);
	if (err_num == ERR_NUM_COLOR)
		ft_putstr_fd("Error\nMultiple colors given\n", 2);
	ft_garbage_collector(END, NULL);
	exit (1);
}

void	skip_spaces(int *letter, char *str)
{
	while (str[*letter] == ' ')
		*letter += 1;
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

void    trim_map(t_data *data, int start_map)
{
    int        line;
    
    line = 0;
    while (line < start_map)
    {
        ft_free(data->file[line]);
        line++;
    }
    data->file = &data->file[start_map];
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
	trim_map(data, line);
}
