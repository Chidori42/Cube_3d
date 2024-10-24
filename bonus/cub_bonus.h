/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakazdao <yakazdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 05:43:32 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/10/23 09:10:30 by yakazdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_BONUS_H
# define CUB_BONUS_H

# include <math.h>
# include <stdio.h>
# include <time.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1486969768
# endif

# define FACTOR 0.003
# define S_W 1900
# define S_H 1000
# define TILE_SIZE 30
# define FOV_ANGLE 60
# define PLYR_SPEED 5
# define ROTATION_SPEED 0.1
# define WALL_WIDTH 1
# define TEX_WIDTH 30
# define TEX_HEIGHT 30

# define TEXTURE_NO "NO"
# define TEXTURE_SO "SO"
# define TEXTURE_WE "WE"
# define TEXTURE_EA "EA"
# define COLOR_C "C"
# define COLOR_F "F"

typedef struct s_player
{
	int			x;
	int			y;
	float		rot_angle;
	float		fov_in_rd;
	int			width;
	int			hieght;
	int			left_right;
	int			up_down;
	int			turn_direction;
	float		move_speed;
	float		turn_speed;
}		t_player;

typedef struct s_ray
{
	float	ray_angle;
	float	distance;
	bool	is_vert;
	bool	ray_facing_up;
	bool	ray_facing_down;
	bool	ray_facing_left;
	bool	ray_facing_right;
	float	h_wall_x_hit;
	float	h_wall_y_hit;
	float	v_wall_x_hit;
	float	v_wall_y_hit;
	float	wall_x_hit;
	float	wall_y_hit;
}		t_ray;

typedef struct s_texture
{
	int				height;
	int				width;
	unsigned char	*pixel_data;
}		t_texture;

typedef struct s_pars
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			is_c;
	int			is_f;
	int			c[3];
	int			f[3];
	int			floor_color;
	int			ceiling_color;
	t_texture	*north;
	t_texture	*south;
	t_texture	*west;
	t_texture	*east;
}		t_pars;

typedef struct s_data
{
	mlx_t				*mlx;
	mlx_image_t			*img;
	int					p_x_pos_in_map;
	int					p_y_pos_in_map;
	int					map_w;
	int					map_h;
	int					num_rays;
	float				wall_height;
	t_ray				*ray;
	t_player			*player;
	bool				is_play;
	bool				is_load;
	bool				is_animate;
	int					start_fram;
	int					end_fram;
	int					frame_delay;
	int					shoot_fram;
	mlx_texture_t		*weapen_txt[330];
	mlx_image_t			*weapen_img;
	char				*weap_path[330];
	t_texture			*door_txt;
	bool				is_door;
	char				**map;
	char				**texters;
	char				**colors;
	int					x_offset;
	int					y_offset;
	char				*file_map;
	int					index;
	bool				door_key_pressed;
	t_pars				pars;
	t_texture			*texture;
	int					grid_x;
	int					grid_y;
	float				intensity;
	float				max_distance;

	float x_intercept;
    float y_intercept;
    float x_step;
    float y_step;
    float x_check;
    float y_check;
}		t_data;

/*************************************************/

void		set_hei_and_wid(t_data *data);
char		*ft_read_map(char *p);
void		ft_free_2dm(char **arr);
void		ft_setparam(t_data *data);
int			ft_check_map(t_data *data, t_pars *args);
int			ft_pars_colors(t_data *data, t_pars *args);
int			ft_pars_texters(t_data *data, t_pars *args);
void		ft_free_exit(t_data *data);
int			ft_disperse_map(t_data *data);
int			draw_pixel(mlx_image_t *img, float pixel_size, float a, float b, int color);
int			draw_minimap(t_data *dt);
int			ft_get_map(t_data *data, char *map);
char		**ft_add_spaces(t_data *data, char **str);
int			ft_check_digit(char *str);
void		ft_set_colore(t_pars *args);
int			ft_init_texters(t_data *data);
int			ft_get_colore(int r, int g, int b);
t_texture	*ft_get_data(char *path);
void		ft_clear_image(mlx_image_t *img);
int			ft_init_weapen_images(t_data *data);
void		weapen_hooks(void *p);
int			ft_check_borders(t_data *data);
char		*ft_read_line(char *file_map);
int			check_valid_color(char *str);
int			get_data(t_data *data, char *colors, char *texters, char *map);

int			ft_init_door_image(t_data *data);
void		game_loop(t_data *data);
void		get_player_pos(char **grid, t_data *dt);
float		normalize_angle(float ray_angle);
void		init_data(t_data *dt);
bool		find_wall_at(t_data *dt, int x, int y, char **grid);
void		start_game(t_data *data);
void		casting_rays(t_data *dt);
void		key_handler(void *param);
void		render_wall(t_data *dt, int ray);
void		init_player(t_data *dt);
int			circle_collision(t_data *dt, double x, double y);
void		doors_hook(void *p);
void		player_rotation(t_data *dt, char rot_inc);
void		get_ray_facing(t_data *dt, float ray_angle);
void		compare_ray_dis(t_data *dt, float horz_distance, float vert_distance);
void		ft_mlx_put_pixel(t_data *dt, int x, int y, int color);
void		apply_shadow(uint32_t *color, t_data *dt);
uint32_t	get_texture_pix(t_data *dt);
#endif