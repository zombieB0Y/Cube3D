/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <zoentifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 15:03:14 by zoentifi          #+#    #+#             */
/*   Updated: 2025/06/29 16:12:16 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
#define CUBE_H
#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <math.h>
#include "libft/libft.h"

// Node to track allocated pointers
#define mapWidth 8
#define mapHeight 8
#define screenWidth 1300
#define screenHeight 900

typedef struct t_GCNode
{
	void *ptr;
	struct t_GCNode *next;
} t_GCNode;

typedef struct s_Cube
{
	t_GCNode *g_head; // Head of the garbage collector linked list
} t_cube;

typedef struct s_img
{
	void *mlx_img;
	char *addr;
	int bpp;
	int line_len;
	int endian;
} t_img;

typedef struct s_cube_map
{
	void *mlx;
	void *mlx_win;
	t_img img;

} t_cube_map;

// our global cube instance
t_Cube *cube(void);

// Memory management functions
void gc_register(void *ptr);
void *gc_malloc(size_t size);
void gc_collect(void);
void create_map(char **map);
void img_pix_put(t_img *img, int x, int y, int color);
int destroy_window(t_vars *vars);
int destroy_window_helper(int code, t_vars *vars)

#endif