NAME = cube3D

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

MLX_FLAGS = -lmlx -lXext -lX11

SRCS = cube.c gc.c $(UTILES) $(ARGS_VALIDAT) $(FILE_READ)

UTILES = utiles_functions/ft_strlen.c utiles_functions/ft_strcmp.c utiles_functions/ft_putstr_fd.c

ARGS_VALIDAT = argument_validation/__arg__.c

FILE_READ = file_read/read_file.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re