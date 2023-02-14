/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:23:38 by abonnefo          #+#    #+#             */
/*   Updated: 2023/02/14 14:32:24 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
pa (push a) : Prend le premier élément au sommet de b et le met sur a.
Ne fait rien si b est vide.

pb (push b) : Prend le premier élément au sommet de a et le met sur b.
Ne fait rien si a est vide.
*/

void	ft_push_pile_a_to_b(t_pile *pile)
{
	t_pile	*position;
	int		pos_zero;

	position = pile->pile_a;
	pos_zero = ft_first_cell(pile->pile_a);
	pile->pile_b = ft_add_pos(pile->pile_b, pos_zero, 0);
	pile->pile_a = pile->pile_a->next;
	free(position);
	ft_printf("pb\n");
}

void	ft_push_pile_b_to_a(t_pile *pile)
{
	t_pile	*position;
	int		pos_zero;

	position = pile->pile_b;
	pos_zero = ft_first_cell(pile->pile_b);
	pile->pile_a = ft_add_pos(pile->pile_a, pos_zero, 0);
	pile->pile_b = pile->pile_b->next;
	free(position);
	ft_printf("pa\n");
}
