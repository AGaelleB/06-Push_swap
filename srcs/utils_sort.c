/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 09:21:43 by abonnefo          #+#    #+#             */
/*   Updated: 2023/02/27 15:00:33 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// int	chose_chunks(int size) //NEW
// {
// 	int	chunk;

// 	if (size <= 10)
// 		chunk = 2;
// 	else if (size <= 50)
// 		chunk = 4;
// 		else if (size <= 100)
// 		chunk = 8;
// 	else
// 		chunk = 10;
// 	return (chunk);
// }

// int	chose_chunks(int size) //NEW
// {
// 	int	chunk;
// 	int modulo;

// 	modulo = size % 10;
// 	if (size <= 10)
// 		chunk = 2;
// 	else if (size % 10 == 0)
// 		chunk = 10;
// 	else if ((modulo * 2) >= 5)
// 		chunk = modulo;
// 	else
// 		chunk = modulo * 2;
// 	// printf("\nmodulo = %d\n", modulo);
// 	// printf("\nchunk = %d\n", chunk);
// 	return (chunk);
// }

/*
comme ca je valide 
les 5 en moins de 11 operations - sur 1000 tests
les 100 en moins de 852 operations - sur 1000 tests -UPDaTE j ai eu 1segfault sur 1000 tests, il semble que ca arrive 
au moment des pb
voici une suite a erreur :

12 83 56 41 91 19 74 100 43 42 97 57 80 86 69 55 84 4 47 29 99 37 73 21 76 22 62 60 7 70 75 67 63 32 59 96 16 10 51 50 26 82 78 2 61 39 18 98 71 48 30 38 89 54 87 40 88 15 46 5 9 85 20 28 17 68 31 34 13 53 64 90 33 11 1 79 24 45 66 6 93 27 44 72 36 92 14 25 81 65 58 95 52 49 3 23 8 94 35 77]

les 5 jai des segfaults 

*/

void	ft_define_chunk_medium(t_pile *pile) // < 100 segfault aux 3 dernieres valeures
{
	pile->min_pile_a = ft_find_min_value(pile->pile_a);
	pile->max_pile_a = ft_find_max_value(pile->pile_a);
	pile->size_of_chunk = ((ft_lst_size(pile->pile_a)) / 5);
	// pile->size_of_chunk = ((ft_lst_size(pile->pile_a)) / chose_chunks(ft_lst_size(pile->pile_a)));
	pile->min_chunk = pile->min_pile_a;
	pile->max_chunk = pile->min_chunk + pile->size_of_chunk; // nope
	pile->mediane_a = pile->size_a / 2;
	pile->size_b = ft_lst_size(pile->pile_b);
	pile->mediane_b = pile->size_b / 2;

	// printf("\npile->min_pile_a = %d\n", pile->min_pile_a);
	// printf("pile->max_pile_a = %d\n\n", pile->max_pile_a);
	// printf("\npile->size_of_chunk = %d\n\n", pile->size_of_chunk);
	// printf("chose_chunks(ft_lst_size(pile->pile_a)) = %d\n\n", chose_chunks(ft_lst_size(pile->pile_a)));
	// printf("pile->min_chunk = %d\n", pile->min_chunk);
	// printf("pile->max_chunk = %d\n\n", pile->max_chunk);
}

void	ft_define_chunk_big(t_pile *pile)
{
	pile->min_pile_a = ft_find_min_value(pile->pile_a);
	pile->max_pile_a = ft_find_max_value(pile->pile_a);
	pile->size_of_chunk = ((ft_lst_size(pile->pile_a)) / 11);
	// pile->size_of_chunk = ((ft_lst_size(pile->pile_a)) / chose_chunks(ft_lst_size(pile->pile_a)));
	pile->min_chunk = pile->min_pile_a;
	pile->max_chunk = pile->min_chunk + pile->size_of_chunk;
	// pile->max_chunk = pile->min_chunk + pile->size_of_chunk + pile->size_of_chunk ;
	pile->mediane_a = pile->size_a / 2;
	pile->size_b = ft_lst_size(pile->pile_b);
	pile->mediane_b = pile->size_b / 2;
}

int	ft_data_index_first(t_pile *pile)
{
	t_pile	*temp;
	int		index_value;

	temp = pile->pile_a;
	index_value = 0;
	while (pile->max_pile_a) //((pile->min_chunk + pile->size_of_chunk) < pile->max_pile_a)
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
		pile->min_chunk = pile->min_chunk + pile->size_of_chunk;
		pile->max_chunk = pile->max_chunk + pile->size_of_chunk;
		temp = pile->pile_a;
		
	// 	if (temp->next == NULL)
	// 	{
	// 		pile->min_chunk = pile->min_chunk + pile->size_of_chunk;
	// 		pile->max_chunk = pile->max_chunk + pile->size_of_chunk + pile->size_of_chunk;
	// 		temp = pile->pile_a;
	// 	}
	// 	else
	// 	{
	// 		pile->min_chunk = pile->min_chunk + pile->size_of_chunk;
	// 		pile->max_chunk = pile->max_chunk + pile->size_of_chunk;
	// 		temp = pile->pile_a;
	// 	}
	}
	return (index_value);
}

int	ft_data_index_last(t_pile *pile)
{
	t_pile	*last;
	int		index_value;

	last = pile->pile_a;
	index_value = 0;
	while (last->next)
		last = last->next;
	while (pile->max_pile_a) //((pile->min_chunk + pile->size_of_chunk) < pile->max_pile_a)
	{
		while (last)
		{
			if (last->data >= pile->min_chunk && last->data <= pile->max_chunk)
			{
				index_value = last->data;
				return (index_value);
			}
			last = last->prev;
		}
		pile->min_chunk = pile->min_chunk + pile->size_of_chunk;
		pile->max_chunk = pile->max_chunk + pile->size_of_chunk;
		last = pile->pile_a;
		
		// if (last->next == NULL)
		// {
		// 	pile->min_chunk = pile->min_chunk + pile->size_of_chunk;
		// 	pile->max_chunk = pile->max_chunk + pile->size_of_chunk + pile->size_of_chunk;
		// 	last = pile->pile_a;
		// }
		// else
		// {
		// 	pile->min_chunk = pile->min_chunk + pile->size_of_chunk;
		// 	pile->max_chunk = pile->max_chunk + pile->size_of_chunk;
		// 	last = pile->pile_a;
		// }
	}
	return (index_value);
}
