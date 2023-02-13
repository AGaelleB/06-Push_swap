/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:22:41 by abonnefo          #+#    #+#             */
/*   Updated: 2023/02/13 16:46:29 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
sa (swap a) : Intervertit les 2 premiers éléments au sommet de la pile a.
Ne fait rien s’il n’y en a qu’un ou aucun.

sb (swap b ) : Intervertit les 2 premiers éléments au sommet de la pile b.
Ne fait rien s’il n’y en a qu’un ou aucun.

ss : sa et sb en même temps.
*/

void	ft_swap_pile_a(t_pile *pile)
{
	t_pile	*temp;

	temp = NULL;
	temp = pile->pile_a;
	pile->pile_a = temp->next;
	temp->next = pile->pile_a->next;
	pile->pile_a->next = temp;
	// ft_printf("sa\n");
}

void	ft_swap_pile_b(t_pile *pile)
{
	t_pile	*temp;

	temp = NULL;
	temp = pile->pile_b;
	pile->pile_b = temp->next;
	temp->next = pile->pile_b->next;
	pile->pile_b->next = temp;
	// ft_printf("sb\n");
}

void	ft_swap_pile_a_and_b(t_pile *pile)
{
	ft_swap_pile_a(pile);
	ft_swap_pile_b(pile);
	// ft_printf("ss\n");
}
