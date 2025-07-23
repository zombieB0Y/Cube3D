/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <zoentifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 15:07:59 by zoentifi          #+#    #+#             */
/*   Updated: 2025/07/23 11:02:54 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
# include "minilibx-linux/mlx.h"


t_Cube  *cube(void)
{
	static t_Cube instance;

	return (&instance);
}

int	key_hook(int keycode)
{
    // printf(">>>%d\n", keycode);
    if (keycode == 65307)
    {
        // mlx_destroy_window(cube()->mlx->mlx, cube()->mlx->win);
		gc_collect();
		ft_putstr_fd("Exiting...\n", 1);
        exit(0);
    }
    // if (keycode == 119 || keycode == 65362)
    //     move_player(0, -10);
    // else if (keycode == 115 || keycode == 65364)
    //     move_player(0, 10);
    // else if (keycode == 97 || keycode == 65361)
    //     move_player(-10, 0);
    // else if (keycode == 100 || keycode == 65363)
    //     move_player(10, 0);
    return (0);
}

int main(int ac, char **av)
{
	if (validate_args(ac, av))
		return (1);
	cube()->mlx = gc_malloc(sizeof(t_mlx));
	if (!cube()->mlx)
	{
		ft_putstr_fd("Error: Failed to allocate memory for MLX\n", 2);
		return (1);
	}
	cube()->mlx->win_width = 960;
	cube()->mlx->win_height = 640;
	read_file(av[1]);
	cube()->mlx->mlx = mlx_init();
	cube()->mlx->win = mlx_new_window(cube()->mlx->mlx,
	cube()->mlx->win_width, cube()->mlx->win_height, "Cube3D");
	if (!cube()->mlx->mlx || !cube()->mlx->win)
	{
		ft_putstr_fd("Error: Failed to initialize MLX\n", 2);
		return (1);
	}
	gc_register(cube()->mlx->mlx);
	gc_register(cube()->mlx->win);
	parse_textures();
	// draw_map();
	init_player();
	draw_player_at_position();
	mlx_hook(cube()->mlx->win, 2, 1L<<0, &key_hook, NULL);
	// mlx_hook(cube()->mlx->win, 17, 0, &close_window, NULL);
	mlx_loop(cube()->mlx->mlx);
	return (0);
}