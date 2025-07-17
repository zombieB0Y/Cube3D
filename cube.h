/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <zoentifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 15:03:14 by zoentifi          #+#    #+#             */
/*   Updated: 2025/07/17 17:15:56 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include <stdbool.h>
# include "mlx.h"
# include "get_line/get_line.h"

typedef struct t_GCNode
{
	void				*ptr;
	struct t_GCNode		*next;
}						t_GCNode;

typedef enum e_texture_type
{
	TEXTURE_NORTH,
	TEXTURE_SOUTH,
	TEXTURE_WEST,
	TEXTURE_EAST
}	t_texture_type;

typedef struct s_texture
{
	char			*path;
	int				width;
	int				height;
	t_texture_type	type;
	bool			loaded;
}			t_texture;

typedef struct s_floor_ceiling
{
	char		*floor_color;
	char		*ceiling_color;
}			t_floor_ceiling;

typedef struct s_parse
{
	t_texture			*textures;
	t_floor_ceiling		*floor_ceiling;
	char				**map;
	int					width;
	int					height;
}						t_parse;

// our global cube instance
typedef struct s_Cube
{
	t_GCNode	*g_head;
	t_parse		*parse;
	void		*mlx;
}				t_Cube;

t_Cube  *cube(void);

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

// Argument validation
int		validate_args(int ac, char **av);

// File reading
bool	check_for_whitespace(char *line);
void	read_file(char *file_name);
void	load_textures(char *file_name);
void	check_textures(void);
bool	check_for_valid_texture(void);
bool	check_each_texture(int id);
// void	load_map(char *file_name, char **map);

# endif