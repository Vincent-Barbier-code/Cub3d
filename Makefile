NAME = cub3D
CFLAGS =  -Wall -Wextra -Werror -g #-fsanitize=thread
DEPS = $(INCLUDES)cub.h Makefile
INCLUDES = inc/
SRC_DIR = src/
OBJ_DIR = obj/
LIBFT =  -L ./libft -lft

SRC_FILES = $(addprefix $(SRC_DIR), \
	main.c \
	parsing/name_parse.c \
	parsing/recup_file.c \
	parsing/verif_wall.c \
	parsing/clean_map.c \
	parsing/verif_sides.c)

OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC_FILES))

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(DEPS)
	@if [ ! -d "$(OBJ_DIR)" ]; then mkdir $(OBJ_DIR); fi
	@if [ ! -d "$(dir $@)" ]; then mkdir $(dir $@); fi
	gcc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(DEPS)
	$(MAKE) -C libft/
	gcc $(CFLAGS) $(OBJ) $(LIBFT) $(GNL) -lreadline -o $(NAME)

all : $(NAME)

clean :
	$(MAKE) clean -C libft/
	rm -rf $(OBJ_DIR)

fclean : clean
	$(MAKE) fclean -C libft/
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
