/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_pile.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:59:50 by abonnefo          #+#    #+#             */
/*   Updated: 2023/02/23 13:53:10 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_ra_or_rra_small_pile(t_pile *pile)
{
	int	i;
	int	smallest;

	i = 5 - pile->size_a;
	pile->mediane_a = pile->size_a / 2;
	while (i >= 0 && i < 2)
	{
		smallest = ft_find_min_value(pile->pile_a);
		if (ft_first_cell(pile->pile_a) != smallest)
		{
			if (ft_pos_idx_first(pile->pile_a, smallest) > pile->mediane_a)
				ft_reverse_rotate_a(pile);
			else
				ft_rotate_a(pile);
		}
		else
		{
			ft_push_pile_a_to_b(pile);
			i++;
		}
	}
}

void	ft_sort_small_pile(t_pile *pile)
{
	ft_ra_or_rra_small_pile(pile);
	if (pile->size_a >= 2 && pile->pile_a->data > pile->pile_a->next->data)
		ft_swap_pile_a(pile);
	if (pile->size_a >= 4 && pile->pile_a->data > ft_last_cell_a(pile))
		ft_reverse_rotate_a(pile);
	if (pile->size_a >= 3 && pile->pile_a->next->data > ft_last_cell_a(pile))
		ft_reverse_rotate_a(pile);
	if (pile->size_a >= 3 && pile->pile_a->data > pile->pile_a->next->data)
		ft_swap_pile_a(pile);
	while (pile->pile_b != NULL)
		ft_push_pile_b_to_a(pile);
}
