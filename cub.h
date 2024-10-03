/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 05:43:32 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/10/02 20:18:04 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"
#include "MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
#include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1486969768
# endif

#define     factor 0.003
# define S_W 1900
# define S_H 1000
# define TILE_SIZE 30
# define FOV_ANGLE 60
# define PLYR_SPEED 4
# define ROTATION_SPEED 0.045
# define WALL_WIDTH 1

typedef struct s_player
{
 int	x;
 int	y;
 float	rot_angle;
 float  fov_in_rd;
 int	width;
 int	hieght;
 int    left_right;
 int    up_down;
 int    turn_direction;
 float  move_speed;
 float  turn_speed;
} t_player;

typedef struct s_ray
{
 float ray_angle;
 float distance;
 bool	is_vert;
 bool  ray_facing_up;
 bool  ray_facing_down;
 bool  ray_facing_left;
 bool  ray_facing_right;
 float  h_wall_x_hit;
 float  h_wall_y_hit;
 float  v_wall_x_hit;
 float  v_wall_y_hit;
 float  wall_x_hit;
 float  wall_y_hit;
} t_ray;

typedef struct s_texture
{
	int 			height;
	int 			width;
	unsigned char 	*pixel_data;
	
} t_texture;

typedef struct s_pars
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			is_c;
	int 		is_f;
	int 		c[3];
	int 		f[3];
	int			floor_color;
	int			ceiling_color;
	t_texture	*north;
	t_texture	*south;
	t_texture	*west;
	t_texture	*east;
} t_pars;

typedef struct s_data
{
 mlx_t		*mlx;
 mlx_image_t	*img;
 int		p_x_pos_in_map;
 int		p_y_pos_in_map;
 int		map_w;
 int		map_h;
 int		num_rays;
 t_ray		*ray;
 t_player	*player;
bool 				is_play;
bool 				is_load;
int 				fram;
int					ammo;
mlx_texture_t		*weapen_txt[19];
mlx_image_t			*weapen_img;
char				*weap_path[19];
char				**map;
char				**texters;
char 				**colors;
t_pars				pars;
} t_data;



///=================////
 
typedef struct s_params
{
	t_pars 		*pars;
	t_data 		*data;
	t_player 	*player;
	t_texture 	*texture;
} t_params;

void		set_hei_and_wid(t_data *data);
char		*ft_read_map(char *p);
void		ft_free_2dm(char **arr);
void 		ft_setparam(t_params *param);
int			ft_check_map(t_data *data, t_pars *args);
int    		ft_pars_colors(t_data *data, t_pars *args);
int 		ft_pars_texters(t_data *data, t_pars *args);
void 		ft_free_exit(t_data *data);
int			ft_disperse_map(t_data *data, char *file_map);
int 		draw_pixel(mlx_image_t *img, float pixel_size, int a, int b, int color);
void 		draw_player_circle(mlx_image_t *img, float x, float y, int size, int color);
int         draw_minimap(t_data *dt);
int 		ft_get_map(t_data *data, char *map);
char    	**ft_add_spaces(t_data *data, char **str);
int 		ft_check_digit(char *str);
void 		ft_set_colore(t_pars *args);
void		ft_init_texters(t_params *param);
int			ft_get_colore(int r, int g, int b);
t_texture   *ft_get_data(char *path);
void		ft_clear_image(mlx_image_t *img);
int			ft_init_weapen_images(t_data *data);
void		weapen_hooks(void *p);


bool		check_map_collision(t_data *dt, int grid_x, int grid_y);
void		get_player_pos(char **grid, t_data *dt);
float		normalize_angle(float ray_angle);
void		init_data(t_data *dt);
bool		find_wall_at(t_data *dt, int x, int y, char **grid);
void		start_game(t_data *data);
void		casting_rays(t_data *dt);
void		render_wall(t_data *dt, int ray);
#endif