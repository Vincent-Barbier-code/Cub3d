NAME = cub3D
CFLAGS =  -Wall -Wextra # -Werror -g #-fsanitize=thread
DEPS = $(INCLUDES)cub.h Makefile
INCLUDES = inc/
SRC_DIR = src/
OBJ_DIR = obj/
LIBFT =  -L ./libft -lft
MLX =  -L minilibx-linux -lft ./minilibx-linux/libmlx.a -Imlx_linux -lXext -lX11 -lz -lm -g3

SRC_FILES = $(addprefix $(SRC_DIR), \
	main.c \
	parsing/name_parse.c \
	parsing/recup_file.c \
	parsing/verif_wall.c \
	parsing/clean_map.c \
	parsing/verif_sides.c \
	parsing/verif_char.c \
	parsing/verif_textures.c \
	parsing/verif_colors.c \
	parsing/init_colors.c \
	parsing/init_textures.c \
	parsing/texture_errors.c \
	view2D/windows.c \
	view2D/affiche_2D.c \
	view2D/draw.c \
	view2D/player_2D.c \
	view2D/move_player.c \
	view2D/player_carre.c \
	view2D/trace_line.c \
	view2D/line_exceptions.c \
	view2D/trace_t_dial.c \
	view2D/triangle.c \
	view2D/ray_caster.c \
	view2D/do_key.c \
	view2D/grid_checks.c \
	view2D/utils_rc.c \
	view3D/draw_walls.c \
	view3D/load_textures.c \
	view3D/draw_textures.c)

OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC_FILES))

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(DEPS)
	@if [ ! -d "$(OBJ_DIR)" ]; then mkdir $(OBJ_DIR); fi
	@if [ ! -d "$(dir $@)" ]; then mkdir $(dir $@); fi
	gcc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(DEPS)
	$(MAKE) -C libft/
	$(MAKE) -C minilibx-linux/
	gcc $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) -o $(NAME) -lm

all : $(NAME)

clean :
	$(MAKE) clean -C libft/
	$(MAKE) clean -C minilibx-linux/
	rm -rf $(OBJ_DIR)

fclean : clean
	$(MAKE) fclean -C libft/
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re