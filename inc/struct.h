/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:16:24 by vbarbier          #+#    #+#             */
/*   Updated: 2022/11/12 18:39:32 by mvue             ###   ########.fr       */
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

typedef struct s_point_f {
	double	x;
	double	y;
}				t_point_f;

typedef struct s_map {
	char		**carte;
	int			y_max;
	int			x_max;
}				t_map;

typedef struct s_img {
	void	*pointer;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*addr;
}				t_img;

typedef struct s_textures {
    char	*path_NO;
    char	*path_SO;
    char	*path_WE;
    char	*path_EA;
	t_img	asset_NO;
	t_img	asset_SO;
	t_img	asset_WE;
	t_img	asset_EA;
    int		*floor;
    int		*ceiling;
	double	x_wall_hit;
	int		dir_looked;
}            t_textures;

typedef struct s_draw {
	int		size;
	int		x;
	int		y;
	int		cp_x;
	int		cp_y;
	double	pos_x;
	double	pos_y;
}				t_draw;

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
	t_draw		draw;
	int			buffer;
	int			POS_MAP_X; 
	int			POS_MAP_Y;
	int			POS_PX;
	int			POS_PY;
	// t_assets	assets;
}				t_data;

typedef struct s_trace_line {
	t_point	a;
	t_point	b;
	t_data	*data;
	int		color;
}			t_line;

typedef struct s_trigo {
	double		dx;
	double		dy;
	double		ray_angle;
	double		ray_len;
	t_point_f	start_ray;
	t_point_f	end_ray;
	int			stop;
} 			t_trigo;

typedef struct s_rays {
	double	angle_start;
	double	angle_end;
	double	step;
	double	len_ray;
}			t_rays;

typedef struct s_3d {
	double		col_h;
	double		col_offset;
	int			pix_x;
	int			pix_y;
	int			tex_x;
	int			tex_y;
	float		tex_y_step;
	double		tex_pos;
	int			n_pix_col;
	int			ind_col;
}			t_3d;