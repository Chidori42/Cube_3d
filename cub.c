/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 08:54:18 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/09/23 17:40:39 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int ft_valid_file(char *p)
{
	int i;

	i = ft_strlen(p);
	if (p[i - 1] != 'b' || p[i - 2] != 'u' || p[i - 3] != 'c' || p[i - 4] != '.')
		return (ft_putendl_fd("Error\ninvalid file extantion", 2), 1);
	return (0);
}

int	ft_get_pngs_path(t_data *data)
{
	int i = 0;
	char *tmp;
	char *path;

	while (i < 19)
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
	while (i < 19)
	{
		data->weapen_txt[i] = mlx_load_png(data->weap_path[i]);
		i++;
	}
	return (0);
}

void play_sound(const char *file)
{
    char command[256];
    snprintf(command, sizeof(command), "afplay %s &", file);
    system(command);
}

void weapen_hooks(void *p)
{
    t_data *data;
    static bool playing = false;
    static int i = 0;
    static int frame_delay = 0;

    data = (t_data *)p;
    if (mlx_is_key_down(data->mlx, MLX_KEY_B) && !playing)
        playing = true;
    if (playing)
    {
        if (frame_delay % 5 == 0)
        {
			mlx_delete_image(data->mlx, data->weapen_img);
			data->weapen_img = mlx_texture_to_image(data->mlx, data->weapen_txt[i]);
			mlx_image_to_window(data->mlx, data->weapen_img, 600, 400);
            i++;
			if (i == 6)
				play_sound("textures/gun.mp3");
            if (i >= 19)
            {
                i = 0;
                playing = false;
            }
        }
		frame_delay++;
    }
}


int	main(int ac, char **av)
{
	t_data		data;
	t_pars		args;
	t_texture	texture;
	t_menu		menu;
	t_player 	player;
	t_params 	params;

	params.data = &data;
	params.pars = &args;
	params.menu = &menu;
	params.player = &player;
	params.texture = &texture;

	if (ac == 2)
	{
		ft_setparam(&params);
		if (ft_valid_file(av[1]) || ft_disperse_map(&data, ft_read_map(av[1])))
			return (ft_free_exit(&params), 1);
		if (ft_check_map(&data, &args))
			return (ft_free_exit(&params), 1);
		data.mlx = mlx_init(data.win_width, data.win_hei, "cub3D", true);
		data.img = mlx_new_image(data.mlx, data.win_width, data.win_hei);
		if (ft_init_weapen_images(&data))
			return (1);
		data.weapen_img = mlx_texture_to_image(data.mlx, data.weapen_txt[0]);
		mlx_image_to_window(data.mlx, data.weapen_img, 600, 400);
		if (menu.check == 0)
			ft_push_menu(&data, &menu);
		else
		{
			ft_mlx_loop(&params);
		}
		mlx_loop_hook(data.mlx, weapen_hooks, &data);
		mlx_loop_hook(data.mlx, key_press, &params);
		mlx_close_hook(data.mlx, ft_close, &data);
		mlx_loop(data.mlx);
	}
}
