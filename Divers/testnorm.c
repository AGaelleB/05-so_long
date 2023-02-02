/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testnorm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:49:38 by abonnefo          #+#    #+#             */
/*   Updated: 2023/01/17 10:09:59 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_check_map_and_duplicate(char **tab)
{
	char	**duplicated_tab;
	int		size_x;
	int		size_y;
	int		y;
	int		x;

	size_x = 0;
	size_y = 0;
	duplicated_tab = ft_tabdup(tab);
	if (duplicated_tab == NULL)
	{
		ft_free_tab(tab);
		return (NULL);
	}
	while (duplicated_tab[size_y])
		size_y++;
	while (duplicated_tab[0][size_x])
		size_x++;
	y = ft_search_perso_y(size_y, size_x, 'P', tab);
	x = ft_search_perso_x(size_y, size_x, 'P', tab);
	ft_map_replace_e(duplicated_tab, y, x);
	ft_search_and_replace(duplicated_tab, y, x);
	ft_check_ultimate_path(duplicated_tab);
	ft_free_tab(duplicated_tab);
	ft_free_tab(tab);
}

char	**ft_put_in_tab(char *map)
{
	char	**tab;
	char	*s1;

	s1 = ft_read_and_join(map);
	ft_check_backslash(s1);
	tab = ft_split(s1, '\n');
	if (tab == NULL)
		return (NULL);
	free(s1);
	ft_check_if_rectangle(tab);
	ft_check_items(tab);
	ft_check_map_and_duplicate(tab);
	if (ft_check_map_and_duplicate == NULL)
		ft_free_tab(tab);
	return (tab);
}
