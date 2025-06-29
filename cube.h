/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <zoentifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 15:03:14 by zoentifi          #+#    #+#             */
/*   Updated: 2025/06/29 17:29:06 by zoentifi         ###   ########.fr       */
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
# include "mlx.h"

typedef struct t_GCNode
{
	void				*ptr;
	struct t_GCNode		*next;
}						t_GCNode;


typedef struct s_texture
{
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
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

// Argument validation
int		validate_args(int ac, char **av);

// File reading
void	read_file(char *file_name);

# endif