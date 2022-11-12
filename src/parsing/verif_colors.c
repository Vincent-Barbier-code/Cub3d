/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:06:11 by mvue              #+#    #+#             */
/*   Updated: 2022/11/12 00:56:42 by mvue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

static void	check_colors(char *RGB)
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
				color_errors(ERR_COLOR);
		}
		else
		{
			if (!(RGB[j] == ','))
				color_errors(ERR_COLOR);
		}
		j++;
		i++;
	}
}

static int	*get_colors(char *RGB)
{
	int	i;
	int	j;
	int	digit_len;
	int	*color_nums;

	color_nums = ft_malloc(sizeof(int) * 3);
	if (!color_nums)
		malloc_error();
	i = -1;
	j = 0;
	while (++i < 3)
	{
		digit_len = 0;
		skip_spaces(&j, RGB);
		while (ft_isdigit(RGB[j++]))
			digit_len++;
		j--;
		if (digit_len > 3)
			color_errors(ERR_COLOR_NUM);
		RGB[j] = '\0';
		color_nums[i] = ft_atoi(&RGB[j - digit_len]);
		j++;
		skip_spaces(&j, RGB);
	}
	return (color_nums);
}

void	get_colors_fc(char *RGB, t_data *data, char *element)
{
	int	*colors;
	int	i;

	check_colors(RGB);
	colors = get_colors(RGB);
	i = -1;
	while (++i < 3)
	{
		if (!(colors[i] >= 0 && colors[i] <= 255))
			color_errors(ERR_COLOR_NUM);
	}
	if (!ft_strncmp(element, "F", 2))
	{
		if (data->textures.floor)
			color_errors(ERR_NUM_COLOR);
		data->textures.floor = colors;
	}
	else if (!ft_strncmp(element, "C", 2))
	{
		if (data->textures.ceiling)
			color_errors(ERR_NUM_COLOR);
		data->textures.ceiling = colors;
	}
	else
		ft_free(colors);
}
