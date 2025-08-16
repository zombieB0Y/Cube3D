#include "cube.h"

static void move_foward(t_Cube *cube)
{
    cube->posx += (float)(cos((cube->direction * (float)(PI_VALUE / 180))) * MOVESPEED);
    cube->posy += (float)(sin((cube->direction * (float)(PI_VALUE / 180))) * MOVESPEED);
}
static void move_behind(t_Cube *cube, float *direction_move)
{
    cube->posx -= cos((cube->direction * (PI_VALUE / 180))) * MOVESPEED;
    cube->posy -= sin((cube->direction * (PI_VALUE / 180))) * MOVESPEED;
    *(direction_move) = *(direction_move) + 180;
}
static void move_left(t_Cube *cube, float *direction_move)
{
    cube->posx -= cos((cube->direction * (PI_VALUE / 180)) + (PI_VALUE / 2)) * MOVESPEED;
    cube->posy -= sin((cube->direction * (PI_VALUE / 180)) + (PI_VALUE / 2)) * MOVESPEED;
    *(direction_move) = *(direction_move)-90;
}
static void move_right(t_Cube *cube, float *direction_move)
{
    cube->posx += cos((cube->direction * (PI_VALUE / 180)) + (PI_VALUE / 2)) * MOVESPEED;
    cube->posy += sin((cube->direction * (PI_VALUE / 180)) + (PI_VALUE / 2)) * MOVESPEED;
    *(direction_move) = *(direction_move) + 90;
}
void mv(t_Cube *cube, int keycode, float *direction_move)
{
    if (keycode == W_KEY)
        move_foward(cube);
    else if (keycode == S_KEY)
        move_behind(cube, direction_move);
    else if (keycode == A_KEY)
        move_left(cube, direction_move);
    else if (keycode == D_KEY)
        move_right(cube, direction_move);
}