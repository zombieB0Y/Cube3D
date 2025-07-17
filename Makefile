NAME = cube3D

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

MLX_FLAGS = -I/usr/include -Imlx_linux -O3 -lX11 -lXext -lm -lz

SRCS = cube.c gc.c $(UTILES) $(ARGS_VALIDAT) $(FILE_READ)

UTILES = utiles_functions/ft_strlen.c utiles_functions/ft_strcmp.c utiles_functions/ft_putstr_fd.c \
		utiles_functions/ft_realloc.c utiles_functions/ft_memcpy.c utiles_functions/ft_strdup.c utiles_functions/ft_memset.c \
		utiles_functions/ft_isspace.c utiles_functions/ft_strncmp.c
ARGS_VALIDAT = argument_validation/__arg__.c

FILE_READ = file_read/read_file.c file_read/read_file_utils.c

GET_LINE = get_line/get_line.c get_line/get_line_utils.c

OBJS = $(SRCS:.c=.o) $(GET_LINE:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(MLX_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re