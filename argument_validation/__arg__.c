/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __arg__.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zm <zm@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 17:08:29 by zoentifi          #+#    #+#             */
/*   Updated: 2025/09/22 23:27:46 by zm               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	validate_args(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putstr_fd("Error: invalid number of arguments\n", 2);
		return (1);
	}
	if (ft_strlen(av[1]) < 4
		|| ft_strcmp(av[1] + ft_strlen(av[1]) - 4, ".cub") != 0)
	{
		ft_putstr_fd("Error: invalid file extension\n", 2);
		return (1);
	}
	return (0);
}

void	error(char *msg)
{
	ft_putstr_fd(msg, 2);
	gc_collect();
	exit(EXIT_FAILURE);
}
