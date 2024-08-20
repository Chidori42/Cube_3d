/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 05:43:32 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/08/20 04:01:32 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"
#include "MLX42/MLX42.h"
# include <stdlib.h>
#include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1486969768
# endif 
#define MOVE_STEP 0.25
#define PI 3.14159265358979323846
#define FOV 60
#define DEG_TO_RAD(deg) ((deg) * (PI / 180.0))

typedef struct s_data
{
	mlx_t				*mlx;
	mlx_image_t			*img;
	int					fd;
	int					hei;
	int					wid;
}	t_data;

typedef struct  s_camera {
    double      posX;
    double      posY;
    double      dirX;
    double      dirY;
}               t_camera;

typedef struct s_pars
{
	float 		x0;
    float 		y0;
    float 		x1;
    float 		y1;
	float 		pa;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			is_c;
	int 		is_f;
	char		**map;
	char		**texters;
	char 		**colors;
} t_pars;

typedef struct s_params
{
	t_pars 		*pars;
	t_data 		*data;
	t_camera 	*camera;
} t_params;

int 	init_mlx(t_data *data);
char	**my_split(char const *s);
int 	is_white_space(char c);
void	draw_map(t_data *data, t_pars *args);
char	*ft_read_map(char *p);
void	ft_free_2dm(char **arr);
void 	ft_setparam(t_params *param);
int		ft_check_map(t_data *data, t_pars *args);
int    	ft_pars_colors(t_pars *args);
int		ft_pars_texters(t_pars *args);
void 	ft_free_exit(t_params *param);
void	key_press(void *p);
int		ft_diff_map(t_pars *args, char *file_map);
int		draw_pixel(t_data *data, int pixel_size, int a, int b, int color);
void 	init_camera(t_pars *args, t_camera *camera);
void    draw_camera_direction(t_params *param, int color);

#endif