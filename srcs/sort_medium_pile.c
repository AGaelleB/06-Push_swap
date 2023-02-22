/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium_pile.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:42:41 by abonnefo          #+#    #+#             */
/*   Updated: 2023/02/22 14:12:30 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_define_chunk(t_pile *pile)
{
	pile->min_pile_a = ft_find_min_value(pile->pile_a);
	pile->max_pile = ft_find_max_value(pile->pile_a);
	pile->min_chunk = pile->min_pile_a;
	pile->nb_in_chunk = ((pile->max_pile - pile->min_pile_a) / 5); // tester les chunks
	pile->max_chunk = pile->min_chunk + pile->nb_in_chunk + pile->nb_in_chunk ;
	pile->mediane = pile->size_a / 2;

	// ft_printf("min_pile_a = %d\n", pile->min_pile_a); // A SUPPRIMER
	// ft_printf("max_pile = %d\n", pile->max_pile); // A SUPPRIMER
	// ft_printf("nb_in_chunk = %d\n", pile->nb_in_chunk); // A SUPPRIMER
	// ft_printf("\nmin_chunk = %d\n", pile->min_chunk); // A SUPPRIMER
	// ft_printf("max_chunk = %d\n", pile->max_chunk); // A SUPPRIMER
	// ft_printf("\npile->size_a = %d\n", pile->size_a); // A SUPPRIMER
	// ft_printf("pile->mediane = %d\n", pile->mediane); // A SUPPRIMER
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
				// printf("\nIN THE IF pile->min_chunk %d\n", pile->min_chunk); // A SUPPRIMER
				// printf("IN THE IF pile->max_chunk %d\n", pile->max_chunk); // A SUPPRIMER
				index_value = temp->data;
				return (index_value);
			}
			temp = temp->next;
		}
		pile->min_chunk = pile->min_chunk + pile->nb_in_chunk;
		pile->max_chunk = pile->max_chunk + pile->nb_in_chunk;
		// printf("\nLA pile->min_chunk %d\n", pile->min_chunk); // A SUPPRIMER
		// printf("LA pile->max_chunk %d\n", pile->max_chunk); // A SUPPRIMER
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
		// printf("\nCOUCOU pile->min_chunk %d\n", pile->min_chunk); // A SUPPRIMER
		// printf("COUCOU pile->max_chunk %d\n", pile->max_chunk); // A SUPPRIMER
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

void	ft_move_medium_pile_b(t_pile *pile)
{
	int		highest_in_b;
	int		smallest_in_b;
	int		closest_in_b;

	highest_in_b = ft_find_max_value(pile->pile_b);
	smallest_in_b = ft_find_min_value(pile->pile_b);

	if (ft_first_cell(pile->pile_a) >= highest_in_b)
	{
		while (ft_first_cell(pile->pile_b) != highest_in_b)
		{
			ft_rotate_b(pile);
		}
	}
	else if (ft_first_cell(pile->pile_a) < smallest_in_b)
	{
		while (ft_first_cell(pile->pile_b) != highest_in_b)
		{
			ft_rotate_b(pile);
		}
	}
	else if (ft_first_cell(pile->pile_a) > smallest_in_b
		&& ft_first_cell(pile->pile_a) < highest_in_b)
	{
		closest_in_b = ft_find_closest_value(pile);
		while (ft_first_cell(pile->pile_b) != closest_in_b)
		{
			ft_rotate_b(pile);
		}
	}
	// while (ft_first_cell(pile->pile_b) != highest_in_b)
	// {
	// 	ft_rotate_b(pile);
	// }
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
					ft_move_medium_pile_b(pile);
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
					ft_move_medium_pile_b(pile);
				// ft_print_piles(pile->pile_a, pile->pile_b); // A SUPPRIMER
			}
		}
		if (pile->pile_a->next == NULL)
		{
			ft_move_medium_pile_b(pile);
			// ft_push_pile_a_to_b(pile);
			// ft_print_piles(pile->pile_a, pile->pile_b);
		}
	}
	while (ft_first_cell(pile->pile_b) != ft_find_max_value(pile->pile_b))
	{
		ft_rotate_b(pile);
	}
	
	while (pile->pile_b != NULL)
		ft_push_pile_b_to_a(pile);
}

void	ft_sort_medium_pile(t_pile *pile)
{
	ft_define_chunk(pile);
	ft_move_medium_pile_a(pile);
	// ft_printf("\n%s***END SORT***%s\n", MAGENTA, RESET); // A SUPPRIMER
	// ft_print_piles(pile->pile_a, pile->pile_b); // A SUPPRIMER
}
