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
#define UPKEY 65363
#define DOWNKEY 65363
#define LEFTKEY 65363
#define RIGHTKEY 65363
#define MOVESPEED 0.1

typedef struct t_GCNode
{
	void *ptr;
	struct t_GCNode *next;
} t_GCNode;


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
typedef struct s_Cube
{
	t_GCNode *g_head; // Head of the garbage collector linked list
	float player_x;
	float player_y;
	float raydirx;
	float raydiry;
	float distance_to_projection_plan;
	float ray_angle;
	float deltadistx;
	float deltadisty;
	float posx;
	int side;
	float posy;
	int stepx;
	int stepy;
	int drawstart;
	int drawend;
	float sidedestx;
	float sidedesty;
	int mapx;
	int mapy;
	int fov;
	int direction;
	float walldist;
	float lineheight;
	int wallhit;
	t_cube_map cube_map;

} t_Cube;

// our global cube instance
t_Cube *cube(void);

// Memory management functions
void gc_register(void *ptr);
void *gc_malloc(size_t size);
void gc_collect(void);

// rssem la bari trssem
void create_map(char **map, t_Cube *cube);
void img_pix_put(t_img *img, int x, int y, int color);
int draw_world();
void draw_in_image(t_cube_map *cube, int x, int start_line, int end_line, int side);
#endif