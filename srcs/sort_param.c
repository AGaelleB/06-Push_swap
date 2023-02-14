/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:59:50 by abonnefo          #+#    #+#             */
/*   Updated: 2023/02/14 16:47:24 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_small_pile(t_pile *pile)
{
	// t_pile	*temp;
	printf("\nDEBUT ft_sort_small_pile\n\n");

	ft_push_pile_a_to_b(pile); //pb
	ft_push_pile_a_to_b(pile); //pb

	printf("\nPILE APRES PUSH\n\n");
	print_piles(pile->pile_a, pile->pile_b);

	// temp = pile->pile_a;
	while (pile->pile_a != NULL)	//!ft_pile_a_is_sort(pile)
	{
		if (pile->pile_a->data > pile->pile_a->next->next->data)
			ft_rotate_a(pile);
		if (pile->pile_a->data > pile->pile_a->next->data)
			ft_swap_pile_a(pile);
		break;
	}
	printf("\nPILE APRES TRI 1\n");
	print_piles(pile->pile_a, pile->pile_b);
	
	ft_push_pile_b_to_a(pile); //pa
	
	while (pile->pile_a != NULL)
	{
		if (pile->pile_a->data > pile->pile_a->next->next->data)
			ft_rotate_a(pile);
		if (pile->pile_a->data > pile->pile_a->next->data)
			ft_swap_pile_a(pile);
		break;
	}
	
	printf("\nPILE APRES TRI 2\n");
	print_piles(pile->pile_a, pile->pile_b);
	
	ft_push_pile_b_to_a(pile); //pa
	
	while (pile->pile_a != NULL)
	{
		if (pile->pile_a->data > pile->pile_a->next->next->data)
			ft_rotate_a(pile);
		if (pile->pile_a->data > pile->pile_a->next->data)
			ft_swap_pile_a(pile);
		break;
	}
	printf("\nPILE APRES TRI 3\n");
	print_piles(pile->pile_a, pile->pile_b);
}
