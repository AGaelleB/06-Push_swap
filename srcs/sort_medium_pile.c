/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium_pile.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:42:41 by abonnefo          #+#    #+#             */
/*   Updated: 2023/02/20 15:02:21 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_define_chunk(t_pile *pile)
{
	pile->min_pile = ft_find_min_value(pile->pile_a);
	pile->max_pile = ft_find_max_value(pile->pile_a);
	pile->min_chunk = pile->min_pile;
	pile->nb_in_chunk = ((pile->max_pile - pile->min_pile) / 5);
	pile->max_chunk = pile->min_chunk + pile->nb_in_chunk;
	pile->mediane = pile->size_a / 2;

	ft_printf("min_pile = %d\n", pile->min_pile);
	ft_printf("max_pile = %d\n", pile->max_pile);
	ft_printf("nb_in_chunk = %d\n", pile->nb_in_chunk);
	ft_printf("\nmin_chunk = %d\n", pile->min_chunk);
	ft_printf("max_chunk = %d\n", pile->max_chunk);
	ft_printf("pile->size_a = %d\n", pile->size_a);
	ft_printf("pile->mediane = %d\n", pile->mediane);
}

int	ft_index_first(t_pile *pile) // OK
{
	t_pile	*temp;
	int		index_value;

	temp = pile->pile_a;
	index_value = 0;

	// ft_printf("\n1er temp->data = %d\n", temp->data);

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
	}
	return (index_value);
}

int	ft_index_last(t_pile *pile) // cherche la last valeure du chunck de B en H
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
	}
	return (index_value);
}

int	ft_pos_index_first(t_pile *pile, int data)
{
	t_pile	*temp;
	int	i;

	temp = pile->pile_a;
	i = 0;
	while (temp->data != data)
	{
		i++;
		temp = temp->next;
	}
	return(i);
}

int	ft_pos_index_last(t_pile *pile, int data)
{
	t_pile	*temp;
	int	i;

	temp = pile->pile_a;
	i = 0;
	while (temp->data != data)
	{
		i++;
		temp = temp->next;
	}
	return(i);
}


void	ft_move_medium_pile_a(t_pile *pile) // CHANTIER
{
	int	data_first;
	int	data_last;

	while (pile->pile_a)
	{
		data_first = ft_index_first(pile);
		data_last = ft_index_last(pile);
		if ((pile->size_a - ft_pos_index_last(pile, data_last)) < ft_pos_index_first(pile, data_first))
		{
			if (ft_pos_index_last(pile, data_last) > pile->mediane)
			{
				while (ft_pos_index_last(pile, data_last) != 0)
				{
					ft_reverse_rotate_a(pile);
					ft_print_piles(pile->pile_a, pile->pile_b); // A SUPPRIMER
				}
				ft_push_pile_a_to_b(pile);
				ft_print_piles(pile->pile_a, pile->pile_b); // A SUPPRIMER
			}
		}
		if ((pile->size_a - ft_pos_index_first(pile, data_first)) >= ft_pos_index_first(pile, data_first))
		{
			if (ft_pos_index_first(pile, data_first) <= pile->mediane)
			{
				while (ft_pos_index_first(pile, data_first) != 0)
				{
					ft_rotate_a(pile);
					ft_print_piles(pile->pile_a, pile->pile_b); // A SUPPRIMER
				}
				ft_push_pile_a_to_b(pile);
				ft_print_piles(pile->pile_a, pile->pile_b); // A SUPPRIMER
			}
		}
	}
}

void	ft_sort_medium_pile(t_pile *pile)
{
	ft_define_chunk(pile);
	ft_printf("\n%sft_index_first = %d%s\n", MAGENTA, ft_index_first(pile), RESET);
	ft_printf("%sft_index_last = %d%s\n\n", MAGENTA, ft_index_last(pile), RESET);

	// ft_printf("\n%sft_pos_index_first = %d%s\n", GREEN, ft_pos_index_first(pile, data_first), RESET);
	// ft_printf("%sft_pos_index_last = %d%s\n\n", GREEN, ft_pos_index_last(pile, data_last), RESET);

	ft_move_medium_pile_a(pile);
	
	ft_printf("\n%s***END SORT***%s\n", MAGENTA, RESET); // A SUPPRIMER
	ft_print_piles(pile->pile_a, pile->pile_b); // A SUPPRIMER
}
