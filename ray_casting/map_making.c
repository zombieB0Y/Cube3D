#include "../cube.h"


void give_me_map(t_Cube *cube)
{
    int j;
    int i;
    char **map;

    i = 0;
    j = 0;
    map = cube->parse->map->map;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if ((map[i][j] != '0') && (map[i][j] != '1') && (map[i][j] != ' ') && (map[i][j] != 's'))
                is_player(map[i][j], j, i, cube);
            j++;
        }
        i++;
    }
    cube->map = map;
}

int is_wall(char **map, int x, int y)
{
    return (map[y][x] == '1');
}

static void initial_wall_distance(t_Cube *cube, float ray_angle)
{
    cube->mapx = (int)(cube->posx);
    cube->mapy = (int)(cube->posy);
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
}

float wall_distance(t_Cube *cube, float ray_angle)
{
    char **map;

    map = cube->map;
    initial_wall_distance(cube, ray_angle);
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
        if (map[cube->mapy][cube->mapx] == '1')
        {
            cube->wallhit = 1;
            if (cube->side)
                cube->walldist = cube->sidedestx - cube->deltadistx;
            else
                cube->walldist = cube->sidedesty - cube->deltadisty;
            return (cube->walldist);
        }
    }
    return (-1);
}
void create_map(t_Cube *cube)
{
    cube->fov = 60;
    cube->distance_to_projection_plan = (((screenHeight) / 2)) / (fabs(tan((cube->fov / 2) * (PI_VALUE / 180))));
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