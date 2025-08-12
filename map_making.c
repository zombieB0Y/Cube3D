#include "cube.h"

static void initial_values(t_Cube *cube)
{
    cube->posx = 3;
    cube->posy = 4;
    cube->wallhit = 0;
    cube->player_x = (cube->posx + 0.5) * 64;
    cube->player_y = (cube->posy + 0.5) * 64;
    cube->fov = 60;
    cube->direction = 180;
    cube->distance_to_projection_plan = (((screenHeight) / 2)) / (fabs(tan((cube->fov / 2 )* (3.14  / 180))));
}
void create_map(char **map, t_Cube *cube)
{
    int x = -1;
    initial_values(cube);
    char hard_coded_map[mapHeight][mapWidth] =
        {
            {'1', '1', '1', '1', '1', '1', '1', '1'},
            {'1', '0', '0', '0', '0', '0', '0', '1'},
            {'1', '0', '0', '0', '0', '0', '0', '1'},
            {'1', '0', '0', '0', '0', '0', '0', '1'},
            {'1', '0', '0', 'N', '0', '0', '0', '1'},
            {'1', '0', '0', '0', '0', '0', '0', '1'},
            {'1', '0', '0', '0', '0', '0', '0', '1'},
            {'1', '1', '1', '1', '1', '1', '1', '1'}};

    while (++x < screenWidth)
    {
        cube->mapx = (int)(cube->player_x) / 64;
        cube->mapy = (int)(cube->player_x) / 64;
        printf("incube->side d loop\n");
        cube->ray_angle = (cube->direction - (cube->fov / 2)) + (cube->direction * (x / (screenWidth)));
        cube->raydirx = cos(cube->ray_angle * (3.14 / 180));
        cube->raydiry = sin(cube->ray_angle * (3.14 / 180));
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
            printf("passed d cos sin x = %d \n", x);
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

            printf("cube->mapx = %d , cube->mapy = %d \n", cube->mapx, cube->mapy);
            if (hard_coded_map[cube->mapx][cube->mapy] == '1')
            {
                 printf("distance to projection plan %f\n", cube->distance_to_projection_plan);
                printf("wall found\n");
                cube->wallhit = 1;
                if (cube->side)
                {
                    cube->walldist = cube->sidedestx - cube->deltadistx;
                }
                else
                {
                    cube->walldist = cube->sidedesty - cube->deltadisty;
                }
                if (cube->side == 0)
                {
                    printf("cube->side = 0\n");
                    return;
                }
                printf("walldist = %f cube->sidedesty = %f cube->sidedestx = %f \n", cube->walldist, cube->sidedesty, cube->sidedestx);
                cube->lineheight = (64 / cube->walldist) * cube->distance_to_projection_plan;
                //cube->lineheight = (cube->lineheight / cube->walldist) * (cube->distance_to_projection_plan);
                cube->drawstart = (screenHeight / 2) - (cube->lineheight / 2);
                cube->drawend = (screenHeight / 2) + (cube->lineheight / 2);
                draw_in_image(&(cube->cube_map), x, cube->drawstart, cube->drawend, cube->side);
                printf("finish draw_in_image()\n");
                cube->wallhit = 1;
            }
        }
    }
    printf("FINISHED\n");
    //   printf("distance to projection plan %f\n", distance_to_projection_plan);
}