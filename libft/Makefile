NAME=libft.a
CC=gcc
CFLAGS=-Wall -Wextra -Werror
RM=rm -f
LDFLAGS=-L.
LDLIBS=-lft

SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c \
ft_strlcat.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c \
ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c ft_garbage_collector.c ft_malloc.c \
ft_free.c ft_strjoin_2free.c ft_strjoin_1free.c ft_strcmp.c ft_strdup_perm.c \
ft_strjoin_1free_perm.c ft_garbage_collector_perm.c ft_free_perm.c ft_malloc_perm.c \
ft_str_deldeb.c \
../get_next_line/get_next_line_utils.c ../get_next_line/get_next_line.c 

OBJ = $(SRC:.c=.o)

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
ft_lstdelone.c ft_lstclear.c ft_lstiter.c

BONUS_OBJS = $(BONUS:.c=.o)

$(NAME): $(OBJ)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

%.o: %.c
		$(CC) -I. $(CFLAGS) -o $@ -c $? 

all: $(NAME)

bonus: $(OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

clean:
		$(RM) $(OBJ) $(BONUS_OBJS)

fclean: clean
		$(RM) $(NAME) 

re: fclean all

.PHONY: all clean fclean re bonus
