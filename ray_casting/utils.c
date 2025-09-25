/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibennaje <ibennaje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 10:07:21 by ibennaje          #+#    #+#             */
/*   Updated: 2025/09/25 21:51:47 by ibennaje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	img_pix_put(t_img *img, int x, int y, long color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*((int *)pixel) = color;
}

int	is_player(char player, int posx, int posy)
{
	if (player == 'E')
		cube()->direction = EAST;
	else if (player == 'W')
		cube()->direction = WEST;
	else if (player == 'S')
		cube()->direction = SOUTH;
	else
		cube()->direction = NORTH;
	cube()->posx = (float)(posx + 0.5);
	cube()->posy = (float)(posy + 0.5);
	return (1);
}

void	give_me_map(void)
{
	int		j;
	int		i;
	char	**map;

	i = 0;
	j = 0;
	map = cube()->parse->map->map;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((map[i][j] != '0') && (map[i][j] != '1') && (map[i][j] != ' ')
				&& (map[i][j] != 's'))
				is_player(map[i][j], j, i);
			j++;
		}
		i++;
	}
}

int	is_wall(char **map, int x, int y)
{
	return (map[y][x] == '1');
}

float	wall_distance_formula(float ray_angle)
{
	float	wall_dist;

	wall_dist = ((float)fabs(cube()->walldist * cos((ray_angle
						- cube()->direction) * (PI_VALUE / 180))));
	return (wall_dist);
}
