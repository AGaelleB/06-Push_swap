/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:59:41 by abonnefo          #+#    #+#             */
/*   Updated: 2023/02/09 10:59:54 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_pile	*ft_create_cell(long data) // OK MODIFIE
{
	t_pile	*cell;

	cell = malloc(sizeof(t_pile));
	if (!cell)
		return (0);
	cell->data = data;
	cell->next = NULL;
	// cell->prev = NULL; // NEW
	return (cell);
}

t_pile	*ft_add_pos(t_pile *list, long data, int pos) // OK MODIFIE
{
	t_pile	*previous_pos;
	t_pile	*position;
	t_pile	*cell;
	int		i;

	previous_pos = list;
	position = list;
	cell = ft_create_cell(data);
	i = 0;
	if (ft_is_empty_list(list))
		return (cell);
	if (pos == 0)
	{
		cell->next = list;
		// list->prev = cell; // NEW

		return (cell);
	}
	while (i < pos)
	{
		i++;
		previous_pos = position;
		position = position-> next;
	}
	previous_pos->next = cell;
	cell->next = position;
	cell->prev = previous_pos; // NEW ICIIIIIIIIIIIIIIIIIIIIIIII
	// position->prev = cell; // NEW SEGFAULT
	return (list);
}

int	ft_lst_size(t_pile *pile) // OK MODIFIE
{
	int	i;

	i = 0;
	while (pile)
	{
		pile = pile->next;
		i++;
	}
	// while (pile && pile->prev) // NEW
	// {
	// 	pile = pile->prev; // NEW
	// 	i++; // NEW
	// }
	
	return (i);
}

void	ft_init_struct(t_pile *pile) // OK MODIFIE
{
	pile->size_a = ft_lst_size(pile->pile_a);
	pile->size_b = ft_lst_size(pile->pile_b);
	// if (pile->pile_a) // NEW
	// 	pile->pile_a->prev = NULL; // NEW
	// if (pile->pile_b) // NEW
	// 	pile->pile_b->prev = NULL; // NEW
}
