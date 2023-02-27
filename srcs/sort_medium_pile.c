/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium_pile.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:42:41 by abonnefo          #+#    #+#             */
/*   Updated: 2023/02/27 11:30:55 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_ra_or_rra_medium_pile_b(t_pile *pile)
{
	int	highest_in_b;

	pile->size_b = ft_lst_size(pile->pile_b);
	if (pile->size_b > 2)
		pile->mediane_b = pile->size_b / 2;
	highest_in_b = ft_find_max_value(pile->pile_b);
	while (ft_first_cell(pile->pile_b) != highest_in_b)
	{
		if (pile->mediane_b >= ft_pos_idx_first(pile->pile_b, highest_in_b))
			ft_rotate_b(pile);
		else
			ft_reverse_rotate_b(pile);
	}
}

void	ft_move_medium_pile_b(t_pile *pile)
{
	int		highest_in_b;
	int		smallest_in_b;
	int		closest_in_b;

	highest_in_b = ft_find_max_value(pile->pile_b);
	smallest_in_b = ft_find_min_value(pile->pile_b);
	pile->size_b = ft_lst_size(pile->pile_b);
	pile->mediane_b = pile->size_b / 2;
	if (ft_first_cell(pile->pile_a) >= highest_in_b)
		ft_ra_or_rra_medium_pile_b(pile);
	else if (ft_first_cell(pile->pile_a) < smallest_in_b)
		ft_ra_or_rra_medium_pile_b(pile);
	else if (ft_first_cell(pile->pile_a) > smallest_in_b
		&& ft_first_cell(pile->pile_a) < highest_in_b)
	{
		closest_in_b = ft_find_closest_value(pile);
		while (ft_first_cell(pile->pile_b) != closest_in_b)
		{
			if (pile->mediane_b >= ft_pos_idx_first(pile->pile_b, closest_in_b))
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
		if ((pile->size_a - ft_pos_index_last(pile, data_last))
			< ft_pos_idx_first(pile->pile_a, data_first))
				ft_move_last_medium_pile_a(pile, data_last);
		else if ((pile->size_a - ft_pos_idx_first(pile->pile_a, data_first))
			>= ft_pos_idx_first(pile->pile_a, data_first))
				ft_move_first_medium_pile_a(pile, data_first);
		if (pile->pile_a->next == NULL)
			ft_move_medium_pile_b(pile);
	}
	while (ft_first_cell(pile->pile_b) != ft_find_max_value(pile->pile_b))
		ft_reverse_rotate_b(pile);
	while (pile->pile_b != NULL)
		ft_push_pile_b_to_a(pile);
}

void	ft_sort_medium_pile(t_pile *pile)
{
	ft_define_chunk_medium(pile);
	ft_move_medium_pile_a(pile);
}
