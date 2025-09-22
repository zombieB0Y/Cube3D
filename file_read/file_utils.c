/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zm <zm@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 00:00:00 by zm                #+#    #+#             */
/*   Updated: 2025/09/22 23:24:46 by zm               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	size_2d(char **arr)
{
	int	i;

	if (!arr)
		return (0);
	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	checking_split_line(char **split_line)
{
	if (!split_line || !split_line[1])
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

char	**load_symbols(void)
{
	char	**symbols;

	symbols = gc_malloc(sizeof(char *) * 5);
	if (!symbols)
	{
		gc_collect();
		exit(EXIT_FAILURE);
	}
	symbols[0] = "NO";
	symbols[1] = "SO";
	symbols[2] = "WE";
	symbols[3] = "EA";
	symbols[4] = NULL;
	return (symbols);
}
