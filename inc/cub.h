/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 18:07:30 by vbarbier          #+#    #+#             */
/*   Updated: 2022/09/18 15:26:20 by vbarbier         ###   ########.fr       */
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
void	clean_map(t_data *data);
void	name_error(int cas);
void	verif_wall(t_data *data);

int	ft_isspc(char c);


#endif