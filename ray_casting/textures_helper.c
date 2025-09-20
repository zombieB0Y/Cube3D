/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <zoentifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 20:08:38 by zoentifi          #+#    #+#             */
/*   Updated: 2025/09/20 20:39:45 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	init_draw_vars(t_draw_norm *vars, int side, int start_line)
{
	vars->pixel = 0;
	vars->texture_index = get_texture_index(side, cube()->raydirx,
			cube()->raydiry);
	vars->texture = &cube()->parse->textures[vars->texture_index];
	if (side == 1)
		vars->wallx = cube()->posy + cube()->walldist * cube()->raydiry;
	else
		vars->wallx = cube()->posx + cube()->walldist * cube()->raydirx;
	vars->wallx -= floor(vars->wallx);
	vars->texx = (vars->wallx * (double)vars->texture->width);
	vars->step = vars->texture->height / cube()->lineheight;
	vars->texpos = (start_line - screenHeight / 2 + cube()->lineheight / 2)
		* vars->step;
}

void	init_texture_addresses(void)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (cube()->parse->textures[i].img)
		{
			cube()->parse->textures[i].addr = mlx_get_data_addr
			(cube()->parse->textures[i].img,
			&cube()->parse->textures[i].bits_per_pixel,
			&cube()->parse->textures[i].line_length,
			&cube()->parse->textures[i].endian);
		}
		else
			cube()->parse->textures[i].addr = NULL;
		i++;
	}
}

void	init_textures(void)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		cube()->parse->textures[i].img = mlx_xpm_file_to_image
			(cube()->cube_map->mlx,
			cube()->parse->textures[i].path,
			&cube()->parse->textures[i].width,
			&cube()->parse->textures[i].height);
		if (!cube()->parse->textures[i].img)
		{
			printf("Failed to load texture %d\n", i);
			cube()->parse->textures[i].width = 64;
			cube()->parse->textures[i].height = 64;
			cube()->parse->textures[i].img = NULL;
		}
		i++;
	}
}

long	convert_rgb(char c)
{
	long	color;
	int		r;
	int		g;
	int		b;

	if (c == 'c')
	{
		r = cube()->parse->floor_ceiling->ceiling_rgb->r;
		g = cube()->parse->floor_ceiling->ceiling_rgb->g;
		b = cube()->parse->floor_ceiling->ceiling_rgb->b;
	}
	else
	{
		r = cube()->parse->floor_ceiling->floor_rgb->r;
		g = cube()->parse->floor_ceiling->floor_rgb->g;
		b = cube()->parse->floor_ceiling->floor_rgb->b;
	}
	color = (r * 65536) + (g * 256) + b;
	return (color);
}
