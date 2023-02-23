/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 09:21:43 by abonnefo          #+#    #+#             */
/*   Updated: 2023/02/23 17:16:31 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	chose_chunks(int size) //NEW
{
	int	chunk;

	if (size <= 10)
		chunk = 2;
	else if (size <= 150)
		chunk = 4;
	else
		chunk = 10;
	return (chunk);
}

// int	chose_chunks(int size) //faire un truc genre si multiple de 3 alors bucket de x, si multiple de 5 alors bucket de x etc
// {
// 	int	chunk;

// if (size <= 10)


// }


void	ft_define_chunk_medium(t_pile *pile) // < 100 segfault aux 3 dernieres valeures
{
	pile->min_pile_a = ft_find_min_value(pile->pile_a);
	pile->max_pile_a = ft_find_max_value(pile->pile_a);
	pile->min_chunk = pile->min_pile_a;
	// pile->size_of_chunk = ((pile->max_pile_a - pile->min_pile_a) / 10);
	pile->size_of_chunk = ((ft_lst_size(pile->pile_a)) / chose_chunks(ft_lst_size(pile->pile_a)));
	pile->max_chunk = pile->min_chunk + pile->size_of_chunk + pile->size_of_chunk;
	// pile->max_chunk = pile->min_chunk + pile->size_of_chunk + pile->size_of_chunk ;
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
	pile->min_chunk = pile->min_pile_a;
	// pile->size_of_chunk = ((pile->max_pile_a - pile->min_pile_a) / 10);
	pile->size_of_chunk = ((ft_lst_size(pile->pile_a)) / chose_chunks(ft_lst_size(pile->pile_a)));
	pile->max_chunk = pile->min_chunk + pile->size_of_chunk + pile->size_of_chunk;
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
	while ((pile->min_chunk + pile->size_of_chunk) < pile->max_pile_a)
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
	while ((pile->min_chunk + pile->size_of_chunk) < pile->max_pile_a)
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
	}
	return (index_value);
}
