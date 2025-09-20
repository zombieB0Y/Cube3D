/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <zoentifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 21:00:22 by zoentifi          #+#    #+#             */
/*   Updated: 2025/09/20 21:00:58 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	destroy_window(void)
{
	destroy_texture();
	mlx_destroy_image(cube()->cube_map->mlx, cube()->cube_map->img->mlx_img);
	mlx_destroy_window(cube()->cube_map->mlx, cube()->cube_map->mlx_win);
	mlx_destroy_display(cube()->cube_map->mlx);
	free(cube()->cube_map->mlx);
	gc_collect();
	exit(0);
}

void	destroy_texture()
{
	int i;

	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(cube()->cube_map->mlx, cube()->parse->textures[i].img);
		i++;
	}
}

int	destroy_window_helper(int code)
{
	code++;
	return (destroy_window());
}
