/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakazdao <yakazdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:18:58 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/10/14 15:13:53 by yakazdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

int	ft_get_pngs_path(t_data *data)
{
	int		i;
	char	*tmp;
	char	*path; 

	i = 0;
	while (i < 329)
	{
		path = ft_strdup("textures/knif/");
		tmp = ft_strjoin(ft_itoa(i + 1), ".png");
		data->weap_path[i] = ft_strjoin(path, tmp);
		if (!(data->weap_path[i]))
			return (1);
		free (tmp);
		i++;
	}
	data->weap_path[i] = NULL;
	return (0);
}

int	ft_init_weapen_images(t_data *data)
{
	int i = 0;
	if (ft_get_pngs_path(data))
		return (1);
	while (i < 329)
	{
		data->weapen_txt[i] = mlx_load_png(data->weap_path[i]);
		if (!(data->weapen_txt[i]))
		{
			printf("index : %d\n", i);
			return (ft_putendl_fd("loadpng fail!!", 2), 1);
		}
		i++;
	}
	i = 0;
    while (i < 329)
        free(data->weap_path[i++]); 
	return (0);
}

void ft_load(t_data *data)
{
    static int frame_delay = 0;

	if (data->start_fram == 0)
		data->end_fram = 115;
	else if (data->start_fram == 115)
		data->end_fram = 180;
	else if (data->start_fram == 180)
		data->end_fram = 283;
	if (frame_delay % 2 == 0)
    {
		mlx_delete_image(data->mlx, data->weapen_img);
		data->weapen_img = mlx_texture_to_image(data->mlx, data->weapen_txt[data->start_fram]);
        data->start_fram++;
        if (data->start_fram >= data->end_fram)
        {
            frame_delay = 0;
            data->is_load = false;
        }
	}
    frame_delay++;
}

void ft_shoot(t_data *data)
{
    static int frame_delay = 0;

    if (frame_delay % 2 == 0)
    {
		mlx_delete_image(data->mlx, data->weapen_img);
		data->weapen_img = mlx_texture_to_image(data->mlx, data->weapen_txt[data->shoot_fram]);
        data->shoot_fram++;
        if (data->shoot_fram >= 329)
        {
            frame_delay = 0;
            data->is_play = false;
			mlx_delete_image(data->mlx, data->weapen_img);
			data->weapen_img = mlx_texture_to_image(data->mlx, data->weapen_txt[0]);
        }
    }
    frame_delay++;
}

void ft_animate(t_data *data)
{
    static int frame_delay = 0;
	static int start = 132;
	static int end = 150;

	if (frame_delay % 2 == 0)
    {
		mlx_delete_image(data->mlx, data->weapen_img);
		data->weapen_img = mlx_texture_to_image(data->mlx, data->weapen_txt[start]);
        start++;
        if (start >= end)
		{
            frame_delay = 0;
			start = 132;
			data->is_animate = false;
		}
	}
    frame_delay++;
}

void weapen_hooks(void *p)
{
    t_data *data;

    data = (t_data *)p;
    if (mlx_is_key_down(data->mlx, MLX_KEY_SPACE) && !data->is_play && !data->is_load)
	{
        data->is_play = true;
        data->shoot_fram = 284;
	}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_R) && !data->is_load && !data->is_play)
	{
        data->is_load = true;
		if (data->end_fram == 0 || data->end_fram == 283)
        	data->start_fram = 0;
		else if (data->end_fram == 115)
			data->start_fram = 115;
		else if (data->end_fram == 180)
			data->start_fram = 180;
	}
	if (!data->is_animate)
		data->is_animate = true;

	if (data->is_load)
        ft_load(data);
    else if (data->is_play)
        ft_shoot(data);
	else if (!data->is_play && !data->is_load)
		ft_animate(data);
	mlx_image_to_window(data->mlx, data->weapen_img, 0, 0);
    data->weapen_img->instances->enabled = true;
}
