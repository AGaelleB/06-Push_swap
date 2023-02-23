/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_pile.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:59:50 by abonnefo          #+#    #+#             */
/*   Updated: 2023/02/23 12:09:16 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
