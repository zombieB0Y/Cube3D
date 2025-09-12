#include "../cube.h"

static void move_foward()
{
    cube()->posx += (cos((cube()->direction * (PI_VALUE / 180))) * MOVESPEED);
    cube()->posy += (sin((cube()->direction * (PI_VALUE / 180))) * MOVESPEED);
}
static void move_behind(float *direction_move)
{
    cube()->posx -= cos((cube()->direction * (PI_VALUE / 180))) * MOVESPEED;
    cube()->posy -= sin((cube()->direction * (PI_VALUE / 180))) * MOVESPEED;
    *(direction_move) = *(direction_move) + 180;
}
static void move_left(float *direction_move)
{
    cube()->posx -= cos((cube()->direction * (PI_VALUE / 180)) + (PI_VALUE / 2)) * MOVESPEED;
    cube()->posy -= sin((cube()->direction * (PI_VALUE / 180)) + (PI_VALUE / 2)) * MOVESPEED;
    *(direction_move) = *(direction_move)-90;
}
static void move_right(float *direction_move)
{
    cube()->posx += cos((cube()->direction * (PI_VALUE / 180)) + (PI_VALUE / 2)) * MOVESPEED;
    cube()->posy += sin((cube()->direction * (PI_VALUE / 180)) + (PI_VALUE / 2)) * MOVESPEED;
    *(direction_move) = *(direction_move) + 90;
}
void mv(int keycode, float *direction_move)
{
    if (keycode == W_KEY)
        move_foward();
    else if (keycode == S_KEY)
        move_behind(direction_move);
    else if (keycode == A_KEY)
        move_left(direction_move);
    else if (keycode == D_KEY)
        move_right(direction_move);
}
