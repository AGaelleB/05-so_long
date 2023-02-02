/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:06:24 by abonnefo          #+#    #+#             */
/*   Updated: 2023/02/02 17:01:46 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_check_backslash(char *str)
{
	int	i;
	int	consecutive_newlines;

	i = 0;
	consecutive_newlines = 0;
	if (str[i] == '\n')
	{
		ft_printf("%s", "Error: first character cannot be a newline.\n");
		return (free(str), exit(0));
	}
	while (str[i])
	{
		if (str[i] == '\n')
		{
			consecutive_newlines++;
			if (consecutive_newlines >= 2)
			{
				ft_printf("%s", "Error: more than 2 consecutives newlines.\n");
				return (free(str), exit(0));
			}
		}
		else
			consecutive_newlines = 0;
		i++;
	}
}

int	ft_check_if_rectangle(char **tab)
{
	if (ft_check_first_and_last_side(tab) == 1
		&& ft_check_last_line(tab) == 1
		&& ft_check_first_line(tab) == 1
		&& ft_check_equal_lenght(tab) == 1)
		return (1);
	else
	{
		ft_printf("%s", "Error: map is not rectangular\n");
		ft_free_tab(tab);
		exit(1);
	}
}
