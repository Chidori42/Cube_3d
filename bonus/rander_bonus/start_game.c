/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:58:00 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/10/10 10:40:35 by ael-fagr         ###   ########.fr       */
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

void ft_reset_door(t_data *dt)
{
    int grid_x;
    int grid_y;
    int new_x;
    int new_y;

    new_x = roundf(dt->player->x + 1);
	new_y = roundf(dt->player->y + 1);  
	grid_x = (new_x / TILE_SIZE);  
	grid_y = (new_y / TILE_SIZE); 

    if (grid_x >= 0 && grid_x < dt->map_w && grid_y >= 0 && grid_y < dt->map_h)
    {
        if (dt->is_door == true && (dt->map[(int)grid_y][(int)grid_x] == 'D' \
            || dt->map[(int)grid_y][(int)grid_x] == 'O'))

        {
            printf("hello\n");
            if (dt->map[(int)grid_y][(int)grid_x] == 'D')
                dt->map[(int)grid_y][(int)grid_x] = 'O';
            else
                dt->map[(int)grid_y][(int)grid_x] = 'D';
        }
    }
}

void key_handler(void* param)
{
    t_data *dt = (t_data *)param;
    double new_x;
    double new_y;

    if (mlx_is_key_down(dt->mlx, MLX_KEY_ESCAPE))
        exit(0);
    if (mlx_is_key_down(dt->mlx, MLX_KEY_G))
        ft_reset_door(dt);
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
	dt->player->rot_angle = M_PI; 
}

void game_loop(t_data *data) 
{
    ft_clear_image(data->img);
    casting_rays(data);
    draw_minimap(data);
}


void retate_angle(void *param)
{
    t_data *dt = (t_data *)param;
    int x;
    int y;
    mlx_get_mouse_pos(dt->mlx, &x, &y);
    int dx = x - dt->player->rot_angle;
    dt->player->rot_angle = dx * factor;
}

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
    mlx_loop_hook(data->mlx, weapen_hooks, data);
	mlx_loop(data->mlx);
}
