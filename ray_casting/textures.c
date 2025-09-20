/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <zoentifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 19:30:25 by zoentifi          #+#    #+#             */
/*   Updated: 2025/09/20 20:11:46 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	get_texture_pixel(t_texture *texture, int x, int y)
{
	char	*pixel;

	pixel = texture->addr + (y * texture->line_length + x
			* (texture->bits_per_pixel / 8));
	return (*((int *)pixel));
}

int	get_texture_index(int side, float raydirx, float raydiry)
{
	if (side == 1)
	{
		if (raydirx > 0)
			return (TEXTURE_EAST);
		else
			return (TEXTURE_WEST);
	}
	else
	{
		if (raydiry > 0)
			return (TEXTURE_SOUTH);
		else
			return (TEXTURE_NORTH);
	}
}

void	floor_or_ceiling(t_draw_norm vars, int x, int start_line, int end_line)
{
	if (vars.pixel < start_line)
		img_pix_put(cube()->cube_map->img, x, vars.pixel, convert_rgb('c'));
	else if (vars.pixel > end_line)
		img_pix_put(cube()->cube_map->img, x, vars.pixel, convert_rgb('f'));
}

void	get_texture_color(t_draw_norm *vars, int side)
{
	if (vars->texture->addr)
	{
		vars->texy = abs((int)vars->texpos) % vars->texture->height;
		vars->texpos += vars->step;
		vars->color = get_texture_pixel(vars->texture, vars->texx, vars->texy);
	}
	else
	{
		if (side)
			vars->color = 0xFF94F3;
		else
			vars->color = 0xC742B6;
	}
}

void	draw_in_image(int x, int start_line, int end_line, int side)
{
	t_draw_norm	vars;

	init_draw_vars(&vars, side, start_line);
	while (vars.pixel < screenHeight - 1)
	{
		if (vars.pixel >= start_line && vars.pixel <= end_line)
		{
			get_texture_color(&vars, side);
			img_pix_put(cube()->cube_map->img, x, vars.pixel, vars.color);
		}
		else
			floor_or_ceiling(vars, x, start_line, end_line);
		vars.pixel++;
	}
}
