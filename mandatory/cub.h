/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 05:43:32 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/10/18 05:40:13 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <math.h>
# include <stdio.h>
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

# define S_W 1900
# define S_H 1000
# define TILE_SIZE 30
# define FOV_ANGLE 60
# define PLYR_SPEED 5
# define ROTATION_SPEED 0.045
# define WALL_WIDTH 1

# define TEXTURE_NO "NO"
# define TEXTURE_SO "SO"
# define TEXTURE_WE "WE"
# define TEXTURE_EA "EA"
# define COLOR_C "C"
# define COLOR_F "F"

typedef struct s_player
{
	int		x;
	int		y;
	float	rot_angle;
	float	fov_in_rd;
	int		width;
	int		hieght;
	int		left_right;
	int		up_down;
	int		turn_direction;
	float	move_speed;
	float	turn_speed;
}		t_player;

typedef struct s_ray
{
	float		ray_angle;
	float		distance;
	bool		is_vert;
	bool		ray_facing_up;
	bool		ray_facing_down;
	bool		ray_facing_left;
	bool		ray_facing_right;
	float		h_wall_x_hit;
	float		h_wall_y_hit;
	float		v_wall_x_hit;
	float		v_wall_y_hit;
	float		wall_x_hit;
	float		wall_y_hit;
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
}	t_pars;

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
	char				**map;
	char				**texters;
	char				**colors;
	int					x_offset;
	int					y_offset;
	char				*file_map;
	int					index;
	t_pars				pars;
	t_texture			*texture;
}		t_data;

void		set_hei_and_wid(t_data *data);
char		*ft_read_map(char *p);
void		ft_free_2dm(char **arr);
void		ft_setparam(t_data *data);
int			ft_check_map(t_data *data, t_pars *args);
int			ft_pars_colors(t_data *data, t_pars *args);
int			ft_pars_texters(t_data *data, t_pars *args);
void		ft_free_exit(t_data *data);
int			ft_check_borders(t_data *data);
int			ft_get_map(t_data *data, char *map);
char		**ft_add_spaces(t_data *data, char **str);
int			ft_disperse_map(t_data *dt);
int			ft_check_digit(char *str);
void		ft_set_colore(t_pars *args);
int			ft_get_colore(int r, int g, int b);
char		*ft_read_line(char *file_map);
int			check_valid_color(char *str);
int			get_data(t_data *data, char *colors, char *texters, char *map);
t_texture	*ft_get_data(char *path);
int			ft_init_texters(t_data *data);
void		ft_clear_image(mlx_image_t *img);

bool		check_map_collision(t_data *dt, int grid_x, int grid_y);
void		get_player_pos(char **grid, t_data *dt);
float		normalize_angle(float ray_angle);
void		game_loop(t_data *data);
void		init_data(t_data *dt);
bool		find_wall_at(t_data *dt, int x, int y, char **grid);
void		start_game(t_data *data);
void		casting_rays(t_data *dt);
void		key_handler(void *param);
void		render_wall(t_data *dt, int ray);
#endif
