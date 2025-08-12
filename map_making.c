#include "cube.h"

void create_map(char **map, t_cube_map *cube)
{
    int x = -1;

    char hard_coded_map[mapHeight][mapWidth] =
        {
            {'1', '1', '1', '1', '1', '1', '1', '1'},
            {'1', '0', '0', '0', '0', '0', '0', '1'},
            {'1', '1', '0', '0', '0', '0', '0', '1'},
            {'1', '0', '0', '0', '0', '1', '0', '1'},
            {'1', '1', '0', 'N', '0', '0', '0', '1'},
            {'1', '0', '0', '0', '1', '1', '0', '1'},
            {'1', '1', '0', '0', '0', '0', '0', '1'},
            {'1', '1', '1', '1', '1', '1', '1', '1'}};

    float player_x;
    float player_y;
    float raydirx;
    float raydiry;
    float distance_to_projection_plan;
    float ray_angle;
    float deltadistx;
    float deltadisty;
    float posx;
    int side;
    float posy;
    int stepx;
    int stepy;
    int drawstart;
    int drawend;
    float sidedestx;
    float sidedesty;
    int mapx;
    int mapy;
    int fov;
    int direction;
    float walldist;
    float lineheight;
    posx = 3;
    posy = 4;
    int wallhit = 0;
    player_x = (posx + 0.5) * 64;
    player_y = (posy + 0.5) * 64;
    fov = 60;
    direction = 30;

    while (++x < screenWidth)
    {
        mapx = (int)(player_x) / 64;
        mapy = (int)(player_x) / 64;
        printf("inside d loop\n");
        ray_angle = (direction - (fov / 2)) + (direction * (x / (screenWidth)));
        raydirx = cos(ray_angle);
        raydiry = sin(ray_angle);
        deltadistx = 1 / fabsf(raydirx);
        deltadisty = 1 / fabsf(raydiry);
        distance_to_projection_plan = ((screenWidth / 2)) / fabs(tan((fov / 2)));
        if (raydirx > 0)
        {
            stepx = 1;
            sidedestx = (mapx + 1 - posx) * deltadistx;
        }
        else
        {
            stepx = -1;
            sidedestx = (posx - mapx) * deltadistx;
        }
        if (raydiry > 0)
        {
            stepy = 1;
            sidedesty = (mapy + 1 - posy) * deltadisty;
        }
        else
        {
            sidedesty = (posy - mapy) * deltadisty;
            stepy = -1;
        }
        wallhit = 0;
        while (wallhit == 0)
        {
            printf("passed d cos sin x = %d \n", x);
            if (sidedestx < sidedesty)
            {
                side = 1;
                mapx += stepx;
                sidedestx += deltadistx;
            }
            else
            {
                side = 0;
                mapy += stepy;
                sidedesty += deltadisty;
            }

            printf("mapx = %d , mapy = %d \n", mapx, mapy);
            if (hard_coded_map[mapx][mapy] == '1')
            {
                printf("distance to projection plan %f\n", distance_to_projection_plan);
                printf("wall found\n");
                wallhit = 1;
                if (side)
                {
                    walldist = sidedestx - deltadistx;
                }
                else
                {
                    walldist = sidedesty - deltadisty;
                }
                if (side == 0)
                {
                    printf("side = 0\n");
                    return;
                }
                printf("walldist = %f sidedesty = %f sidedestx = %f \n", walldist, sidedesty, sidedestx);
                lineheight = screenHeight / walldist;
                drawstart = (screenHeight / 2) - (lineheight / 2);
                drawend = (screenHeight / 2) + (lineheight / 2);
                draw_in_image(cube, x, drawstart, drawend, side);
                printf("finish draw_in_image()\n");
                wallhit = 1;
            }
        }
    }
    printf("FINISHED\n");
    printf("distance to projection plan %f\n", distance_to_projection_plan);
}