#include "cube.h"

void initial_values(t_Cube *cube)
{
    cube->posx = 4;
    cube->posy = 5;
    cube->wallhit = 0;
    cube->fov = 60;
    cube->direction = 180;
    cube->distance_to_projection_plan = (((screenHeight) / 2)) / (fabs(tan((cube->fov / 2) * (PI_VALUE / 180))));
}
void create_map(char **map, t_Cube *cube)
{
    int x = -1;

    char hard_coded_map[mapHeight][mapWidth] =
        {
            {'1', '1', '1', '1', '1', '1', '1', '1'},
            {'1', '0', '0', '0', '0', '0', '0', '1'},
            {'1', '0', '0', '0', '0', '1', '0', '1'},
            {'1', '1', '0', '0', '0', '0', '0', '1'},
            {'1', '0', '0', '0', '0', '0', '0', '1'},
            {'1', '1', '0', '0', '0', '0', '0', '1'},
            {'1', '0', '1', '0', '1', '0', '0', '1'},
            {'1', '1', '1', '1', '1', '1', '1', '1'}};

    while (++x < screenWidth)
    {
        cube->player_x = (cube->posx );
        cube->player_y = (cube->posy);
        cube->mapx = (int)(cube->player_x);
        cube->mapy = (int)(cube->player_y);
        cube->ray_angle = cube->direction - (cube->fov / 2) + ((x / (double)screenWidth) * cube->fov);
        cube->raydirx = cos(cube->ray_angle * (PI_VALUE / 180));
        cube->raydiry = sin(cube->ray_angle * (PI_VALUE / 180));
        cube->deltadistx = 1 / fabsf(cube->raydirx);
        cube->deltadisty = 1 / fabsf(cube->raydiry);
        // distance_to_projection_plan = ((screenWidth / 2)) / fabs(tan((cube->fov / 2)));
        if (cube->raydirx > 0)
        {
            cube->stepx = 1;
            cube->sidedestx = (cube->mapx + 1 - cube->posx) * cube->deltadistx;
        }
        else
        {
            cube->stepx = -1;
            cube->sidedestx = (cube->posx - cube->mapx) * cube->deltadistx;
        }
        if (cube->raydiry > 0)
        {
            cube->stepy = 1;
            cube->sidedesty = (cube->mapy + 1 - cube->posy) * cube->deltadisty;
        }
        else
        {
            cube->sidedesty = (cube->posy - cube->mapy) * cube->deltadisty;
            cube->stepy = -1;
        }
        cube->wallhit = 0;
        while (cube->wallhit == 0)
        {
            if (cube->sidedestx < cube->sidedesty)
            {
                cube->side = 1;
                cube->mapx += cube->stepx;
                cube->sidedestx += cube->deltadistx;
            }
            else
            {
                cube->side = 0;
                cube->mapy += cube->stepy;
                cube->sidedesty += cube->deltadisty;
            }

            if (hard_coded_map[cube->mapy][cube->mapx] == '1')
            {
                cube->wallhit = 1;
                if (cube->side)
                {
                    cube->walldist = cube->sidedestx - cube->deltadistx;
                }
                else
                {
                    cube->walldist = cube->sidedesty - cube->deltadisty;
                }
                cube->walldist = fabs(cube->walldist * cos((cube->ray_angle - cube->direction) * (PI_VALUE / 180)));
                cube->lineheight = screenWidth / cube->walldist;
                cube->drawstart = (screenHeight / 2) - (cube->lineheight / 2);
                cube->drawend = (screenHeight / 2) + (cube->lineheight / 2);
                printf("cube->deltadistx = %f , cube->deltadisty = %f , cube->sidedestx = %f , cube->sidedesty = %f , cube->walldist = %f , cube->ray_angle =  %f  \n", cube->deltadistx, cube->deltadisty, cube->sidedestx, cube->sidedesty, cube->walldist, cube->ray_angle);
                draw_in_image(&(cube->cube_map), x, cube->drawstart, cube->drawend, cube->side);
                cube->wallhit = 1;
            }
        }
    }
}