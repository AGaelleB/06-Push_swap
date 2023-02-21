/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_pile.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:59:50 by abonnefo          #+#    #+#             */
/*   Updated: 2023/02/21 10:33:11 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_find_max_value(t_pile *pile)
{
	t_pile	*temp;
	int		max;

	temp = pile->next;
	max = ft_first_cell(pile);
	while (temp)
	{
		if (temp->data > max)
			max = temp->data;
		temp = temp->next;
	}
	return (max);
}

int	ft_find_min_value(t_pile *pile)
{
	t_pile	*temp;
	int		min;

	temp = pile->next;
	min = ft_first_cell(pile);
	while (temp)
	{
		if (temp->data < min)
			min = temp->data;
		temp = temp->next;
	}
	return (min);
}

void	ft_ra_or_rra(t_pile *pile)
{
	int	smallest;
	int	i;

	i = 5 - pile->size_a;
	while (i < 2)
	{
		smallest = ft_find_min_value(pile->pile_a);
		if (ft_first_cell(pile->pile_a) != smallest)
		{
			if (ft_pos_index_first(pile, smallest) > pile->mediane)
				ft_rotate_a(pile);
			else if (ft_pos_index_first(pile, smallest) <= pile->mediane)
				ft_reverse_rotate_a(pile);
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
	ft_ra_or_rra(pile);
	if (pile->size_a >= 2 && pile->pile_a->data > pile->pile_a->next->data)
		ft_swap_pile_a(pile);
	if (pile->size_a > 3 && pile->pile_a->data > ft_last_cell_a(pile))
		ft_reverse_rotate_a(pile);
	if (pile->size_a > 2 && pile->pile_a->next->data > ft_last_cell_a(pile))
		ft_reverse_rotate_a(pile);
	if (pile->size_a > 2 && pile->pile_a->data > pile->pile_a->next->data)
		ft_swap_pile_a(pile);
	while (pile->pile_b != NULL)
		ft_push_pile_b_to_a(pile);
}
