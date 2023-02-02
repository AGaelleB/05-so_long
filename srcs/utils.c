/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:35:29 by abonnefo          #+#    #+#             */
/*   Updated: 2023/02/01 09:58:15 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_count_width(char **tab)
{
	int	x;

	x = 0;
	while (tab[0][x])
		x++;
	return (x);
}

int	ft_count_height(char **tab)
{
	int	y;

	y = 0;
	while (tab[y])
		y++;
	return (y);
}
