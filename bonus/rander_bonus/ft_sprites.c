/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:18:58 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/10/28 15:46:05 by ael-fagr         ###   ########.fr       */
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
	int		i;
	int		end_i;
	bool	check_fail;

	1 && (i = 0, end_i = 329, check_fail = false);
	if (ft_get_pngs_path(data))
		return (1);
	while (i < 329)
	{
		data->weapen_txt[i] = mlx_load_png(data->weap_path[i]);
		if (!(data->weapen_txt[i]))
			1 && (end_i = i, check_fail = true);
		i++;
	}
	i = 0;
	while (i < 329)
	{
		if (check_fail == true && i < end_i)
			free(data->weapen_txt[i]);
		free(data->weap_path[i++]);
	}
	if (check_fail == true)
		return (ft_putendl_fd("loadpng fail!!", 2), 1);
	return (0);
}

void	ft_load(t_data *dt)
{
	if (dt->start_fram == 0)
		dt->end_fram = 115;
	else if (dt->start_fram == 115)
		dt->end_fram = 180;
	else if (dt->start_fram == 180)
		dt->end_fram = 283;
	if (dt->frame_delay % 2 == 0)
	{
		mlx_delete_image(dt->mlx, dt->weapen_img);
		dt->weapen_img = mlx_texture_to_image(dt->mlx, \
			dt->weapen_txt[dt->start_fram]);
		if (mlx_image_to_window(dt->mlx, dt->weapen_img, 0, 0) == -1)
			ft_exit(dt, "failed to init the window\n");
		dt->start_fram++;
		if (dt->start_fram >= dt->end_fram)
		{
			dt->frame_delay = 0;
			dt->is_load = false;
		}
	}
	dt->frame_delay++;
}

void	ft_shoot(t_data *dt)
{
	if (dt->frame_delay % 2 == 0)
	{
		mlx_delete_image(dt->mlx, dt->weapen_img);
		dt->weapen_img = mlx_texture_to_image(dt->mlx, \
			dt->weapen_txt[dt->shoot_fram]);
		mlx_image_to_window(dt->mlx, dt->weapen_img, 0, 0);
		dt->shoot_fram++;
		if (dt->shoot_fram >= 329)
		{
			dt->frame_delay = 0;
			dt->is_play = false;
			mlx_delete_image(dt->mlx, dt->weapen_img);
			dt->weapen_img = mlx_texture_to_image(dt->mlx, dt->weapen_txt[0]);
			mlx_image_to_window(dt->mlx, dt->weapen_img, 0, 0);
		}
	}
	dt->frame_delay++;
}

void	weapen_hooks(void *p)
{
	t_data	*dt;

	dt = (t_data *)p;
	if (mlx_is_key_down(dt->mlx, MLX_KEY_SPACE) && !dt->is_play && !dt->is_load)
	{
		dt->frame_delay = 0;
		dt->is_play = true;
		dt->shoot_fram = 284;
	}
	else if (mlx_is_key_down(dt->mlx, MLX_KEY_R) \
		&& !dt->is_load && !dt->is_play)
	{
		dt->frame_delay = 0;
		dt->is_load = true;
		if (dt->end_fram == 0 || dt->end_fram == 283)
			dt->start_fram = 0;
		else if (dt->end_fram == 115)
			dt->start_fram = 115;
		else if (dt->end_fram == 180)
			dt->start_fram = 180;
	}
	if (dt->is_load)
		ft_load(dt);
	else if (dt->is_play)
		ft_shoot(dt);
}
