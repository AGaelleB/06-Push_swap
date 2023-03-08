/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:06:46 by abonnefo          #+#    #+#             */
/*   Updated: 2023/03/08 17:41:35 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_move_last_medium_pile_a(t_pile *pile, int data_last)
{
	while (ft_pos_index_last(pile, data_last) != 0)
	{
		ft_reverse_rotate_a(pile);
		// ft_print_piles(pile->pile_a, pile->pile_b); // A SUPPRIMER
	}
	if (pile->pile_b == NULL)
	{
		ft_push_pile_a_to_b(pile);
		// ft_print_piles(pile->pile_a, pile->pile_b); // A SUPPRIMER
	}
	else
	{
		ft_move_medium_pile_b(pile);
		// ft_print_piles(pile->pile_a, pile->pile_b); // A SUPPRIMER
	}
}

void	ft_move_first_medium_pile_a(t_pile *pile, int data_first)
{
	while (ft_pos_idx_first(pile->pile_a, data_first) != 0)
		ft_rotate_a(pile);
	if (pile->pile_b == NULL)
		ft_push_pile_a_to_b(pile);
	else
		ft_move_medium_pile_b(pile);
}

void	ft_ra_or_rra_big_pile_b(t_pile *pile)
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

void	ft_move_last_big_pile_a(t_pile *pile, int data_last)
{
	while (ft_pos_index_last(pile, data_last) != 0)
	{
		ft_reverse_rotate_a(pile);
		// ft_print_piles(pile->pile_a, pile->pile_b); // A SUPPRIMER
	}
	if (pile->pile_b == NULL)
	{
		ft_push_pile_a_to_b(pile);
		// ft_print_piles(pile->pile_a, pile->pile_b); // A SUPPRIMER
	}
	else
	{
		ft_move_big_pile_b(pile);
		// ft_print_piles(pile->pile_a, pile->pile_b); // A SUPPRIMER
	}
}

void	ft_move_first_big_pile_a(t_pile *pile, int data_first)
{
	while (ft_pos_idx_first(pile->pile_a, data_first) != 0)
	{
		ft_rotate_a(pile);
		// ft_print_piles(pile->pile_a, pile->pile_b); // A SUPPRIMER
	}
	if (pile->pile_b == NULL)
		ft_push_pile_a_to_b(pile);
	else
		ft_move_big_pile_b(pile);
}
