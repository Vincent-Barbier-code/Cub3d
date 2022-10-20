/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 18:07:30 by vbarbier          #+#    #+#             */
/*   Updated: 2022/10/13 23:56:42 by mvue             ###   ########.fr       */
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
# include "../get_next_line/get_next_line.h"
//# include "../minilibx-linux/mlx.h"
# include <mlx.h>
# include "./struct.h"

//PARSING
# define ERR_TEXT_UNRECO 15
# define ERR_WRONG_FILE 16
# define ERR_COLOR 17
# define ERR_COLOR_NUM 18
// SCREEN
# define WIDTH 3000
# define HEIGHT 1400
# define SIZE_PIXEL 64
# define SIZE_PLAYER 10
# define COLOR_PLAYER 0xA30B37
# define VIDE 0xBBB6DF
# define MUR 0x4E8098
# define FOND 0x040404
# define COLOR_RAY 0xff8c00
// KEYS LINUX
// # define LEFT 65361
// # define TOP 65362
// # define RIGHT 65363
// # define BOT 65364
// # define ESC 65307
// KEYS MAC
# define LEFT 0
# define TOP 13
# define RIGHT 2
# define BOT 1
# define ESC 53
# define CAM_LEFT 123
# define CAM_RIGHT 124
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


//verif_char.c
int		is_player(char c);
void	verif_char(t_data *data);

//2D
//windows.c
void	new_window(t_data *img);
int		win_close(t_data *img);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		key_press(int key, t_data *data);
int		key_release(int key, t_data *data);

//affiche2D.c
void	affiche_2D(t_data *data);
void	refresh_2D(t_data *data);
void	map_2D(t_data *data);

//player2D.c
void	draw_player(t_data *data);
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
void	launch_rays(t_data *data);
void	vertical_check(t_data	*data);
#endif