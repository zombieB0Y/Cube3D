#include "cube.h"

char hard_coded_map[mapHeight][mapWidth] =
    {
        {'1', '1', '1', '1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0', '0', '0', '1'},
        {'1', '0', '0', '0', '0', '1', '0', '1'},
        {'1', '1', '0', '0', '1', '0', '0', '1'},
        {'1', '0', '0', '0', '0', '0', '0', '1'},
        {'1', '1', '0', '0', '0', '1', '0', '1'},
        {'1', '0', '1', '0', '1', '0', '0', '1'},
        {'1', '1', '1', '1', '1', '1', '1', '1'}};

int is_wall(int x , int y)
{

    return (hard_coded_map[y][x] == '1');
}

void initial_values(t_Cube *cube)
{
    cube->posx = 4;
    cube->posy = 5;
    cube->wallhit = 0;
    cube->fov = 60;
    cube->direction = 180;
    cube->distance_to_projection_plan = (((screenHeight) / 2)) / (fabs(tan((cube->fov / 2) * (PI_VALUE / 180))));
}
float wall_distance(t_Cube *cube, float ray_angle)
{
    cube->player_x = (cube->posx);
    cube->player_y = (cube->posy);
    cube->mapx = (int)(cube->player_x);
    cube->mapy = (int)(cube->player_y);
    cube->raydirx = cos(ray_angle * (PI_VALUE / 180));
    cube->raydiry = sin(ray_angle * (PI_VALUE / 180));
    cube->deltadistx = 1 / fabsf(cube->raydirx);
    cube->deltadisty = 1 / fabsf(cube->raydiry);
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
                cube->walldist = cube->sidedestx - cube->deltadistx;
            else
                cube->walldist = cube->sidedesty - cube->deltadisty;
           // return ((float)fabs(cube->walldist * cos((ray_angle - cube->direction) * (PI_VALUE / 180))));
           return (cube->walldist);
        }
    }
    return (-1);
}
void create_map(char **map, t_Cube *cube)
{
    int x = -1;
    float ray_angle;

    while (++x < screenWidth)
    {
        ray_angle = cube->direction - (cube->fov / 2) + ((x / (double)screenWidth) * cube->fov);
        cube->walldist = wall_distance(cube, ray_angle);
        cube->walldist = ((float)fabs(cube->walldist * cos((ray_angle - cube->direction) * (PI_VALUE / 180))));
        cube->lineheight = screenWidth / cube->walldist;
        cube->drawstart = (screenHeight / 2) - (cube->lineheight / 2);
        cube->drawend = (screenHeight / 2) + (cube->lineheight / 2);
        draw_in_image(&(cube->cube_map), x, cube->drawstart, cube->drawend, cube->side);
    }
}