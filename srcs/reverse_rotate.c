/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:24:18 by abonnefo          #+#    #+#             */
/*   Updated: 2023/02/13 16:47:59 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
rra (reverse rotate a) : Décale d’une position vers le bas tous les élements de
la pile a. Le dernier élément devient le premier.

rrb (reverse rotate b) : Décale d’une position vers le bas tous les élements de
la pile b. Le dernier élément devient le premier.

rrr : rra et rrb en même temps.
*/

void	ft_reverse_rotate_a(t_pile *pile)
{
	int	temp;

	temp = ft_last_cell(pile->pile_a);
	pile->pile_a = ft_add_pos(pile->pile_a, temp, 0);
	pile->pile_a = ft_delete_last_cell(pile->pile_a);
	// ft_printf("rra\n");
}

void	ft_reverse_rotate_b(t_pile *pile)
{
	int	temp;

	temp = ft_last_cell(pile->pile_b);
	pile->pile_b = ft_add_pos(pile->pile_b, temp, 0);
	pile->pile_b = ft_delete_last_cell(pile->pile_b);
	// ft_printf("rrb\n");
}

void	ft_reverse_rotate_a_and_b(t_pile *pile)
{
	ft_reverse_rotate_a(pile);
	ft_reverse_rotate_b(pile);
	// ft_printf("rrr\n");
}
