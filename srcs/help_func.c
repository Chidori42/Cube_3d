#include "../cub.h"

bool check_map_collision(t_data *dt, int grid_x, int grid_y)
{
    if (dt->map[grid_y][grid_x] != '1' && \
	(dt->map[grid_y][dt->player->x / TILE_SIZE] != '1' && \
	dt->map[dt->player->y / TILE_SIZE][grid_x] != '1'))
        return (true);
    return (false);
}

float normalize_angle(float ray_angle)
{
   if (ray_angle < 0)
		ray_angle += (2 * M_PI);
	if (ray_angle > (2 * M_PI))
		ray_angle -= (2 * M_PI);
	return (ray_angle);
}
bool find_wall_at(int x, int y, char **grid) 
{
    if (x < 0 || x > S_W || y < 0 || y > S_H)
		return (false);
    int grid_x = floor(x / TILE_SIZE);
    int grid_y = floor(y / TILE_SIZE);
    return (grid[grid_y][grid_x] == '1');
}

void    get_player_pos(char **grid, t_data *dt)
{
    int i;
    int j;

    i = 0;
    while (grid[i])
    {
        j = 0;
        while (grid[i][j])
        {
            if (grid[i][j] == 'E' || grid[i][j] == 'S' || grid[i][j] == 'N' || grid[i][j] == 'W')
            {
                dt->p_y_pos_in_map = i;
                dt->p_x_pos_in_map = j;
                return ;
            }
            j++;
        }
        i++;
    }
}
void init_data(t_data *dt)
{
	dt->player = calloc(1, sizeof(t_player));
	dt->ray = calloc(1, sizeof(t_ray));
    get_player_pos(dt->map, dt);
    dt->num_rays = S_W;
}
