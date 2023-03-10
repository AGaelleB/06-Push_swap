/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 09:23:32 by abonnefo          #+#    #+#             */
/*   Updated: 2023/03/10 11:11:53 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_pos_idx_first(t_pile *pile, int data)
{
	t_pile	*temp;
	int		i;

	temp = pile;
	i = 0;
	while (temp->data != data)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

int	ft_pos_index_last(t_pile *pile, int data)
{
	t_pile	*temp;
	int		i;

	temp = pile->pile_a;
	i = 0;
	while (temp->data != data)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}
