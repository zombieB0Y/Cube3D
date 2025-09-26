/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: zoentifi <zoentifi@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/06/29 15:03:14 by zoentifi		  #+#	#+#			 */
/*   Updated: 2025/09/25 10:05:36 by ibennaje         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include <stdbool.h>
# include "get_line/get_line.h"

# define WIN "Cube_3D"
# define SCREENWIDTH 1300
# define SCREENHEIGHT 900
# define UPKEY 65362
# define DOWNKEY 65364
# define LEFTKEY 65361
# define RIGHTKEY 65363
# define MOVESPEED 0.1
# define PI_VALUE 3.141592653589793
# define W_KEY 119
# define S_KEY 115
# define A_KEY 97
# define D_KEY 100
# define EAST 360
# define NORTH 90
# define WEST 180
# define SOUTH 270
# define ESC 65307

typedef struct s_gcnode
{
	void				*ptr;
	struct s_gcnode		*next;
}	t_gcnode;

typedef enum e_texture_type
{
	TEXTURE_NORTH,
	TEXTURE_SOUTH,
	TEXTURE_WEST,
	TEXTURE_EAST
}	t_texture_type;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_player
{
	int	x;
	int	y;
	int	size;
}	t_player;

typedef struct s_texture
{
	char			*path;
	int				width;
	int				height;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	void			*img;
	char			*addr;
	t_texture_type	type;
	bool			loaded;
}	t_texture;

typedef struct s_floor_ceiling
{
	char	*floor_color;
	t_color	*floor_rgb;
	bool	floor_color_loaded;
	char	*ceiling_color;
	t_color	*ceiling_rgb;
	bool	ceiling_color_loaded;
}	t_floor_ceiling;

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	bool	is_player_there;
}	t_map;

typedef struct s_parse
{
	char			*line;
	char			*tmp;
	char			**new_map;
	t_texture		*textures;
	t_floor_ceiling	*floor_ceiling;
	t_map			*map;
	int				width;
	int				height;
}	t_parse;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_cube_map
{
	void	*mlx;
	void	*mlx_win;
	t_img	*img;
}	t_cube_map;
typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_queue
{
	t_point	*data;
	int		front;
	int		back;
	int		capacity;
}	t_queue;

typedef struct s_cube
{
	t_gcnode	*g_head;
	t_parse		*parse;
	int			fd;
	float		raydirx;
	float		raydiry;
	float		distance_to_projection_plan;
	float		ray_angle;
	float		deltadistx;
	float		deltadisty;
	float		posx;
	int			side;
	float		posy;
	int			stepx;
	int			stepy;
	int			drawstart;
	int			drawend;
	float		sidedestx;
	float		sidedesty;
	int			mapx;
	int			mapy;
	int			fov;
	int			direction;
	float		walldist;
	float		lineheight;
	int			wallhit;
	t_cube_map	*cube_map;
}	t_cube;

typedef struct s_cs
{
	t_point	*directions;
	t_point	point;
	t_point	curr;
	int		i;
	int		sx;
	int		sy;
	char	c;
	t_queue	q;
	bool	**visited;
}	t_cs;

typedef struct s_draw_norm
{
	int			pixel;
	int			texture_index;
	t_texture	*texture;
	float		wallx;
	int			texx;
	int			texy;
	float		step;
	float		texpos;
	int			color;
}	t_draw_norm;

// Memory management functions
void	gc_register(void *ptr);
void	*gc_malloc(size_t size);
void	gc_collect(void);

// Utility functions
size_t	ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_putstr_fd(char *s, int fd);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);
char	*ft_strdup(const char *s1);
void	*ft_memset(void *s, int c, size_t n);
bool	ft_isspace(char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		gcd(int a, int b);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
char	**ft_split1(char *s, char c);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t count, size_t size);

// Argument validation
int		validate_args(int ac, char **av);
// File reading
bool	check_for_whitespace(char *line);
void	read_file(char *file_name);
void	read_textures_colors(char *file_name);
void	check_textures(void);
bool	check_for_valid_texture(void);
bool	check_each_texture(int id);
bool	check_if_valid(char **split_line);
void	load_textures_or_colors(char **split_line);
void	print_textures_colors(void);
void	read_map(void);
void	print_map(void);
void	load_floor_ceiling_colors(char **split_line);
bool	is_it_loaded(void);
void	init_parse(void);

// File utilities
int		size_2d(char **arr);
void	checking_split_line(char **split_line);
char	**load_symbols(void);
void	error(char *msg);

// Map utilities
void	init_new_map(void);
void	init_line(void);
void	alloc_space(bool valid);
void	add_border(void);
char	*get_tmp(void);
void	check_for_valid_map(void);

// Map validation
bool	itiraite_foward(char **map, int i, int j);
bool	itiraite_backward(char **map, int i, int j);
bool	itiraite_upward(char **map, int i, int j);
bool	itiraite_downward(char **map, int i, int j);
bool	check_surrounding(char **map, int i, int j);

// Queue utilities
int		init_queue(t_queue *q, int capacity);
void	add_in_queue(t_queue *q, t_point point);
t_point	out_of_queue(t_queue *q);
int		is_empty(t_queue *q);

// Parsing functions
void	parse_textures(void);
bool	parse_color(char **tokens, char c);
void	check_color_range(t_color *color, char c);
void	map_parsing(void);
int		change_space(int X, int Y, int height, int width);
long	convert_rgb(char c);
void	check_player(void);
void	init_directions(t_point *directions);
void	check_for_invalid_char(int i, int j);
void	validate_surrounding(int i, int j, bool valid);

t_cube	*cube(void);

void	create_map(void);
void	img_pix_put(t_img *img, int x, int y, long color);
int		draw_world(void);
void	draw_in_image(int x, int start_line, int end_line, int side);

// herrek
int		key_hook(int keycode);
void	mv(int keycode, float *direction_move);

int		is_player(char player, int posx, int posy);
void	give_me_map(void);

float	wall_distance(float ray_angle);
int		is_wall(char **map, int x, int y);

int		destroy_window_helper(int code);
int		destroy_window(void);
void	destroy_texture(void);

void	ft_mlx_new_image(void);
void	ft_mlx_get_data_addr(void);
void	ft_mlx_put_image_to_window(void);
void	ft_mlx_new_window(void);
void	ft_mlx_xpm_file_to_image(int i);

void	init_textures(void);
void	init_texture_addresses(void);
int		get_texture_index(int side, float raydirx, float raydiry);
int		get_texture_pixel(t_texture *texture, int x, int y);
void	init_draw_vars(t_draw_norm *vars, int side, int start_line);
void	get_texture_color(t_draw_norm *vars, int side);
void	floor_or_ceiling(t_draw_norm vars, int x, int start_line, int end_line);
float	wall_distance_formula(float ray_angle);
#endif
