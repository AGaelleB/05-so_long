/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_items.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:23:34 by abonnefo          #+#    #+#             */
/*   Updated: 2023/01/17 10:53:08 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_count_items(char **tab, char elem)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (tab[j])
	{
		while (tab[j][i])
		{
			if (tab[j][i] == elem)
				count ++;
			if (tab[j][i] != 'E' && tab[j][i] != 'C' && tab[j][i] != 'P'
				&& tab[j][i] != '0' && tab[j][i] != '1')
				return (0);
			i++;
		}
		i = 0;
		j++;
	}
	return (count);
}

int	ft_check_items(char **tab)
{
	int		out;
	int		collect;
	int		perso;

	out = ft_count_items(tab, 'E');
	collect = ft_count_items(tab, 'C');
	perso = ft_count_items(tab, 'P');
	if (out == 1 && collect >= 1 && perso == 1)
		return (1);
	else
	{
		ft_printf("%s", "Error: invalid items on the map\n");
		ft_free_tab(tab);
		exit(0);
	}
}
