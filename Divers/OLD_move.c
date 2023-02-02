/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 09:56:54 by abonnefo          #+#    #+#             */
/*   Updated: 2023/01/27 11:48:43 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_move_up(t_data *data, int x, int y)
{
	printf("\n	debut boucle ft_move_up\n	player avant x = %d et y = %d", data->player_x, data->player_y); //A SUPPRIMER

	// if (data->tab[y - 1][x] == 0)
		data->player_y -= 1; 
	printf("\n	player apres x = %d et y = %d\n", data->player_x, data->player_y); //A SUPPRIMER
}

void	ft_move_down(t_data *data, int x, int y)
{
	printf("\n	debut boucle ft_move_down\n	player avant x = %d et y = %d\n", data->player_x, data->player_y); //A SUPPRIMER

	// if (data->tab[y + 1][x] == 0)
		data->player_y += 1;
	printf("	player apres x = %d et y = %d\n", data->player_x, data->player_y); //A SUPPRIMER
}

void	ft_move_right(t_data *data, int x, int y)
{
	printf("\n	debut boucle ft_move_right\n	player avant x = %d et y = %d\n", data->player_x, data->player_y); //A SUPPRIMER

	// if (data->tab[y][x + 1] == 0)
		data->player_x += 1;
	printf("	player apres x = %d et y = %d\n", data->player_x, data->player_y); //A SUPPRIMER
}

void	ft_move_left(t_data *data, int x, int y)
{
	printf("\n	debut boucle ft_move_left\n	player avant x = %d et y = %d\n", data->player_x, data->player_y); //A SUPPRIMER

	// if (data->tab[y][x - 1] == 0)
		data->player_x -= 1;
	printf("	player apres x = %d et y = %d\n", data->player_x, data->player_y); //A SUPPRIMER
}

void	refresh_img(t_data *data) 
{
	refresh_img(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img->img_sand, 0, 0); // ou data->player_x, data->player_y
}

int	key_release(int keycode, t_data *data)
{
	// printf("\n\033[1;31m*** DEBUT KEY_RELEASE ***\033[0m\n"); //A SUPPRIMER
	if (keycode == W || keycode == UP)
	{
		printf("W is release");
		data->player_up = 0;
		printf("\n	Down data->player_down = %d\n", data->player_down); //A SUPPRIMER
		printf("\n	Up data->player_up = %d\n", data->player_up); //A SUPPRIMER
		printf("\n	Left data->player_left = %d\n", data->player_left); //A SUPPRIMER
		printf("\n	Right player_right = %d\n", data->player_right); //A SUPPRIMER
	}
	if (keycode == S || keycode == DOWN)
	{
		printf("S is release");
		data->player_down = 0;
	}
	if (keycode == A || keycode == LEFT)
	{
		printf("A is release");
		data->player_left = 0;
	}
	if (keycode == D || keycode == RIGHT)
	{
		printf("D is release");
		data->player_right = 0;
	}
	update_map(data);
	// printf("\n\033[1;31m*** FIN KEY_RELEASE ***\033[0m\n"); //A SUPPRIMER
	return (0);
}

int	key_press(int keycode, t_data *data)
{
	// printf("\n\033[1;33m*** DEBUT KEY_PRESS ***\n\n\033[0m"); //A SUPPRIMER
	if (keycode == ESC)
		ft_free_images(data);
	if (keycode == 119 || keycode == UP)
	{
		printf("*W is press*\n");
		data->player_up = 1;
		printf("\n	Down data->player_down = %d\n", data->player_down); //A SUPPRIMER
		printf("\n	Up data->player_up = %d\n", data->player_up); //A SUPPRIMER
		printf("\n	Left data->player_left = %d\n", data->player_left); //A SUPPRIMER
		printf("\n	Right player_right = %d\n", data->player_right); //A SUPPRIMER
	}
	if (keycode == 115 || keycode == DOWN)
	{
		printf("*S is press*\n");
		data->player_down = 1;
		printf("\n	Down data->player_down = %d\n", data->player_down); //A SUPPRIMER
		printf("\n	Up data->player_up = %d\n", data->player_up); //A SUPPRIMER
		printf("\n	Left data->player_left = %d\n", data->player_left); //A SUPPRIMER
		printf("\n	Right player_right = %d\n", data->player_right); //A SUPPRIMER
	}
	if (keycode == 97 || keycode == LEFT)
	{
		printf("*A is press*\n");
		data->player_left = 1;
		printf("\n	Down data->player_down = %d\n", data->player_down); //A SUPPRIMER
		printf("\n	Up data->player_up = %d\n", data->player_up); //A SUPPRIMER
		printf("\n	Left data->player_left = %d\n", data->player_left); //A SUPPRIMER
		printf("\n	Right player_right = %d\n", data->player_right); //A SUPPRIMER
	}
	if (keycode == 100 || keycode == RIGHT)
	{
		printf("*D is press*\n");
		data->player_right = 1;
		printf("\n	Down data->player_down = %d\n", data->player_down); //A SUPPRIMER
		printf("\n	Up data->player_up = %d\n", data->player_up); //A SUPPRIMER
		printf("\n	Left data->player_left = %d\n", data->player_left); //A SUPPRIMER
		printf("\n	Right player_right = %d\n", data->player_right); //A SUPPRIMER
	}
	update_map(data);
	// printf("\n\033[1;33m*** FIN KEY_PRESS ***\n\033[0m"); //A SUPPRIMER
	return (0);
}

void	update_map(t_data *data)
{
	int		x;
	int		y;
	printf("\n\033[1;32m*** DEBUT UPDATE_MAP ***\n\033[0m"); //A SUPPRIMER

	y = data->player_y;
	x = data->player_x;
	printf("\n\033[1;34mposition update P : x = %d et y = %d\n\033[0m", data->player_x, data->player_y); //A SUPPRIMER

	if (data->player_up != 0)
		ft_move_up(data, x, y);
	else if (data->player_down != 0)
		ft_move_down(data, x, y);
	else if (data->player_left != 0)
		ft_move_left(data, x, y);
	else if (data->player_right != 0)
		ft_move_right(data, x, y);
	// refresh_img(data);
	printf("\n\033[1;32m*** FIN UPDATE_MAP ***\n\033[0m"); //A SUPPRIMER
}

