/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 09:28:29 by abonnefo          #+#    #+#             */
/*   Updated: 2023/02/02 09:55:40 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_init_images(t_data *data, t_image *img)
{
	img->img_width = 80;
	img->img_height = 80;
	img->path_sand = "images/sand.xpm";
	img->img_sand = mlx_xpm_file_to_image
		(data->mlx, img->path_sand, &img->img_width, &img->img_height);
	img->path_cactus = "images/cactus2.xpm";
	img->img_cactus = mlx_xpm_file_to_image
		(data->mlx, img->path_cactus, &img->img_width, &img->img_height);
	img->path_cowboy = "images/cowboy.xpm";
	img->img_cowboy = mlx_xpm_file_to_image
		(data->mlx, img->path_cowboy, &img->img_width, &img->img_height);
	img->path_gold = "images/gold.xpm";
	img->img_gold = mlx_xpm_file_to_image
		(data->mlx, img->path_gold, &img->img_width, &img->img_height);
	img->path_horse = "images/horse.xpm";
	img->img_horse = mlx_xpm_file_to_image
		(data->mlx, img->path_horse, &img->img_width, &img->img_height);
}

void	ft_put_caractere(t_data *data, char c)
{
	if (c == '0')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->img->img_sand, data->offset_x, data->offset_y);
	else if (c == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->img->img_cactus, data->offset_x, data->offset_y);
	else if (c == 'P')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->img->img_cowboy, data->offset_x, data->offset_y);
	else if (c == 'C')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->img->img_gold, data->offset_x, data->offset_y);
	else if (c == 'E')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->img->img_horse, data->offset_x, data->offset_y);
}

void	ft_put_into_window(t_data *data, char **tab)
{
	int	x;
	int	y;

	data->size_x = ft_count_width(tab);
	data->size_y = ft_count_height(tab);
	data->offset_x = 0;
	data->offset_y = 0;
	y = 0;
	while (y < data->size_y)
	{
		x = 0;
		while (x < data->size_x)
		{
			ft_put_caractere(data, data->tab[y][x]);
			data->offset_x += data->img->img_width;
			x++;
		}
		data->offset_x = 0;
		data->offset_y += data->img->img_height;
		y++;
	}
}
