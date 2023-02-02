/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 09:56:54 by abonnefo          #+#    #+#             */
/*   Updated: 2023/02/01 10:15:28 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_move_up(t_data *data)
{
	if (data->tab[data->player_y - 1][data->player_x] == 'E'
		&& data->collectible == 0)
		ft_exit_game(data);
	else if (data->tab[data->player_y - 1][data->player_x] != 'E')
	{
		data->tab[data->player_y][data->player_x] = '0';
		data->player_y -= 1;
		data->tab[data->player_y][data->player_x] = 'P';
		data->count++;
		ft_printf("Movement counter : \033[1;34m%d\033[0m\n", data->count);
	}
}

void	ft_move_down(t_data *data)
{
	if (data->tab[data->player_y + 1][data->player_x] == 'E'
		&& data->collectible == 0)
		ft_exit_game(data);
	else if (data->tab[data->player_y + 1][data->player_x] != 'E')
	{
		data->tab[data->player_y][data->player_x] = '0';
		data->player_y += 1;
		data->tab[data->player_y][data->player_x] = 'P';
		data->count++;
		ft_printf("Movement counter : \033[1;34m%d\033[0m\n", data->count);
	}
}

void	ft_move_left(t_data *data)
{
	if (data->tab[data->player_y][data->player_x - 1] == 'E'
		&& data->collectible == 0)
		ft_exit_game(data);
	else if (data->tab[data->player_y][data->player_x - 1] != 'E')
	{
		data->tab[data->player_y][data->player_x] = '0';
		data->player_x -= 1;
		data->tab[data->player_y][data->player_x] = 'P';
		data->count++;
		ft_printf("Movement counter : \033[1;34m%d\033[0m\n", data->count);
	}
}

void	ft_move_right(t_data *data)
{
	if (data->tab[data->player_y][data->player_x + 1] == 'E'
		&& data->collectible == 0)
		ft_exit_game(data);
	else if (data->tab[data->player_y][data->player_x + 1] != 'E')
	{
		data->tab[data->player_y][data->player_x] = '0';
		data->player_x += 1;
		data->tab[data->player_y][data->player_x] = 'P';
		data->count++;
		ft_printf("Movement counter : \033[1;34m%d\033[0m\n", data->count);
	}
}
