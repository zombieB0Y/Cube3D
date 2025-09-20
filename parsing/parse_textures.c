/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <zoentifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 19:30:00 by zoentifi          #+#    #+#             */
/*   Updated: 2025/09/20 20:59:30 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	parse_textures(void)
{
	check_textures();
}

void	check_textures(void)
{
	if (!check_for_valid_texture())
	{
		ft_putstr_fd("Error: Invalid texture\n", 2);
		gc_collect();
		exit(EXIT_FAILURE);
	}
}

bool	check_for_valid_texture(void)
{
	if (!check_each_texture(0))
		return (false);
	if (!check_each_texture(1))
		return (false);
	if (!check_each_texture(2))
		return (false);
	if (!check_each_texture(3))
		return (false);
	return (true);
}

bool	check_each_texture(int id)
{
	int	fd;

	fd = open(cube()->parse->textures[id].path, O_RDONLY);
	if (fd == -1)
	{
		printf("Texture %d not found: '%s'\n", id,
			cube()->parse->textures[id].path);
		return (false);
	}
	close(fd);
	return (true);
}
