/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:27:08 by abonnefo          #+#    #+#             */
/*   Updated: 2023/01/24 11:41:57 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_search_perso_y(int y, int x, char to_find, char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (++j < y)
	{
		i = 0;
		while (++i < x)
			if (tab[j][i] == to_find)
				return (j);
	}
	return (0);
}

int	ft_search_perso_x(int y, int x, char to_find, char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (++j < y)
	{
		i = 0;
		while (++i < x)
			if (tab[j][i] == to_find)
				return (i);
	}
	return (0);
}

void	ft_search_and_replace(char **tab, int y, int x)
{
	int	size_y;
	int	size_x;

	size_y = 0;
	size_x = 0;
	while (tab[0][size_x])
		size_x++;
	while (tab[size_y])
		size_y++;
	if (y < 0 || y >= size_y || x < 0 || x >= size_x)
		return ;
	if (tab[y][x] != '1')
	{
		tab[y][x] = '1';
		ft_search_and_replace(tab, y, x + 1);
		ft_search_and_replace(tab, y, x - 1);
		ft_search_and_replace(tab, y + 1, x);
		ft_search_and_replace(tab, y - 1, x);
	}
}

void	ft_map_replace_e(char **tab, int size_y, int size_x)
{
	int	x;
	int	y;

	x = ft_search_perso_x(size_y, size_x, 'E', tab);
	y = ft_search_perso_y(size_y, size_y, 'E', tab);
	tab[y][x] = '1';
}

int	ft_check_ultimate_path(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[j])
	{
		while (tab[j][i])
		{
			if (tab[j][i] == 'C' || tab[j][i] == 'E')
			{
				ft_printf("%s", "Error: invalid path on the map\n");
				return (0);
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}
