/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <zoentifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 15:07:59 by zoentifi          #+#    #+#             */
/*   Updated: 2025/08/24 16:19:41 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
# include "minilibx-linux/mlx.h"


t_Cube  *cube(void)
{
	static t_Cube instance;

	return (&instance);
}



int main(int ac, char **av)
{
	if (validate_args(ac, av))
		return (1);
	read_file(av[1]);
	parse_color(ft_split1(cube()->parse->floor_ceiling->floor_color, ','));
	parse_color(ft_split1(cube()->parse->floor_ceiling->ceiling_color, ','));
	parse_textures();
    if (!change_space(0, 0, cube()->parse->map->height + 2, cube()->parse->map->width + 2))
	{
		gc_collect();
		exit(1);
	}
	map_parsing();
	draw_world();
	gc_collect();
	return (0);
}