/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium_pile.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:42:41 by abonnefo          #+#    #+#             */
/*   Updated: 2023/02/18 23:23:02 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_define_chunk(t_pile *pile)
{
	pile->min_pile = ft_find_min_value(pile->pile_a); // 1
	pile->max_pile = ft_find_max_value(pile->pile_a); // 19
	pile->min_chunk = pile->min_pile; // 1
	pile->nb_in_chunk = ((pile->max_pile - pile->min_pile) / 5); // de 3 en 3
	pile->max_chunk = pile->min_chunk + pile->nb_in_chunk; // 1 + 3 = 4
	pile->mediane = pile->size_a / 2; // a verifier

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

	ft_printf("\n1er temp->data = %d\n", temp->data);

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

int	ft_index_second(t_pile *pile)
{
	t_pile	*temp;
	t_pile	*last;
	int		index_value;

	temp = pile->pile_a;
	index_value = 0;

	while (last && last->next)
		last = last->next;
	temp = last;

	ft_printf("\n1er temp->data = %d\n", temp->data);

	while ((pile->min_chunk + pile->nb_in_chunk) < pile->max_pile)
	{
		while (temp)
		{
			if (temp->data >= pile->min_chunk && temp->data <= pile->max_chunk)
			{
				index_value = temp->data;
				return (index_value);
			}
			temp = temp->prev;
		}
		pile->min_chunk = pile->min_chunk + pile->nb_in_chunk;
		pile->max_chunk = pile->max_chunk + pile->nb_in_chunk;
	}
	return (index_value);
}

void	ft_move_medium_pile_a(t_pile *pile)
{
	t_pile	*temp;

	temp = pile->pile_a;
	while (temp->data != ft_index_first(pile))
	{
		ft_rotate_a(pile);
	}
}


void	ft_sort_medium_pile(t_pile *pile)
{
	ft_define_chunk(pile);
	ft_printf("\n%sft_index_first = %d%s\n", MAGENTA, ft_index_first(pile), RESET);
	ft_printf("\n%sft_index_second = %d%s\n\n", MAGENTA, ft_index_second(pile), RESET);

	ft_move_medium_pile_a(pile);
	
	ft_printf("\n%s***END SORT***%s\n", MAGENTA, RESET); // A SUPPRIMER
	ft_print_piles(pile->pile_a, pile->pile_b); // A SUPPRIMER
}
