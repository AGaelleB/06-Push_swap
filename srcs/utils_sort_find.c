/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_find.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 09:29:05 by abonnefo          #+#    #+#             */
/*   Updated: 2023/02/23 10:06:17 by abonnefo         ###   ########.fr       */
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

int	ft_find_closest_value(t_pile *pile)
{
	t_pile	*temp;
	int		closest_val;
	int		top_data_pile_a;

	closest_val = 0;
	top_data_pile_a = pile->pile_a->data;
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
