/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 09:21:43 by abonnefo          #+#    #+#             */
/*   Updated: 2023/03/08 15:23:23 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	chose_nb_of_chunks(int size)
{
	int	nb_of_chunks;

	if (size <= 10)
		nb_of_chunks = 2;
	else if (size <= 100)
		nb_of_chunks = 4;
	else if (size <= 250)
		nb_of_chunks = 8;
	else
		nb_of_chunks = 11;
	return (nb_of_chunks);
}

void	ft_define_chunk_medium(t_pile *pile) // > 5 et < 100
{
	pile->min_pile_a = ft_find_min_value(pile->pile_a);
	pile->max_pile_a = ft_find_max_value(pile->pile_a);
	pile->size_of_chunk = ((ft_lst_size(pile->pile_a)) / chose_nb_of_chunks(ft_lst_size(pile->pile_a)));
	pile->min_chunk = pile->min_pile_a;
	pile->max_chunk = pile->min_chunk + pile->size_of_chunk;
	pile->mediane_a = pile->size_a / 2;
	pile->size_b = ft_lst_size(pile->pile_b);
	pile->mediane_b = pile->size_b / 2;

	// printf("\npile->min_pile_a = %d\n", pile->min_pile_a); // A SUPPRIMER
	// printf("pile->max_pile_a = %d\n\n", pile->max_pile_a); // A SUPPRIMER
	// printf("chose_nb_of_chunks = %d\n", chose_nb_of_chunks(ft_lst_size(pile->pile_a))); // A SUPPRIMER
	// printf("pile->size_of_chunk = %d\n\n", pile->size_of_chunk); // A SUPPRIMER
	// printf("pile->min_chunk = %d\n", pile->min_chunk); // A SUPPRIMER
	// printf("pile->max_chunk = %d\n\n", pile->max_chunk); // A SUPPRIMER
}

void	ft_define_chunk_big(t_pile *pile) // > 100 et < 500
{
	pile->min_pile_a = ft_find_min_value(pile->pile_a);
	pile->max_pile_a = ft_find_max_value(pile->pile_a);
	// pile->size_of_chunk = ((ft_lst_size(pile->pile_a)) / 11);
	pile->size_of_chunk = ((ft_lst_size(pile->pile_a)) / chose_nb_of_chunks(ft_lst_size(pile->pile_a)));
	pile->min_chunk = pile->min_pile_a;
	pile->max_chunk = pile->min_chunk + pile->size_of_chunk;
	// pile->max_chunk = pile->min_chunk + pile->size_of_chunk + pile->size_of_chunk ;
	pile->mediane_a = pile->size_a / 2;
	pile->size_b = ft_lst_size(pile->pile_b);
	pile->mediane_b = pile->size_b / 2;
}

// void	ft_next_chunk(t_pile *pile)
// {
// 	pile->min_chunk += pile->size_of_chunk;
// 	pile->max_chunk += pile->size_of_chunk;
// }

int	ft_data_index_first(t_pile *pile)
{
	t_pile	*temp;
	int		index_value;

	temp = pile->pile_a;
	index_value = 0;
	while (pile->max_pile_a)
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
		// if (pile->max_chunk < (pile->max_pile_a + pile->size_of_chunk))
		// {
			pile->min_chunk = pile->min_chunk + pile->size_of_chunk;
			pile->max_chunk = pile->max_chunk + pile->size_of_chunk;
			// printf("	IDX FIRST pile->min_chunk = %d\n", pile->min_chunk); // A SUPPRIMER
			// printf("	IDX FIRST pile->max_chunk = %d\n\n", pile->max_chunk); // A SUPPRIMER
		// }
		temp = pile->pile_a;
	}
	return (-1); //index_value
}

int	ft_data_index_last(t_pile *pile)
{
	t_pile	*last;
	t_pile	*temp;

	int		index_value;

	// last = pile->pile_a;
	index_value = 0;
	// while (last->next)
	// 	last = last->next;
	while (pile->max_pile_a)
	{
		last = pile->pile_a;
		temp = pile->pile_a;
		while (last->next)////NEW ?
			last = last->next;///NEW ?
		while (temp)
		{
			if (last->data >= pile->min_chunk && last->data <= pile->max_chunk)
			{
				index_value = last->data;
				return (index_value);
			}
			last = last->prev;
			temp = temp->next;
		}
		
		// if (pile->max_chunk < (pile->max_pile_a + pile->size_of_chunk))
		// {
			pile->min_chunk = pile->min_chunk + pile->size_of_chunk;
			pile->max_chunk = pile->max_chunk + pile->size_of_chunk;
			// printf("	IDX LAST pile->min_chunk = %d\n", pile->min_chunk); // A SUPPRIMER
			// printf("	IDX LAST pile->max_chunk = %d\n\n", pile->max_chunk); // A SUPPRIMER
		// }
	}
	return (-1); //index_value
}
