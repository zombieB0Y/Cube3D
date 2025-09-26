/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zm <zm@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 20:08:38 by zoentifi          #+#    #+#             */
/*   Updated: 2025/09/26 18:08:52 by zm               ###   ########.fr       */
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
	vars->texpos = (start_line - SCREENHEIGHT / 2 + cube()->lineheight / 2)
		* vars->step;
}

static void	init_texture_addresses_helper(int i)
{
	char	*texture_addr;
	void	*img;
	int		*bpp;
	int		*line_length;
	int		*endian;

	img = cube()->parse->textures[i].img;
	bpp = &cube()->parse->textures[i].bits_per_pixel;
	line_length = &cube()->parse->textures[i].line_length;
	endian = &cube()->parse->textures[i].endian;
	texture_addr = mlx_get_data_addr(img, bpp, line_length, endian);
	cube()->parse->textures[i].addr = texture_addr;
}

void	init_texture_addresses(void)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (cube()->parse->textures[i].img)
			init_texture_addresses_helper(i);
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
		ft_mlx_xpm_file_to_image(i);
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
