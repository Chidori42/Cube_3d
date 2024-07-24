/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 05:43:32 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/07/24 08:02:26 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <math.h>
# include "mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1486969768
# endif 
#define PI 3.1415926535

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			fd;
	float 		x0;
    float 		y0;
    float 		x1;
    float 		y1;
	int			hei;
	int			wid;
	float 		pa;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		**map;
	char		**texters;
	char 		**colors;
	char 		**cp_mp;
}	t_data;

void	set_param(t_data *args);
void	set_p(t_data *arg);
size_t	check_flood(t_data *arg);
int		ft_check_map(t_data *args);
int    	ft_pars_colors(t_data *args);
int		ft_pars_texters(t_data *args);
void	ft_free_2dm(char **arr);
int		key_press(int keycode, t_data *par);
int		ft_diff_map(t_data *args, char *file_map);
void	draw_map(t_data *arg);
int		draw_pixel(t_data *data, int pixel_size, int a, int b, int color);
char	*ft_read_map(char *p);
void	set_hei_and_wid(t_data *arg);
void    dda_algo(t_data *data, float x1, float y1, float x2, float y2, int color);
void    draw_direction_line(t_data *data, int color);

#endif