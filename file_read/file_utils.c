/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zm <zm@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 00:00:00 by zm                #+#    #+#             */
/*   Updated: 2025/09/20 05:25:50 by zm               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	size_2d(char **arr)
{
	int i;

	if (!arr)
		return (0);
	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	checking_split_line(char **split_line)
{
	if (!split_line)
	{
		gc_collect();
		exit(EXIT_FAILURE);
	}
	if (split_line[0][0] == 'F' || split_line[0][0] == 'C')
		load_floor_ceiling_colors(split_line);
	else if (size_2d(split_line) != 2)
	{
		ft_putstr_fd("Error: invalid texture line\n", 2);
		gc_collect();
		exit(EXIT_FAILURE);
	}
	else if (!check_if_valid(split_line))
	{
		ft_putstr_fd("Error: Invalid texture line\n", 2);
		gc_collect();
		exit(EXIT_FAILURE);
	}
	load_textures_or_colors(split_line);
}
