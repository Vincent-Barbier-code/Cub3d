/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 18:07:30 by vbarbier          #+#    #+#             */
/*   Updated: 2022/11/08 19:15:39 by mvue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stddef.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
//# include <mlx.h>
# include "./struct.h"

//PARSING
# define ERR_TEXT_UNRECO 15
# define ERR_WRONG_FILE 16
# define ERR_COLOR 17
# define ERR_COLOR_NUM 18
# define ERR_NUM_PATH 19
# define ERR_NUM_COLOR 20
// SCREEN
# define WIDTH 800
# define HEIGHT 500
// MINIMAP
// NOT USE FOR VINCENT # define SIZE_PIXEL 20
# define SIZE_PIXMAP 32
# define SIZE_PLAYER 6
# define COLOR_RAY 0xA30B37
# define GAP_MAP 40
# define POS_MAP_X (WIDTH - (WIDTH / 4) - GAP_MAP)
# define POS_MAP_Y (HEIGHT - (HEIGHT / 2.5) - GAP_MAP)
# define POS_PX (WIDTH - ((WIDTH / 4) / 2) - GAP_MAP)
# define POS_PY (HEIGHT - ((HEIGHT / 2.5) / 2) - GAP_MAP)
	// PLAYER_FORM 0 = CARRE 1 = TRIANGLE
# define PLAYER_FORM 0
# define NUM_RAYS 200
# define SIZE_PIXEL 64
# define COLOR_PLAYER 0xA30B37
# define BLACK 0x000000
# define VIDE 0xBBB6DF
# define MUR 0x4E8098
# define FOND 0x040404
//TEXTURES
# define NO 1
# define SO 2
# define WE 3
# define EA 4
// KEYS
# define LEFT 97
# define TOP 119
# define RIGHT 100
# define BOT 115
# define CAM_LEFT 65361
# define CAM_RIGHT 65363
# define ESC 65307
//KEYS MAC
// # define LEFT 0
// # define TOP 13
// # define RIGHT 2
// # define BOT 1
// # define ESC 53
// # define CAM_LEFT 123
// # define CAM_RIGHT 124
//PARSING
// name_parse.c
void	name_file(int ac, char *av);

// recup_map.c
void	init_file(t_data *data, char *nom);
void	name_error(int cas);
void	affiche_file(t_data *data);

//clean_map.c
void	clean_map(t_data *data);

//verif_wall.c
int		ft_isspc(char c);
int 	is_near_empty(char c);
void	verif_wall(t_data *data);

//verif_sides
int		verif_up(t_map *map, int y, int x, int (*f)(char));
int		verif_down(t_map *map, int y, int x, int (*f)(char));
int		verif_right(t_map *map, int y, int x, int (*f)(char));
int		verif_left(t_map *map, int y, int x, int (*f)(char));

//verif_textures
void	init_textures(t_data *data);
void	get_textures(t_data *data);
void	textures_errors(int err_num);
void	skip_spaces(int *letter, char *str);

//init_textures.c
void	init_textures(t_data *data);
char	*set_element(int *letter, int line, char **file);
void	get_texture_path(char *path, t_data *data, char *element);
void	set_default_textures(t_data *data);

//init_colors.c
void	set_default_colors(t_data *data);

//verif_colors.c
void	get_colors_FC(char *RGB, t_data *data, char *element);

//verif_char.c
double	is_player(char c);
void	verif_char(t_data *data);

//2D
//windows.c
void	new_window(t_data *img);
int		win_close(t_data *img);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		key_press(int key, t_data *data);
int		key_release(int key, t_data *data);

//affiche2D.c
void	affiche_2d(t_data *data);
void	refresh_2d(t_data *data);
void	map_2d(t_data *data);
int		can_move(t_data *data, int pos, char c);

//draw.c
int		can_draw(int x, int y);
void	init_map(t_data *data);
void	draw_map_2d(t_data *data, int x, int y, int color);
int		formule(t_data *data, t_draw draw, char c);

//player2D.c
void	draw_player_c(t_data *data);
void	draw_player_t(t_data *data);
double	get_player_pos(t_map *map, char c);
void	init_player(t_data *data);
void	move_player(t_data *data, int key);
void    move_cam(t_data *data, int key);
//trace_line.c
void	trace_line(t_line l);

//line_exceptions.c
int	line_exceptions(t_line l, int dx, int dy);

//trace_t_dial.c
void	first_dial(t_line l, int dx, int dy);
void	second_dial(t_line l, int dx, int dy);

//triangle.c
void	trace_triangle(t_point a, t_point b, t_point c, t_data *data);
void	trace_tilted(t_data *data);

//ray_caster.c
void	trace_rays(t_data *data);

//3D
//draw_walls.c
void	trace_pix_column(t_data *data, double len_ray, int n_pix_col, int ind_col);
//load_textures.c
void	load_imgs(t_data *data);
void	destroy_imgs(t_data *data);
//draw_textures.c
t_img	get_correct_texture(t_data *data);
#endif