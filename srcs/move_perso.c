/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_perso.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 09:56:54 by abonnefo          #+#    #+#             */
/*   Updated: 2023/02/01 14:53:17 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_key_press(int keycode, t_data *data)
{
	data->collectible = ft_count_items(data->tab, 'C');
	if ((keycode == W || keycode == UP)
		&& data->tab[data->player_y - 1][data->player_x] != '1')
		ft_move_up(data);
	if ((keycode == S || keycode == DOWN)
		&& data->tab[data->player_y + 1][data->player_x] != '1')
		ft_move_down(data);
	if ((keycode == A || keycode == LEFT)
		&& data->tab[data->player_y][data->player_x - 1] != '1')
		ft_move_left(data);
	if ((keycode == D || keycode == RIGHT)
		&& data->tab[data->player_y][data->player_x + 1] != '1')
		ft_move_right(data);
	ft_put_into_window(data, data->tab);
	return (0);
}
