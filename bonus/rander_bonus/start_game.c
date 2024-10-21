/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:58:00 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/10/21 22:01:21 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

void ft_clear_image(mlx_image_t *img)
{
    uint32_t        i;
    uint32_t        j;
    unsigned int    clear;
    
    i = 0;
    clear = 255 << 24 | 255 << 16 | 255 << 8 | 0;
    while (i < img->height)
    {
        j = 0;
        while (j < img->width)
        {
            mlx_put_pixel(img, j, i, clear);
            j++;
        }
        i++;
    }
}

bool is_wall(t_data *dt, double x, double y)
{
    int map_x = (int)(x / TILE_SIZE);
    int map_y = (int)(y / TILE_SIZE);
    
    if (map_x >= 0 && map_x < dt->map_w&& map_y >= 0 && map_y < dt->map_h) 
        return (dt->map[map_y][map_x] == '1' || dt->map[map_y][map_x] == 'D');
    return (false);
}

int circle_collision(t_data *dt, double x, double y)
{
    if (is_wall(dt, x - PLYR_SPEED, y - PLYR_SPEED) ||
        is_wall(dt, x + PLYR_SPEED, y - PLYR_SPEED) ||
        is_wall(dt, x - PLYR_SPEED, y + PLYR_SPEED) ||
        is_wall(dt, x + PLYR_SPEED, y + PLYR_SPEED)) {
        return (1);
    }
    return (0);
}

void move_player(t_data *dt, double move_x, double move_y)
{
    double potential_x = roundf(dt->player->x + move_x);
    double potential_y = roundf(dt->player->y + move_y);

    if (!circle_collision(dt, potential_x, dt->player->y))
        dt->player->x = potential_x;
    if (!circle_collision(dt, dt->player->x, potential_y))
        dt->player->y = potential_y;
}

void	player_rotation(t_data *dt, char rot_inc)
{
	if (rot_inc == '+')
	{
		dt->player->rot_angle += ROTATION_SPEED; 
		if (dt->player->rot_angle > 2 * M_PI)
			dt->player->rot_angle -= 2 * M_PI;
	}
	else
	{
		dt->player->rot_angle -= ROTATION_SPEED; 
		if (dt->player->rot_angle < 0)
			dt->player->rot_angle += 2 * M_PI;
	}
}

void game_loop(t_data *data) 
{
    ft_clear_image(data->img);
    casting_rays(data);
    draw_minimap(data);
}

void key_handler(void* param)
{
    t_data *dt = (t_data *)param;
    double new_x;
    double new_y;

    if (mlx_is_key_down(dt->mlx, MLX_KEY_ESCAPE))
        exit(0);
    if (mlx_is_key_down(dt->mlx, MLX_KEY_LEFT))
        player_rotation(dt, '-');
    else if (mlx_is_key_down(dt->mlx, MLX_KEY_RIGHT))
        player_rotation(dt, '+');
    if (mlx_is_key_down(dt->mlx, MLX_KEY_W))
    {
        new_x = cos(dt->player->rot_angle) * PLYR_SPEED;
        new_y = sin(dt->player->rot_angle) * PLYR_SPEED;
    }
    else if (mlx_is_key_down(dt->mlx, MLX_KEY_S))
    {
        new_x = -cos(dt->player->rot_angle) * PLYR_SPEED;
        new_y = -sin(dt->player->rot_angle) * PLYR_SPEED;
    }
    else if (mlx_is_key_down(dt->mlx, MLX_KEY_A))
    {
        new_x = sin(dt->player->rot_angle) * PLYR_SPEED;
        new_y = -cos(dt->player->rot_angle) * PLYR_SPEED;
    }
    else if (mlx_is_key_down(dt->mlx, MLX_KEY_D))
    {
        new_x = -sin(dt->player->rot_angle) * PLYR_SPEED;
        new_y = cos(dt->player->rot_angle) * PLYR_SPEED;
    }
    move_player(dt, new_x, new_y);
    game_loop(dt);
}

