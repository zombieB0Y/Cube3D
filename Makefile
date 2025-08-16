NAME = cube3D

CC = cc

CFLAGS = #-Wall -Wextra -Werror -g

MLX_FLAGS =  -lXext -lX11 -lm

SRCS = cube.c gc.c map_making.c draw_world.c utils.c hooks.c move_to.c

OBJS = $(SRCS:.c=.o)

libft = libft

libs = libft/libft.a

mlx     = minilibx-linux
mlx_lib = $(mlx)/libmlx.a

all: make_libs $(NAME)


make_libs:
	$(MAKE) -C $(libft)
	$(MAKE) -C $(mlx)


$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) $(libs) $(mlx_lib) -o $(NAME)

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