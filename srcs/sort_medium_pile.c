/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium_pile.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:42:41 by abonnefo          #+#    #+#             */
/*   Updated: 2023/02/23 09:25:37 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_define_chunk(t_pile *pile)
{
	pile->min_pile_a = ft_find_min_value(pile->pile_a);
	pile->max_pile = ft_find_max_value(pile->pile_a);
	pile->min_chunk = pile->min_pile_a;
	pile->nb_in_chunk = ((pile->max_pile - pile->min_pile_a) / 13); // tester les chunks
	pile->max_chunk = pile->min_chunk + pile->nb_in_chunk + pile->nb_in_chunk ;
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
		temp = pile->pile_a;
	}
	return (index_value);
}

void	ft_move_medium_pile_b(t_pile *pile)
{
	int		highest_in_b;
	int		smallest_in_b;
	int		closest_in_b;
	
	highest_in_b = ft_find_max_value(pile->pile_b);
	smallest_in_b = ft_find_min_value(pile->pile_b);

	pile->size_b = ft_lst_size(pile->pile_b);
	if (pile->size_b > 2)
		pile->mediane_b = pile->size_b / 2; // a bouger ensuite dans le define

	if (ft_first_cell(pile->pile_a) >= highest_in_b)
	{
		while (ft_first_cell(pile->pile_b) != highest_in_b)
		{
			if (pile->mediane_b >= ft_pos_index_first(pile->pile_b, highest_in_b))
				ft_rotate_b(pile);
			else
				ft_reverse_rotate_b(pile);
		}
	}
	else if (ft_first_cell(pile->pile_a) < smallest_in_b)
	{
		while (ft_first_cell(pile->pile_b) != highest_in_b)
		{
			if (pile->mediane_b >= ft_pos_index_first(pile->pile_b, highest_in_b))
				ft_rotate_b(pile);
			else
				ft_reverse_rotate_b(pile);
		}
	}
	else if (ft_first_cell(pile->pile_a) > smallest_in_b
		&& ft_first_cell(pile->pile_a) < highest_in_b)
	{
		closest_in_b = ft_find_closest_value(pile);
		// printf ("closest_in_b = %d\n", closest_in_b);
		while (ft_first_cell(pile->pile_b) != closest_in_b)
		{
			if (pile->mediane_b >= ft_pos_index_first(pile->pile_b, closest_in_b))
				ft_rotate_b(pile);
			else
				ft_reverse_rotate_b(pile);
		}
	}
	ft_push_pile_a_to_b(pile);
}


void	ft_move_medium_pile_a(t_pile *pile)
{
	int	data_first;
	int	data_last;

	while (pile->pile_a)
	{
		data_first = ft_data_index_first(pile);
		data_last = ft_data_index_last(pile);
		pile->mediane_a = pile->size_a / 2;
		if ((pile->size_a - ft_pos_index_last(pile, data_last)) < ft_pos_index_first(pile->pile_a, data_first))
		{
			while (ft_pos_index_last(pile, data_last) != 0)
			{
				ft_reverse_rotate_a(pile);
				// ft_print_piles(pile->pile_a, pile->pile_b); // A SUPPRIMER
			}
			if (pile->pile_b == NULL)
				ft_push_pile_a_to_b(pile);
			else
				ft_move_medium_pile_b(pile);
			// ft_print_piles(pile->pile_a, pile->pile_b); // A SUPPRIMER
		}
		else if ((pile->size_a - ft_pos_index_first(pile->pile_a, data_first)) >= ft_pos_index_first(pile->pile_a, data_first))
		{
			while (ft_pos_index_first(pile->pile_a, data_first) != 0)
			{
				ft_rotate_a(pile);
				// ft_print_piles(pile->pile_a, pile->pile_b); // A SUPPRIMER
			}
			if (pile->pile_b == NULL)
				ft_push_pile_a_to_b(pile);
			else
				ft_move_medium_pile_b(pile);
			// ft_print_piles(pile->pile_a, pile->pile_b); // A SUPPRIMER
		}
		if (pile->pile_a->next == NULL)
		{
			ft_move_medium_pile_b(pile);
			// ft_print_piles(pile->pile_a, pile->pile_b); // A SUPPRIMER
		}
	}
	while (ft_first_cell(pile->pile_b) != ft_find_max_value(pile->pile_b))
	{
		ft_rotate_b(pile);
	}
	while (pile->pile_b != NULL)
		ft_push_pile_b_to_a(pile);
}

void	ft_sort_medium_pile(t_pile *pile)
{
	ft_define_chunk(pile);
	ft_move_medium_pile_a(pile);
}
