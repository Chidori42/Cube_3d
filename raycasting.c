#include "cub.h"

void    dda_algo(t_data *data, float x1, float y1, float x2, float y2, int color)
{
    float dx = x2 - x1;
    float dy = y2 - y1;
    int step;
    if (fabs(dx) > fabs(dy))
        step = fabs(dx);
    else
        step = fabs(dy);
    float x_inc = dx / (float)step * 0.25;
    float y_inc = dy / (float)step * 0.25;
    int i = 0;
    float x = x1;
    float y = y1;
    while (i <= step)
    {
        mlx_pixel_put(data->mlx, data->win, (int)x, (int)y, color);
        x += x_inc;
        y += y_inc;
        i++;
    }
}

void    draw_direction_line(t_data *data, int color)
{
    float line_length = 10.0;
    float start_x = data->x0;
    float start_y = data->y0;
    float end_x = start_x + cos(data->pa) * line_length;
    float end_y = start_y + sin(data->pa) * line_length;
    dda_algo(data, start_x * 50, start_y * 50, end_x * 50, end_y * 50, color);
}