/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:49:22 by abonnefo          #+#    #+#             */
/*   Updated: 2023/02/02 08:55:53 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_invalid_open(int ac, char **av)
{
	int	fd;

	if (ac != 2)
	{
		ft_printf("Error : Invalid number of arguments\n");
		exit(1);
	}
	fd = open(av[1], O_DIRECTORY);
	if (fd > 0)
	{
		ft_printf("Error : Invalid map (<name>.ber)\n");
		exit(1);
	}
	if (ft_strlen(av[1]) < 4
		|| av[1][ft_strlen(av[1]) - 4] != '.'
		|| av[1][ft_strlen(av[1]) - 3] != 'b'
		|| av[1][ft_strlen(av[1]) - 2] != 'e'
		|| av[1][ft_strlen(av[1]) - 1] != 'r')
	{
		ft_printf("Error : Invalid file, use a (<name>.ber)\n");
		exit(1);
	}
}

void	ft_run_window(t_data *data)
{
	ft_init_images(data->img);
	data->mlx_win = mlx_new_window(data->mlx,
			data->window_width, data->window_height, "so_long");
	ft_put_into_window(data, data->tab);
	mlx_hook(data->mlx_win, 3, 1L << 1, ft_key_press, data);
	mlx_hook(data->mlx_win, 2, 1L << 0, ft_close_esc, data);
	mlx_hook(data->mlx_win, 17, 1L << 17, ft_close_mouse, data);
	mlx_loop(data->mlx);
}

int	main(int ac, char **av)
{
	t_data	data;
	t_image	img;

	ft_invalid_open(ac, av);
	data.count = 0;
	data.tab = ft_put_in_tab(av[1]);
	// if (data.tab == NULL)
	// 	exit(1);
	data.mlx = mlx_init();
	data.img = &img;
	data.window_width = ft_count_width(data.tab) * 80;
	data.window_height = ft_count_height(data.tab) * 80;
	data.x = ft_count_width(data.tab);
	data.y = ft_count_height(data.tab);
	data.player_y = ft_search_perso_y(data.y, data.x, 'P', data.tab);
	data.player_x = ft_search_perso_x(data.y, data.x, 'P', data.tab);
	ft_run_window(&data);
	free(data.mlx);
}
