/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <zoentifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 15:07:59 by zoentifi          #+#    #+#             */
/*   Updated: 2025/06/29 16:45:16 by zoentifi         ###   ########.fr       */
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
    if (ac != 2)
    {
        write(2, "Error: invalid number of arguments\n", 44);
        return (1);
    }
    if (strlen(av[1]) < 4 || strcmp(av[1] + strlen(av[1]) - 4, ".cub") != 0)
    {
        write(2, "Error: invalid file extension\n", 31);
        return (1);
    }
    return (0);
}