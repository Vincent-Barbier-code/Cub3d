/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:16:24 by vbarbier          #+#    #+#             */
/*   Updated: 2022/10/13 15:19:17 by mvue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

typedef struct s_player {
	double	x;
	double	y;
	double	front;
	int color;
}				t_player;

typedef struct s_point {
	int	x;
	int	y;
}				t_point;

typedef struct s_map {
	char		**carte;
	int			y_max;
	int			x_max;
}				t_map;

typedef struct s_textures {
    char    *path_NO;
    char    *path_SO;
    char    *path_WE;
    char    *path_EA;
    int        *floor;
    int        *ceiling;
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
}			t_line;

typedef struct s_trigo {
	double	dx;
	double	dy;
	double	ray_angle;
	double	ray_len;
	t_point	start_ray;
	t_point	end_ray;
} 			t_trigo;
