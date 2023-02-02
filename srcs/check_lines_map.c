/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lines_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:06:24 by abonnefo          #+#    #+#             */
/*   Updated: 2023/01/24 09:14:11 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_check_first_line(char **tab)
{
	int	i;
	int	j;
	int	count_first;

	i = 0;
	j = 0;
	count_first = 0;
	while (tab[j])
		j++;
	while (tab[0][i])
	{
		if (tab[0][i] == '1')
			count_first++;
		i++;
	}
	return (i);
}

int	ft_check_last_line(char **tab)
{
	int	i;
	int	j;
	int	count_last;

	i = 0;
	j = 0;
	count_last = 0;
	while (tab[j])
		j++;
	while (tab[j - 1][i])
	{
		if (tab[j - 1][i] == '1')
			count_last++;
		i++;
	}
	return (i);
}

int	ft_check_first_and_last_line(char **tab)
{
	if (ft_check_first_line(tab) == ft_check_last_line(tab))
		return (1);
	else
		return (0);
}

int	ft_check_first_and_last_side(char **tab)
{
	int	j;
	int	lenght_line;

	j = 0;
	lenght_line = ft_strlen(tab[0]);
	while (tab[j])
	{
		if (tab[j][0] == '1' && tab[j][lenght_line - 1] == '1')
			j++;
		else
			return (0);
	}
	return (1);
}

int	ft_check_equal_lenght(char **tab)
{
	int	j;
	int	lenght_line;

	j = 0;
	lenght_line = ft_strlen(tab[0]);
	while (tab[j] && tab[j + 1])
	{
		if (tab[j][lenght_line] == tab[j + 1][lenght_line])
			j++;
		else
			return (0);
	}
	return (1);
}
