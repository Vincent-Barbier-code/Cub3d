/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 18:07:30 by vbarbier          #+#    #+#             */
/*   Updated: 2022/09/17 23:10:11 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stddef.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"

typedef struct s_data {
	// void		*mlx;
	// void		*mlx_win;
	char		**map;
	int			nb_line_map;
	// t_assets	assets;
	// char		*addr;
	// int			bits_per_pixel;
	// int			line_length;
}				t_data;


// name_parse.c
void	name_file(int ac, char *av);
// recup_map.c
void	init_map(t_data *data, char *nom);
// void	clean_map(t_data *data);

# define MOT 0
# define CMD 1

#endif