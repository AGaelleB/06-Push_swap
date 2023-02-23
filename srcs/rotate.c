/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:24:18 by abonnefo          #+#    #+#             */
/*   Updated: 2023/02/23 09:48:28 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rotate_a(t_pile *pile)
{
	int		temp;
	int		last_ac;
	t_pile	*free_pile;

	temp = ft_first_cell(pile->pile_a);
	free_pile = pile->pile_a;
	pile->pile_a = pile->pile_a->next;
	last_ac = ft_lst_size(pile->pile_a);
	pile->pile_a = ft_add_pos(pile->pile_a, temp, last_ac);
	free(free_pile);
	ft_printf("ra\n");
}

void	ft_rotate_b(t_pile *pile)
{
	int		temp;
	int		last_ac;
	t_pile	*free_pile;

	temp = ft_first_cell(pile->pile_b);
	free_pile = pile->pile_b;
	pile->pile_b = pile->pile_b->next;
	last_ac = ft_lst_size(pile->pile_b);
	pile->pile_b = ft_add_pos(pile->pile_b, temp, last_ac);
	free(free_pile);
	ft_printf("rb\n");
}

void	ft_rotate_a_and_b(t_pile *pile)
{
	ft_rotate_a(pile);
	ft_rotate_b(pile);
	ft_printf("rr\n");
}
