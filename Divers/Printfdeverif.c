/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Printfdeverif.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:56:20 by abonnefo          #+#    #+#             */
/*   Updated: 2023/01/24 09:18:03 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


void	printf_FINAL_check(char **tab) // SERA A SUPPRIMER
{
	int i;
	i = 0;
	
	printf("\nmap initiale : \n\n");

	while(tab[i])
	{
		printf("%s \n", tab[i]);
		i++;
	}
	printf("\n");
}


void	printf_FINAL_path(char **tab) // SERA A SUPPRIMER
{
	int i = 0;
	printf("map apres verif : \n\n");
	while(tab[i])
	{
		printf("%s \n", tab[i]);
		i++;
	}
}
