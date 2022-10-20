/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:16:24 by vbarbier          #+#    #+#             */
/*   Updated: 2022/10/20 04:21:52 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

typedef struct s_player {
	double	x;
	double	y;
	double	radian;
	int		color;
}				t_player;

typedef struct s_point {
	int	x;
	int	y;
}				t_point;

typedef struct s_map {
	// ligne marhino
	char		**carte;
	int			y_max;
	int			x_max;
}				t_map;

typedef struct s_textures {
    char	*path_NO;
    char	*path_SO;
    char	*path_WE;
    char	*path_EA;
    int		*floor;
    int		*ceiling;
}            t_textures;

typedef struct s_data {
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	//mlx finish
	char		**file;
	t_textures	textures;
	t_map		*map;
	t_player	player;
	// t_assets	assets;
}				t_data;

typedef struct s_trace_line {
	t_point	a;
	t_point	b;
	t_data	*data;
	int		color;
}				t_line;
