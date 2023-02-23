/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 09:21:43 by abonnefo          #+#    #+#             */
/*   Updated: 2023/02/23 11:26:33 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_define_chunk_medium(t_pile *pile)
{
	pile->min_pile_a = ft_find_min_value(pile->pile_a);
	pile->max_pile = ft_find_max_value(pile->pile_a);
	pile->min_chunk = pile->min_pile_a;
	pile->nb_in_chunk = ((pile->max_pile - pile->min_pile_a) / 5);
	pile->max_chunk = pile->min_chunk + pile->nb_in_chunk + pile->nb_in_chunk ;
	pile->mediane_a = pile->size_a / 2;
	pile->size_b = ft_lst_size(pile->pile_b);
	pile->mediane_b = pile->size_b / 2;
}

void	ft_define_chunk_big(t_pile *pile)
{
	pile->min_pile_a = ft_find_min_value(pile->pile_a);
	pile->max_pile = ft_find_max_value(pile->pile_a);
	pile->min_chunk = pile->min_pile_a;
	pile->nb_in_chunk = ((pile->max_pile - pile->min_pile_a) / 10);
	pile->max_chunk = pile->min_chunk + pile->nb_in_chunk + pile->nb_in_chunk ;
	pile->mediane_a = pile->size_a / 2;
	pile->size_b = ft_lst_size(pile->pile_b);
	pile->mediane_b = pile->size_b / 2;
}

int	ft_data_index_first(t_pile *pile)
{
	t_pile	*temp;
	int		index_value;

	temp = pile->pile_a;
	index_value = 0;
	while ((pile->min_chunk + pile->nb_in_chunk) < pile->max_pile)
	{
		while (temp)
		{
			if (temp->data >= pile->min_chunk && temp->data <= pile->max_chunk)
			{
				index_value = temp->data;
				return (index_value);
			}
			temp = temp->next;
		}
		pile->min_chunk = pile->min_chunk + pile->nb_in_chunk;
		pile->max_chunk = pile->max_chunk + pile->nb_in_chunk;
		temp = pile->pile_a;
	}
	return (index_value);
}

int	ft_data_index_last(t_pile *pile)
{
	t_pile	*last;
	int		index_value;

	last = pile->pile_a;
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
