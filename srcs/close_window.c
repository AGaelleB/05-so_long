/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:09:30 by abonnefo          #+#    #+#             */
/*   Updated: 2023/02/02 09:56:12 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free_images(t_data *data)
{
	if (data->img->img_sand)
		mlx_destroy_image(data->mlx, data->img->img_sand);
	if (data->img->img_cactus)
		mlx_destroy_image(data->mlx, data->img->img_cactus);
	if (data->img->img_cowboy)
		mlx_destroy_image(data->mlx, data->img->img_cowboy);
	if (data->img->img_gold)
		mlx_destroy_image(data->mlx, data->img->img_gold);
	if (data->img->img_horse)
		mlx_destroy_image(data->mlx, data->img->img_horse);
}

void	ft_free_game(t_data *data)
{
	if (data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	free(data->mlx);
}

void	ft_exit_game(t_data *data)
{
	data->count++;
	ft_printf("Movement counter : \033[1;34m%d\033[0m\n", data->count);
	ft_free_tab(data->tab);
	ft_free_images(data);
	ft_free_game(data);
	exit(0);
}

int	ft_close_esc(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		ft_free_tab(data->tab);
		ft_free_images(data);
		ft_free_game(data);
		exit(0);
	}
	return (0);
}

int	ft_close_mouse(t_data *data)
{
	ft_free_tab(data->tab);
	ft_free_images(data);
	ft_free_game(data);
	exit(0);
}
