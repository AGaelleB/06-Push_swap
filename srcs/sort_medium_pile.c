/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium_pile.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:42:41 by abonnefo          #+#    #+#             */
/*   Updated: 2023/02/21 17:17:40 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_define_chunk(t_pile *pile)
{
	pile->min_pile_a = ft_find_min_value(pile->pile_a);
	// pile->min_pile_b = ft_find_min_value(pile->pile_b); // SEGFAULT
	pile->max_pile = ft_find_max_value(pile->pile_a);
	pile->min_chunk = pile->min_pile_a;
	pile->nb_in_chunk = ((pile->max_pile - pile->min_pile_a) / 5); // tester les chunks
	pile->max_chunk = pile->min_chunk + pile->nb_in_chunk;
	pile->mediane = pile->size_a / 2;

	// ft_printf("min_pile_a = %d\n", pile->min_pile_a);
	// ft_printf("min_pile_b = %d\n", pile->min_pile_b);
	// ft_printf("max_pile = %d\n", pile->max_pile);
	// ft_printf("nb_in_chunk = %d\n", pile->nb_in_chunk);
	// ft_printf("\nmin_chunk = %d\n", pile->min_chunk);
	// ft_printf("max_chunk = %d\n", pile->max_chunk);
	// ft_printf("\npile->size_a = %d\n", pile->size_a);
	// ft_printf("pile->mediane = %d\n", pile->mediane);
}

int	ft_data_index_first(t_pile *pile) // OK
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
				// printf("\nIN THE IF pile->min_chunk %d\n", pile->min_chunk);
				// printf("IN THE IF pile->max_chunk %d\n", pile->max_chunk);
				index_value = temp->data;
				return (index_value);
			}
			temp = temp->next;
		}
		pile->min_chunk = pile->min_chunk + pile->nb_in_chunk;
		pile->max_chunk = pile->max_chunk + pile->nb_in_chunk;
		// printf("\nLA pile->min_chunk %d\n", pile->min_chunk);
		// printf("LA pile->max_chunk %d\n", pile->max_chunk);
		temp = pile->pile_a;
	}
	return (index_value);
}

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

/*********************************************************************************************/

int	ft_find_closest_value(t_pile *pile)
{
	t_pile	*temp;
	int		closest;

	temp = pile->next;
	closest = ft_first_cell(pile);
	while (temp)
	{
		if (temp->data - 1 != temp->data) //(temp->data > closest)
			closest = temp->data;
		temp = temp->next;
	}
	return (closest);
}

void	ft_move_medium_pile_b(t_pile *pile) // ICI je veux definir si je rra ou ra avant pb
{
	t_pile	*temp_b;
	int		highest_in_b;
	int		smallest_in_b;
	int		closest_in_b;

	temp_b = pile->pile_b;
	highest_in_b = ft_find_max_value(pile->pile_b);
	smallest_in_b = ft_find_min_value(pile->pile_b);
	closest_in_b = ft_find_closest_value(pile->pile_b);

	// printf("temp_b->data = %d\n", temp_b->data);
	// printf("pile->pos_zero = %d\n", pile->pos_zero);
	// printf("highest_in_b = %d\n", highest_in_b);
	// printf("smallest_in_b = %d\n", smallest_in_b);
	// printf("closest_in_b = %d\n", closest_in_b);

	if (ft_first_cell(pile->pile_a) >= highest_in_b) //alors je rotate pour que n+1 ou n-1 soit egale a la highest
	{
		// printf("\n ICI \n");
		if (ft_first_cell(pile->pile_b) != highest_in_b)
		{
			// if (ft_pos_index_first(pile, highest_in_b) > pile->mediane)
				ft_rotate_b(pile);
			// else if (ft_pos_index_first(pile, highest_in_b) <= pile->mediane)
				// ft_reverse_rotate_b(pile);
		}
	}
	else if (ft_first_cell(pile->pile_a) < smallest_in_b) //alors je rotate pour que n+1 ou n-1 soit egale a la smallest
	{
		if (ft_first_cell(pile->pile_b) != smallest_in_b)
		{
			// if (ft_pos_index_first(pile, smallest_in_b) > pile->mediane)
				ft_rotate_b(pile);
			// else if (ft_pos_index_first(pile, smallest_in_b) <= pile->mediane)
				// ft_reverse_rotate_b(pile);
		}
	}
	else if (ft_first_cell(pile->pile_a) > smallest_in_b && ft_first_cell(pile->pile_a) < highest_in_b)
	{
		// if (ft_first_cell(pile->pile_b) != closest_in_b) // bouger la pile pour se trouver entre 
			ft_rotate_b(pile);
	}
	ft_push_pile_a_to_b(pile);
}

/*********************************************************************************************/

void	ft_move_medium_pile_a(t_pile *pile) // NE MARCHE PLUS
{
	int	data_first;
	int	data_last;

	while (pile->pile_a)
	{
		data_first = ft_data_index_first(pile);
		data_last = ft_data_index_last(pile);
		pile->mediane = pile->size_a / 2; // AJOUT
		if ((pile->size_a - ft_pos_index_last(pile, data_last)) < ft_pos_index_first(pile, data_first))
		{
			if (ft_pos_index_last(pile, data_last) > pile->mediane)
			{
				while (ft_pos_index_last(pile, data_last) != 0)
				{
					ft_reverse_rotate_a(pile);
					// ft_print_piles(pile->pile_a, pile->pile_b); // A SUPPRIMER
				}
				if (pile->pile_b == NULL)
					ft_push_pile_a_to_b(pile);
				else
					ft_move_medium_pile_b(pile); //NEW
				// 	ft_push_pile_a_to_b(pile);
				// ft_print_piles(pile->pile_a, pile->pile_b); // A SUPPRIMER
			}
		}
		else if ((pile->size_a - ft_pos_index_first(pile, data_first)) >= ft_pos_index_first(pile, data_first))
		{
			if (ft_pos_index_first(pile, data_first) <= pile->mediane)
			{
				while (ft_pos_index_first(pile, data_first) != 0)
				{
					ft_rotate_a(pile);
					// ft_print_piles(pile->pile_a, pile->pile_b); // A SUPPRIMER
				}
				if (pile->pile_b == NULL)
					ft_push_pile_a_to_b(pile);
				else
					ft_move_medium_pile_b(pile); //NEW
				// 	ft_push_pile_a_to_b(pile);
				// ft_print_piles(pile->pile_a, pile->pile_b); // A SUPPRIMER
			}
		}
		if (pile->pile_a->next == NULL)
		{
			ft_push_pile_a_to_b(pile);
			// ft_print_piles(pile->pile_a, pile->pile_b);
			// exit (0);
		}
	}
	while (pile->pile_b != NULL)
		ft_push_pile_b_to_a(pile); //pa
}

void	ft_sort_medium_pile(t_pile *pile)
{
	ft_define_chunk(pile);
	ft_move_medium_pile_a(pile);
	
	// ft_printf("\n%s***END SORT***%s\n", MAGENTA, RESET); // A SUPPRIMER
	// ft_print_piles(pile->pile_a, pile->pile_b); // A SUPPRIMER
}
