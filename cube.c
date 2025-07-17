/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <zoentifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 15:07:59 by zoentifi          #+#    #+#             */
/*   Updated: 2025/07/17 17:11:35 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_Cube  *cube(void)
{
	static t_Cube instance;

	return (&instance);
}

int main(int ac, char **av)
{
	if (validate_args(ac, av))
		return (1);
	cube()->mlx = mlx_init();
	if (!cube()->mlx)
	{
		ft_putstr_fd("Error: Failed to initialize MLX\n", 2);
		return (1);
	}
	read_file(av[1]);
	return (0);
}