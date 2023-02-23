/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 09:21:43 by abonnefo          #+#    #+#             */
/*   Updated: 2023/02/23 09:24:41 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_data_index_last(t_pile *pile)
{
	t_pile	*last;
	int		index_value;

	last = pile->pile_a; // remplacer par la fonction lastcell

	index_value = 0;

	while (last->next)
		last = last->next;

	while ((pile->min_chunk + pile->nb_in_chunk) < pile->max_pile)
	{
		while (last)
		{
			if (last->data >= pile->min_chunk && last->data <= pile->max_chunk)
			{
				index_value = last->data;
				return (index_value);
			}
			last = last->prev;
		}
		pile->min_chunk = pile->min_chunk + pile->nb_in_chunk;
		pile->max_chunk = pile->max_chunk + pile->nb_in_chunk;
		last = pile->pile_a;
	}
	return (index_value);
}

int	ft_find_closest_value(t_pile *pile)
{
	t_pile	*temp;
	int		closest_val = 0;
	int top_data_pile_a = pile->pile_a->data;

	while (closest_val == 0)
	{
		temp = pile->pile_b;
		top_data_pile_a = top_data_pile_a - 1;
		while (temp)
		{
			if (top_data_pile_a == temp->data)
				closest_val = temp->data;
			temp = temp->next;
		}
	}
	return (closest_val);
}