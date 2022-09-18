/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 18:07:30 by vbarbier          #+#    #+#             */
/*   Updated: 2022/09/18 17:26:22 by vbarbier         ###   ########.fr       */
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

# define MOT 0
# define CMD 1

typedef struct s_map {
	// ligne marhino
	char		**carte;
	int			y_max;
	int			x_max;
} 				t_map;

typedef struct s_data {
	// void		*mlx;
	// void		*mlx_win;
	char		**file;
	t_map		*map;
	// t_assets	assets;
	// char		*addr;
	// int			bits_per_pixel;
	// int			line_length;
}				t_data;


// name_parse.c
void	name_file(int ac, char *av);
// recup_map.c
void	init_file(t_data *data, char *nom);
void	name_error(int cas);
//clean_map.c
void	clean_map(t_data *data);
//verif_wall.c
void	verif_wall(t_data *data);
//verif_sides
int	verif_up(t_map *map, int y, int x, int (*f)(char));
int	verif_down(t_map *map, int y, int x, int (*f)(char));
int	verif_right(t_map *map, int y, int x, int (*f)(char));
int	verif_left(t_map *map, int y, int x, int (*f)(char));

int	ft_isspc(char c);


#endif