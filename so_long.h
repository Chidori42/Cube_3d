/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 05:43:32 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/02/09 12:44:57 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <math.h>
# include "mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1486969768
# endif 

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*w;
	void		*l;
	void		*c;
	void		*e;
	void		*e_o;
	void		*p_d;
	void		*enemy;
	int			fd;
	size_t		x;
	size_t		y;
	int			i;
	int			j;
	int			e_x_p;
	int			e_y_p;
	int			count_c;
	int			move;
	int			hei;
	int			wid;
	int			retate_x;
	int			retate_y;
	char		**map;
	char		**cp_mp;
}	t_data;

void	set_param(t_data *args);
void	set_p(t_data *arg);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char *s);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		key_press(int keycode, t_data *par);
void	draw_map(t_data *arg);
int		draw_pixel(t_data *data, int pixel_size, int a, int b, int color);
char	**read_map(char *p);
char	**ft_split(char *s, char c);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
int		check_map(t_data *arg);
size_t	check_flood(t_data *arg);
void	set_hei_and_wid(t_data *arg);
size_t	check_c(t_data *arg);
void	win_exit(t_data *arg, int x, int y);
int		ft_strncmp(char *s1, char *s2, int n);
char	*ft_strrchr(char *s, int c);
int		ft_check_ber(char *str);
void ft_dda_algo(t_data *args, int x1, int y1, int color);
void ft_draw_lines(t_data *args, int wid, int hei, int color);

#endif