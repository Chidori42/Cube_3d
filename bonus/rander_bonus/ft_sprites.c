/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:18:58 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/10/04 20:30:58 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

int	ft_get_pngs_path(t_data *data)
{
	int		i;
	char	*tmp;
	char	*path;

	i = 0;
	while (i < 14)
	{
		path = ft_strdup("textures/weapen_pngs/");
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
	while (i < 14)
	{
		data->weapen_txt[i] = mlx_load_png(data->weap_path[i]);
		if (!(data->weapen_txt[i]))
			return (ft_putendl_fd("loadpng fail!!", 2), 1);
		i++;
	}
	i = 0;
    while (i < 14)
        free(data->weap_path[i++]);
	return (0);
}

void ft_load(t_data *data)
{
    static int frame_delay = 0;

	if (frame_delay % 5 == 0)
    {
		mlx_delete_image(data->mlx, data->weapen_img);
		data->weapen_img = mlx_texture_to_image(data->mlx, data->weapen_txt[data->fram]);
		mlx_resize_image(data->weapen_img, 375, 400);
		mlx_image_to_window(data->mlx, data->weapen_img, 600, 600);
        data->fram++;
        if (data->fram >= 14)
        {
            frame_delay = 0;
            data->is_load = false;
            data->ammo = 8;
			mlx_delete_image(data->mlx, data->weapen_img);
			data->weapen_img = mlx_texture_to_image(data->mlx, data->weapen_txt[3]);
			mlx_resize_image(data->weapen_img, 375, 400);
			mlx_image_to_window(data->mlx, data->weapen_img, 600, 600);
        }
	}
    frame_delay++;
}

void ft_shoot(t_data *data)
{
    static int frame_delay = 0;

    if (frame_delay % 10 == 0)
    {
		mlx_delete_image(data->mlx, data->weapen_img);
		data->weapen_img = mlx_texture_to_image(data->mlx, data->weapen_txt[data->fram]);
		mlx_resize_image(data->weapen_img, 375, 400);
		mlx_image_to_window(data->mlx, data->weapen_img, 600, 600);
        data->fram++;
        if (data->fram >= 3)
        {
            frame_delay = 0;
            data->is_play = false;
            data->ammo--;
            if (data->ammo == 0)
                data->is_load = true;
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
        data->fram = 0;
	}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_R) && !data->is_load && !data->is_play)
	{
        data->is_load = true;
        data->fram = 4;
	}
	if (data->is_load == true || data->ammo == 0)
        ft_load(data);  
    else if (data->is_play)
        ft_shoot(data);
}

