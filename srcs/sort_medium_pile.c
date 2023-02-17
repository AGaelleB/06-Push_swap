/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium_pile.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:42:41 by abonnefo          #+#    #+#             */
/*   Updated: 2023/02/17 13:36:02 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
je parcours toute la pile et je ressors le MAX et MIN
ex -500 et +100
ensuite je calcul le nbr d entier entre = 600
je divise se nbr par 5.
j ai 5 chunk de 120.

chunk 1 : -500 a - 380
chunk 2 : - 379 a -260
chunk 3 : - 259 a -140
chunk 4 : - 139 a -20
chunk 5 : - 19 a 100

ensuite je cherche les index etc. 
*/

void	ft_define_chunk(t_pile *pile)
{
	pile->min_pile = ft_find_min_value(pile->pile_a); // 1
	pile->max_pile = ft_find_max_value(pile->pile_a); // 19
	pile->min_chunk = pile->min_pile; // 1
	pile->nb_in_chunk = ((pile->max_pile - pile->min_pile) / 5); // de 3 en 3
	pile->max_chunk = pile->min_chunk + pile->nb_in_chunk; // 1 + 3 = 4
	
	ft_printf("min_pile = %d\n", pile->min_pile);
	ft_printf("max_pile = %d\n", pile->max_pile);
	ft_printf("nb_in_chunk = %d\n", pile->nb_in_chunk);
	ft_printf("\nmin_chunk = %d\n", pile->min_chunk);
	ft_printf("max_chunk = %d\n", pile->max_chunk);
}

int	ft_index_first(t_pile *pile) // OK
{
	t_pile	*temp;
	int		index_value;

	temp = pile->pile_a;
	index_value = 0;

	ft_printf("\n1er temp->data = %d\n", temp->data);
	ft_printf("1er temp->next->data = %d\n", temp->next->data);
	ft_printf("1er temp->next->next->data = %d\n", temp->next->next->data);
	ft_printf("1er temp->next->next->prev->data = %d\n", temp->next->next->prev->data);

	while ((pile->min_chunk + pile->nb_in_chunk) < pile->max_pile)
	{
		while (temp)
		{
			if (temp->data >= pile->min_chunk && temp->data <= pile->max_chunk)
			{
				index_value = temp->data;
				return (index_value);
			}
			temp = temp->next;
		}
		pile->min_chunk = pile->min_chunk + pile->nb_in_chunk;
		pile->max_chunk = pile->max_chunk + pile->nb_in_chunk;
	}
	return (index_value);
}

/*
imaginons que je stock dans ma pile_a la liste de nombre entré en ac. par exemple 12 13 64 1 5
jemet ensuite cette pile->pile_a->data sera = a 12.
maintenant je veux faire une fonction qui vaparcourir et imprimer avec un printf tous les elements de ma pile a en sens inverse et en utilisant une liste chainée simple.
*/

int	ft_index_second(t_pile *pile)
{
	t_pile *head = pile->pile_a; // pointeur vers le premier élément
	t_pile *temp = NULL; // pointeur temporaire
	int	index_value;

	index_value = 0;
	while (head && head->next)
		head = head->next;
	temp = head;

	ft_printf("\n1er head->data = %d\n", head->data); // afficher la dernière valeur
	ft_printf("1er temp->data = %d\n\n", temp->data); // afficher la dernière valeur

	while ((pile->min_chunk + pile->nb_in_chunk) < pile->max_pile)
	{
		while (temp)
		{
			if (temp->data >= pile->min_chunk && temp->data <= pile->max_chunk)
			{
				index_value = temp->data;
				return (index_value);
			}
			temp = temp->prev;
			
			if (temp != NULL)
				ft_printf("temp->prev = %d\n", temp->data);
			else 
				ft_printf("temp is NULL\n");

		}
		pile->min_chunk = pile->min_chunk + pile->nb_in_chunk;
		pile->max_chunk = pile->max_chunk + pile->nb_in_chunk;
		temp = head; // réinitialiser temp à la fin de la boucle interne
		// temp = pile->pile_a;
	}
	return (index_value);
}

void	ft_sort_medium_pile(t_pile *pile) // scanner A de H en B pour chunk 1
{
	ft_define_chunk(pile);
	ft_printf("\n%sft_index_first = %d%s\n", MAGENTA, ft_index_first(pile), RESET);
	// ft_printf("\n%sft_index_second = %d%s\n\n", MAGENTA, ft_index_second(pile), RESET);
}
