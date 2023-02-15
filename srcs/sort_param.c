/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:59:50 by abonnefo          #+#    #+#             */
/*   Updated: 2023/02/15 17:27:39 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_find_smallest(t_pile *pile)
{
	t_pile	*temp;
	int		smallest;

	temp = pile->next;
	smallest = ft_first_cell(pile);
	while (temp)
	{
		if (temp->data < smallest)
			smallest = temp->data;
		temp = temp->next;
	}
	return (smallest);
}

void	ft_sort_small_pile(t_pile *pile)
{
	int	smallest;
	int	size;
	int	i;

	size = ft_lst_size(pile->pile_a);
	i = 5 - size;
	while (i < 2)
	{
		smallest = ft_find_smallest(pile->pile_a);
		if (ft_first_cell(pile->pile_a) != smallest)
			ft_reverse_rotate_a(pile);
		else
		{
			ft_push_pile_a_to_b(pile);
			i++;
		}
	}
	if (size > 2 && pile->pile_a->data > pile->pile_a->next->data)
		ft_swap_pile_a(pile);
	if (size > 3 && pile->pile_a->data > pile->pile_a->next->next->data)
		ft_reverse_rotate_a(pile);
	if (size > 2 && pile->pile_a->next->data > pile->pile_a->next->next->data)
		ft_reverse_rotate_a(pile);
	if (size > 2 && pile->pile_a->data > pile->pile_a->next->data)
		ft_swap_pile_a(pile);
	while (pile->pile_b != NULL)
		ft_push_pile_b_to_a(pile);

	ft_printf("\n%s***END SORT***%s\n", MAGENTA, RESET);
	print_piles(pile->pile_a, pile->pile_b);
}
