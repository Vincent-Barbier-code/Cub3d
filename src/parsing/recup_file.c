/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 18:25:22 by vbarbier          #+#    #+#             */
/*   Updated: 2022/11/12 22:33:41 by mvue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

void	fd_close_error(int fd)
{
	if (fd == -1)
	{
		perror("");
		ft_garbage_collector(END, NULL);
		exit(1);
	}
}

int	ligne_verif(char *nom)
{
	int		ligne;
	int		fd;
	char	*str;

	ligne = 0;
	fd = open(nom, O_RDONLY);
	fd_close_error(fd);
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			return (ligne);
		ligne++;
		ft_free(str);
	}
	fd_close_error(close(fd));
}

void	init_file(t_data *data, char *nom)
{
	int		fd;
	char	*str;
	int		i;
	int		ligne;

	ligne = ligne_verif(nom);
	data->map = ft_malloc(sizeof(t_map));
	i = 0;
	fd = open(nom, O_RDONLY);
	fd_close_error(fd);
	data->file = ft_malloc(sizeof(data->file) * (ligne + 1));
	if (!data->file)
		malloc_error();
	str = get_next_line(fd);
	while (str)
	{
		data->file[i] = ft_strdup(str);
		if (!data->file[i++])
			malloc_error();
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	data->file[i] = NULL;
	fd_close_error(close(fd));
}
