/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_making.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibennaje <ibennaje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 10:06:54 by ibennaje          #+#    #+#             */
/*   Updated: 2025/09/25 21:49:37 by ibennaje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

static void	check_next(void)
{
	if (cube()->sidedestx < cube()->sidedesty)
	{
		cube()->side = 1;
		cube()->mapx += cube()->stepx;
		cube()->sidedestx += cube()->deltadistx;
	}
	else
	{
		cube()->side = 0;
		cube()->mapy += cube()->stepy;
		cube()->sidedesty += cube()->deltadisty;
	}
}

static void	initial_side_distance(void)
{
	float	dx;
	float	dy;

	dx = cube()->deltadistx;
	dy = cube()->deltadisty;
	if (cube()->raydirx > 0)
	{
		cube()->stepx = 1;
		cube()->sidedestx = (cube()->mapx + 1 - cube()->posx) * dx;
	}
	else
	{
		cube()->stepx = -1;
		cube()->sidedestx = (cube()->posx - cube()->mapx) * dx;
	}
	if (cube()->raydiry > 0)
	{
		cube()->stepy = 1;
		cube()->sidedesty = (cube()->mapy + 1 - cube()->posy) * dy;
	}
	else
	{
		cube()->sidedesty = (cube()->posy - cube()->mapy) * dy;
		cube()->stepy = -1;
	}
}

static void	initial_wall_distance(float ray_angle)
{
	cube()->mapx = (int)(cube()->posx);
	cube()->mapy = (int)(cube()->posy);
	cube()->raydirx = cos(ray_angle * (PI_VALUE / 180));
	cube()->raydiry = sin(ray_angle * (PI_VALUE / 180));
	cube()->deltadistx = 1 / fabsf(cube()->raydirx);
	cube()->deltadisty = 1 / fabsf(cube()->raydiry);
	initial_side_distance();
	cube()->wallhit = 0;
}

float	wall_distance(float ray_angle)
{
	char	**map;

	map = cube()->parse->map->map;
	initial_wall_distance(ray_angle);
	while (cube()->wallhit == 0)
	{
		check_next();
		if (map[cube()->mapy][cube()->mapx] == '1')
		{
			cube()->wallhit = 1;
			if (cube()->side)
				cube()->walldist = cube()->sidedestx - cube()->deltadistx;
			else
				cube()->walldist = cube()->sidedesty - cube()->deltadisty;
			return (cube()->walldist);
		}
	}
	return (-1);
}

void	create_map(void)
{
	int		x;
	float	ray_angle;

	cube()->fov = 60;
	cube()->distance_to_projection_plan = (((SCREENHEIGHT) / 2))
	/ (fabs(tan((cube()->fov / 2) * (PI_VALUE / 180))));
	x = -1;
	ray_angle = -1;
	while (++x < SCREENWIDTH)
	{
		ray_angle = cube()->direction - (cube()->fov / 2) + ((x
					/ (double)SCREENWIDTH) * cube()->fov);
		cube()->walldist = wall_distance(ray_angle);
		cube()->lineheight = SCREENWIDTH / wall_distance_formula(ray_angle);
		cube()->drawstart = (SCREENHEIGHT / 2) - (cube()->lineheight / 2);
		cube()->drawend = (SCREENHEIGHT / 2) + (cube()->lineheight / 2);
		if (cube()->drawstart < 0)
			cube()->drawstart = 0;
		if (cube()->drawend >= SCREENHEIGHT)
			cube()->drawend = SCREENHEIGHT - 1;
		draw_in_image(x, cube()->drawstart, cube()->drawend,
			cube()->side);
	}
}
