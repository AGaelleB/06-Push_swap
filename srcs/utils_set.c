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

t_pile	*ft_create_cell(long data)
{
	t_pile	*cell;

	cell = malloc(sizeof(t_pile));
	if (!cell)
		return (0);
	cell->data = data;
	cell->next = NULL;
	cell->prev = NULL; //je garde ? 
	return (cell);
}

t_pile	*ft_add_pos(t_pile *list, long data, int pos)
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
		return (cell->next = list, cell); // ici dans return
	while (i < pos)
	{
		i++;
		previous_pos = position;
		position = position-> next;
	}
	previous_pos->next = cell;
	cell->next = position;
	cell->prev = previous_pos;
	return (list);
}

int	ft_lst_size(t_pile *pile)
{
	int	i;

	i = 0;
	while (pile)
	{
		pile = pile->next;
		i++;
	}
	return (i);
}

void	ft_init_struct(t_pile *pile)
{
	pile->size_a = ft_lst_size(pile->pile_a);
	pile->size_b = ft_lst_size(pile->pile_b);
}