void init_player(t_data *dt)
{
    dt->player->x = dt->p_x_pos_in_map * TILE_SIZE + TILE_SIZE / 2; 
	dt->player->y = dt->p_y_pos_in_map * TILE_SIZE + TILE_SIZE / 2;
	dt->player->fov_in_rd = (FOV_ANGLE * M_PI) / 180;
    if (dt->map[dt->p_y_pos_in_map][dt->p_x_pos_in_map] == 'W')
	    dt->player->rot_angle = M_PI;
    else if (dt->map[dt->p_y_pos_in_map][dt->p_x_pos_in_map] == 'N')
	    dt->player->rot_angle = (3 * M_PI) / 2;
    else if (dt->map[dt->p_y_pos_in_map][dt->p_x_pos_in_map] == 'E')
	    dt->player->rot_angle = 0;
    else if (dt->map[dt->p_y_pos_in_map][dt->p_x_pos_in_map] == 'S')
	    dt->player->rot_angle = M_PI / 2;
}

void open_close_door(t_data *dt)
{
    float next_x = dt->player->x + cos(dt->player->rot_angle) * TILE_SIZE;
    float next_y = dt->player->y + sin(dt->player->rot_angle) * TILE_SIZE;

    if ((dt->map[dt->player->y / TILE_SIZE][dt->player->x / TILE_SIZE] == 'D' || dt->map[dt->player->y / TILE_SIZE][dt->player->x / TILE_SIZE] == 'O')
        && (dt->map[(int)next_y / TILE_SIZE][(int)next_x / TILE_SIZE] == 'D' || dt->map[(int)next_y / TILE_SIZE][(int)next_x / TILE_SIZE] == 'O'))
        return ;
    int grid_x = (int)floor(next_x / TILE_SIZE);
    int grid_y = (int)floor(next_y / TILE_SIZE);
    if (grid_x >= 0 && grid_x < dt->map_w && grid_y >= 0 && grid_y < dt->map_h)
    {
        if (dt->map[grid_y][grid_x] == 'D')
            dt->map[grid_y][grid_x] = 'O';
        else if (dt->map[grid_y][grid_x] == 'O')
            dt->map[grid_y][grid_x] = 'D';
    }
}

void doors_hook(void *p)
{
    t_data *dt = (t_data *)p;

    static bool door_key_pressed = false;

    if (mlx_is_key_down(dt->mlx, MLX_KEY_C))
    {
        if (!door_key_pressed)
        {
            open_close_door(dt);
            door_key_pressed = true;
        }
    }
    else
        door_key_pressed = false;
}

// void ft_mouse_hook(void *p)
// {
//     t_data  *dt;
//     int     x;
//     int     y;
//     int     delta_x;
//     int     center_x;

//     dt = (t_data *)p;
//     mlx_get_mouse_pos(dt->mlx, &x, &y);
//     center_x = S_W / 2; 
//     delta_x = x - center_x;
//     dt->player->rot_angle += delta_x * FACTOR; 
//     mlx_set_mouse_pos(dt->mlx, center_x, S_H / 2);
// }

void start_game(t_data *data)
{
    init_player(data);
    data->mlx = mlx_init(S_W, S_H, "CUB3D", true);
    if (!data->mlx)
    {
        perror("Error initializing window");
        ft_free_exit(data);
    }
    data->img = mlx_new_image(data->mlx, S_W, S_H);
    if (!data->img)
    {
        perror("Error creating image");
        exit(1) ;
    }
    mlx_image_to_window(data->mlx, data->img, 0, 0);
    data->weapen_img = mlx_texture_to_image(data->mlx, data->weapen_txt[0]);
    mlx_image_to_window(data->mlx, data->weapen_img, 0, 0);
	mlx_loop_hook(data->mlx,  key_handler, data);
    mlx_loop_hook(data->mlx,  doors_hook, data);
    mlx_loop_hook(data->mlx, weapen_hooks, data);
    // mlx_loop_hook(data->mlx, ft_mouse_hook, data);
	mlx_loop(data->mlx);
}