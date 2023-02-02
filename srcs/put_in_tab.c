/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:24:34 by abonnefo          #+#    #+#             */
/*   Updated: 2023/02/01 15:47:43 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**ft_tabdup(char **tab)
{
	int		i;
	char	**dup;

	i = 0;
	while (tab[i])
		i++;
	dup = (char **)malloc (sizeof(char *) * (i + 1));
	i = 0;
	while (tab[i])
	{
		dup[i] = ft_strdup(tab[i]);
		i++;
	}
	dup[i] = 0;
	return (dup);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

char	*ft_read_and_join(char *map)
{
	char	*s1;
	char	*s2;
	char	*temp;
	int		fd;

	fd = open(map, O_RDWR);
	if (fd <= 0)
	{
		ft_printf("Error : Invalid read\n");
		return (NULL);
	}
	s1 = ft_calloc(sizeof(char), 1);
	if (s1 == NULL)
		return (NULL);
	s2 = get_next_line(fd);
	while (s2)
	{
		temp = s1;
		s1 = ft_strjoin(temp, s2);
		free(temp);
		free(s2);
		s2 = get_next_line(fd);
	}
	close(fd);
	return (s1);
}

char	*ft_check_map_and_duplicate(char **tab)
{
	t_data	data;
	char	**duplicated_tab;
	int		y;
	int		x;

	data.size_x = ft_count_width(tab);
	data.size_y = ft_count_height(tab);
	duplicated_tab = ft_tabdup(tab);
	if (duplicated_tab == NULL)
	{
		ft_free_tab(tab);
		return (NULL);
	}
	y = ft_search_perso_y(data.size_y, data.size_x, 'P', tab);
	x = ft_search_perso_x(data.size_y, data.size_x, 'P', tab);
	ft_map_replace_e(duplicated_tab, y, x);
	ft_search_and_replace(duplicated_tab, y, x);
	if (ft_check_ultimate_path(duplicated_tab) == 0)
	{
		ft_free_tab(duplicated_tab);
		ft_free_tab(tab);
		exit (1);
	}
	ft_free_tab(duplicated_tab);
	return (NULL);
}

char	**ft_put_in_tab(char *map)
{
	char	**tab;
	char	*s1;

	s1 = ft_read_and_join(map);
	if (s1 == NULL)
		exit(1);
	ft_check_backslash(s1);
	tab = ft_split(s1, '\n');
	if (tab == NULL)
		return (NULL);
	free(s1);
	ft_check_if_rectangle(tab);
	ft_check_items(tab);
	ft_check_map_and_duplicate(tab);
	return (tab);
}
