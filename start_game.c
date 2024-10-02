#include "cub.h"

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
    //render_map(data);
    // render_player(data);
    hook_player(data, 0, 0);
    casting_rays(data);
    mlx_image_to_window(data->mlx, data->img, 0, 0);
}

void start_game(t_data *data)
{
    init_player(data);
    data->mlx = mlx_init(S_W, S_H, "CUB", true);
    if (!data->mlx)
    {
        perror("Error initializing window");
        // free 
        exit(0);
    }
	mlx_loop_hook(data->mlx, game_loop, data);
	mlx_key_hook(data->mlx,  key_handler, data);
	mlx_loop(data->mlx);
}