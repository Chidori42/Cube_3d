/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doors_animistions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 01:37:46 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/10/09 03:36:20 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

int	ft_get_doors_path(t_data *data, char *type, char *txt_path[])
{
	int		i;
    char	*tmp1;
	char	*tmp2;
    char    *tmp3;
	char	*path;

	i = 0;
	while (i < 7)
	{
		path = ft_strdup("textures/Doors/");
        tmp1 = ft_strdup(type);
        tmp2 = ft_itoa(i + 1);
		tmp3 = ft_strjoin(ft_strjoin(tmp1, tmp2), ".png");
		txt_path[i] = ft_strjoin(path, tmp3);
		if (!(txt_path[i]))
			return (1);
        free (tmp2);
		free (tmp3);
		i++;
	}
	txt_path[i] = NULL;
	return (0);
}

static int ft_load_textures(t_texture *txt[], char *txt_path[])
{
    int i = 0;

    while (i < 7)
	{
        printf("%s\n", txt_path[i]);
		txt[i] = ft_get_data(txt_path[i]);
		if (!(txt[i]))
			return (ft_putendl_fd("loadpng fail!!", 2), 1);
		i++;
	}
	i = 0;
    while (i < 7)
        free(txt_path[i++]);
    return (0);
}

int	ft_init_door_images(t_data *data)
{
	int i = 0;
	if (ft_get_doors_path(data, "open", data->d_open)
        || ft_get_doors_path(data, "close", data->d_close))
		return (1);
	if (ft_load_textures(data->open_txt, data->d_open)
        || ft_load_textures(data->close_txt, data->d_close))
        return (1);
	return (0);
}

void ft_open(t_data *data)
{
    unsigned int frame_delay = 0;
    t_texture *txt;

    if (frame_delay % 10 == 0)
    {
        txt = data->open_txt[data->door_frame];
        if (data->door_frame == 8)
        {
            frame_delay = 0;
            data->door_frame = 0;
            data->is_open = true;
            data->is_close = false;
        }
    }
    frame_delay++;
}

void ft_close(t_data *data)
{
    static int frame_delay = 0;
    t_texture *txt;
    if (frame_delay % 10 == 0)
    {
        txt = data->close_txt[data->door_frame];
        data->door_frame++;
        if (data->door_frame == 8)
        {
            frame_delay = 0;
            data->door_frame = 0;
            data->is_open = false;
            data->is_close = true;
        }
    }
    frame_delay++; 
}

void doors_kook(void *p)
{
    t_data *data = (t_data *)p;
    
    if (mlx_is_key_down(data->mlx, MLX_KEY_C))
    {
        if (data->is_open && !data->is_close)
            ft_close(data);
        else if (data->is_close && !data->is_open)
            ft_open(data);
    }
}
