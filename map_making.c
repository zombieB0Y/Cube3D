#include "cube.h"


void create_map(char **map)
{

    char hard_coded_map[mapHeight][mapWidth] =
        {
            {'1', '1', '1', '1', '1', '1', '1', '1'},
            {'1', '0', '0', '0', '0', '0', '0', '1'},
            {'1', '0', '0', '0', '0', '0', '0', '1'},
            {'1', '0', '0', '0', '0', '0', '0', '1'},
            {'1', '0', 'N', '0', '0', '0', '0', '1'},
            {'1', '0', '1', '1', '1', '1', '0', '1'},
            {'1', '0', '0', '0', '0', '0', '0', '1'},
            {'1', '1', '1', '1', '1', '1', '1', '1'}};

    float player_x;
    float player_y;
    float raydirx;
    float raydiry;
    float distance_to_projection_plan;
    float ray_angle;
    float deltadistx;
    float deltadisty;

    player_x = (2 + 0.5) * 64;
    player_y = (4 + 0.5) * 64;
    int mapx;
    int mapy;
    int fov;
    int direction;
    fov = 60;
    direction = 180;

    mapx = player_x / 64;
    mapy = player_x / 64;
    float walldist;
    float lineheight;
    int wallhit = 0;
    while (x < screenWidth)
    {
        ray_angle = (direction - (fov / 2)) + (direction * (x / (screenWidth - 1)));
        raydirx = cos(ray_angle);
        raydiry = sin(ray_angle);
        deltadistx = 1 / raydirx;
        deltadistx = 1 / raydiry;
        distance_to_projection_plan = ((screenWidth / 2)) / tan((fov / 2));
        int x;
        int y;
        int stepx;
        int stepy;
        x = 0;
        y = 0;
        int drawstart;
        int drawend;
        float sidedestx;
        float sidedesty;
        if (raydirx > 0)
        {
            stepx = 1;
            sidedestx = (mapx + 1 - player_x) * deltadistx;
        }
        else
        {
            stepx = -1;
            sidedestx = (mapx - player_x) * deltadistx;
        }
        if (raydiry > 0)
        {
            stepy = 1;
            sidedesty = (mapy + 1 - player_y) * deltadisty;
        }
        else
        {
            sidedesty = (mapy - player_y) * deltadisty;
            stepy = -1;
        }
        wallhit = 0;
        while (wallhit == 0)
        {
            if (sidedestx < sidedesty)
            {
                mapx += stepx;
                sidedestx += deltadistx;
            }
            else
            {
                mapy += stepy;
                sidedesty += deltadisty;
            }
            if (hard_coded_map[mapx][mapy] == '1')
            {
                wallhit = 1;
                if (sidedestx < sidedesty)
                    walldist = sidedestx - deltadistx;
                else
                    walldist = sidedesty - deltadisty;
                lineheight = (distance_to_projection_plan * 64) / walldist;
                drawstart = (screenHeight / 2) - (lineheight / 2);
                drawend = (screenHeight / 2) + (lineheight / 2);
            }
        }
    }
}