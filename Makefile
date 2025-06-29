NAME = cube3D

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

MLX_FLAGS = -lmlx -lXext -lX11

SRCS = cube.c gc.c

OBJS = $(SRCS:.c=.o)

libft = libft

libs = libft/libft.a

all: make_libs $(NAME)


make_libs:
	$(MAKE) -C $(libft)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) $(libs) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(libft) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(libft) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re