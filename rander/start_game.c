/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:58:00 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/10/02 20:18:29 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

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

void    move_player(t_data *dt, int move_x, int move_y)
{
    int grid_x;
    int grid_y;
    int new_x;
    int new_y;

    new_x = roundf(dt->player->x + move_x);
	new_y = roundf(dt->player->y + move_y);  
	grid_x = (new_x / TILE_SIZE);  
	grid_y = (new_y / TILE_SIZE); 
	if (check_map_collision(dt, grid_x, grid_y))
	{
		dt->player->x = new_x;  
		dt->player->y = new_y;  
	}
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
void    hook_player(t_data *dt, double new_x, double new_y)
{
    if (dt->player->turn_direction == 1)
        player_rotation(dt, '+');
    if (dt->player->turn_direction == -1)
        player_rotation(dt, '-');
    if (dt->player->left_right == 1)
    {
        new_x = -sin(dt->player->rot_angle) * PLYR_SPEED;
        new_y = cos(dt->player->rot_angle) * PLYR_SPEED;
    }
    if (dt->player->left_right == -1)
    {
        new_x = sin(dt->player->rot_angle) * PLYR_SPEED;
        new_y = -cos(dt->player->rot_angle) * PLYR_SPEED;
    }
    if (dt->player->up_down == 1)
    {
        new_x = cos(dt->player->rot_angle) * PLYR_SPEED;
        new_y = sin(dt->player->rot_angle) * PLYR_SPEED;
    }
     if (dt->player->up_down == -1)
    {
        new_x = -cos(dt->player->rot_angle) * PLYR_SPEED;
        new_y = -sin(dt->player->rot_angle) * PLYR_SPEED;
    }
    move_player(dt, new_x, new_y);
}

void key_handler(mlx_key_data_t keydata, void* param)
{
    t_data *dt = (t_data *)param;

    if (keydata.action == MLX_PRESS)
    {
        if (keydata.key == MLX_KEY_ESCAPE)
            exit(0);
        if (keydata.key == MLX_KEY_A)
            dt->player->left_right = -1;
        else if (keydata.key == MLX_KEY_D)
            dt->player->left_right = 1;
        else if (keydata.key == MLX_KEY_W)
            dt->player->up_down = 1;
        else if (keydata.key == MLX_KEY_S)
            dt->player->up_down = -1;
        else if (keydata.key == MLX_KEY_LEFT)
            dt->player->turn_direction = -1;
        else if (keydata.key == MLX_KEY_RIGHT)
            dt->player->turn_direction = 1;
    }
    if (keydata.action == MLX_RELEASE)
    {
         if (keydata.key == MLX_KEY_A)
            dt->player->left_right =  0;
        else if (keydata.key == MLX_KEY_D)
            dt->player->left_right = 0;
        else if (keydata.key == MLX_KEY_W)
            dt->player->up_down = 0;
        else if (keydata.key == MLX_KEY_S)
            dt->player->up_down =  0;
        else if (keydata.key == MLX_KEY_LEFT)
            dt->player->turn_direction =  0;
        else if (keydata.key == MLX_KEY_RIGHT)
            dt->player->turn_direction = 0;
    }
}

void init_player(t_data *dt)
{
    dt->player->x = dt->p_x_pos_in_map * TILE_SIZE + TILE_SIZE / 2; 
	dt->player->y = dt->p_y_pos_in_map * TILE_SIZE + TILE_SIZE / 2;
	dt->player->fov_in_rd = (FOV_ANGLE * M_PI) / 180; 
	dt->player->rot_angle = M_PI; 
}

void game_loop(void *param) 
{
    t_data *data;

    data = (t_data *)param;
    mlx_delete_image(data->mlx, data->img);
    data->img = mlx_new_image(data->mlx, S_W, S_H);
    if (!data->img)
    {
        mlx_terminate(data->mlx);
        perror("Error creating image");
        exit(1) ;
    }
    ft_clear_image(data->img);
    hook_player(data, 0, 0);
    casting_rays(data);
    draw_minimap(data);
    mlx_image_to_window(data->mlx, data->img, 0, 0);
    // data->weapen_img = mlx_texture_to_image(data->mlx, data->weapen_txt[0]);
    // mlx_resize_image(data->weapen_img, 375, 400);
    // mlx_image_to_window(data->mlx, data->weapen_img, 600, 600);
}

void start_game(t_data *data)
{
    init_player(data);
    data->mlx = mlx_init(S_W, S_H, "CUB", true);
    if (!data->mlx)
    {
        perror("Error initializing window");
        ft_free_exit(data);
    }
	mlx_loop_hook(data->mlx, game_loop, data);
	mlx_key_hook(data->mlx,  key_handler, data);
    mlx_loop_hook(data->mlx, weapen_hooks, data);
	mlx_loop(data->mlx);
}
