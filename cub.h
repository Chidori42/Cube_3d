/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 05:43:32 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/09/19 14:13:51 by ael-fagr         ###   ########.fr       */
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

#define MOVE_STEP 0.1
#define DEG_TO_RAD(deg) ((deg) * (M_PI / 180.0))

typedef struct s_data
{
	mlx_t				*mlx;
	mlx_image_t			*img;
	char				**map;
	char				**texters;
	char 				**colors;
	int					hei;
	int					wid;
}	t_data;


typedef struct s_texture
{
	int 			height;
	int 			width;
	unsigned char 	*pixel_data;
	
} t_texture;

typedef struct s_menu
{
	mlx_image_t			*img;
	mlx_image_t			*start_img;
    mlx_image_t			*back_img;
	int					hei;
	int					wid;
	int					check;
} t_menu;

typedef struct s_player
{
	float 		x;
	float 		y;
	float 		dx;
	float 		dy;
	char 		p_char;
	float 		angle;
	float 		fov;
} 	t_player;

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

typedef struct s_params
{
	t_pars 		*pars;
	t_data 		*data;
	t_player 	*player;
	t_texture 	*texture;
	t_menu		*menu;
} t_params;

int 		init_mlx(t_data *data);
char		**my_split(char const *s);
void		set_hei_and_wid(t_data *data);
int 		is_white_space(char c);
void		draw_map(t_params *param);
char		*ft_read_map(char *p);
void		ft_free_2dm(char **arr);
void 		ft_setparam(t_params *param);
int			ft_check_map(t_data *data, t_pars *args);
int    		ft_pars_colors(t_data *data, t_pars *args);
int 		ft_pars_texters(t_data *data, t_pars *args);
void 		ft_free_exit(t_params *param);
int			ft_disperse_map(t_data *data, char *file_map);
int 		draw_pixel(mlx_image_t *img, float pixel_size, int a, int b, int color);
void 		draw_player_circle(mlx_image_t *img, float x, float y, int size, int color);
int			draw_minimap(t_params *param);
int 		ft_get_map(t_data *data, char *map);
char    	**ft_add_spaces(t_data *data, char **str);
int 		ft_check_digit(char *str);
int 		t_check_window_size(t_data *data);
void 		ft_set_colore(t_pars *args);
void		key_press(void *p);
void		init_player(t_params *param);
int 		draw_line(t_data *data, int x0, int y0, int x1, int y1, int color);
int			ft_get_colore(int r, int g, int b);
void		ft_init_texters(t_params *param);
void		ft_rander_map(t_params *param);
int			get_pixel_color (t_texture *texture, int x, int y);
t_texture   *ft_get_data(char *path);
void		ft_close(void *param);
void 		ft_mlx_loop(t_params *param);
void		ft_menu_loop(t_params *param);
void		clear_window(t_data *data);
#endif