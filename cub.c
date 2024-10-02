/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 08:54:18 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/10/01 19:22:57 by ael-fagr         ###   ########.fr       */
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

// void rotate_view(t_player *player, int new_x)
// {
// 	// Calculate how much the mouse moved on the X-axis
// 	int dx = new_x - player->angle;
// 	// Adjust the factor 0.005 to control sensitivity
// 	player->angle = dx  * 0.005;
// }

// void	mouse_move(void *p)
// {
//     t_params *param = (t_params *)p;

//     int new_x = 0;
//     int new_y = 0;

//     mlx_get_mouse_pos(param->data->mlx, &new_x, &new_y);
//     rotate_view(param->player, new_x);
//     draw_minimap(param);
// }



int	main(int ac, char **av)
{
	t_data		data;
	t_pars		args;
	t_texture	texture;
	t_player 	player;
	t_params 	params;

	params.data = &data;
	params.pars = &args;
	params.player = &player;
	params.texture = &texture;
	if (ac == 2)
	{
		ft_setparam(&params);
		if (ft_valid_file(av[1]) || ft_disperse_map(&data, ft_read_map(av[1])))
			return (ft_free_exit(&params), 1);
		if (ft_check_map(&data, &args))
			return (ft_free_exit(&params), 1);
		// data.mlx = mlx_init(data.win_width, data.win_hei, "cub3D", true);
		// data.img = mlx_new_image(data.mlx, data.win_width, data.win_hei);
		if (ft_init_weapen_images(&data))
			return (ft_free_exit(&params), 1);
		init_data(&data);
    	start_game(&data);
	}
}
