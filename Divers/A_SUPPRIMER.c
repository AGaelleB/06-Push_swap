/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_SUPPRIMER.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:59:30 by abonnefo          #+#    #+#             */
/*   Updated: 2023/02/20 17:05:45 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_print_list(t_pile *list)
{
	if (list == NULL)
		return ;
	while (list)
	{
		ft_printf("%d\n", list->data);
		list = list->next;
	}
}

void	ft_print_piles(t_pile *pile_a, t_pile *pile_b)
{
	if (pile_a != NULL)
	{
		ft_printf("%s-----\n", BLUE);
		ft_print_list(pile_a);
		ft_printf("%s-----\n 'a' \n\n%s", BLUE, RESET);
	}
	if (pile_b != NULL)
	{
		ft_printf("%s-----\n", MAGENTA);
		ft_print_list(pile_b);
		ft_printf("%s-----\n 'b' \n\n%s", MAGENTA, RESET);
	}
}

void	degeu(t_pile *pile)
{
	/*JE FAIS MON PRINT INITIAL*/
	ft_printf("\n%s***INIT***%s\n", GREEN, RESET);
	ft_print_piles(pile->pile_a, pile->pile_b);
	ft_printf("%s*********%s\n\n", GREEN, RESET);
	
	// /*JE SWAP*/
	// ft_swap_pile_a(pile);
	// ft_printf("%s***SWAP***%s\n", RED, RESET);
	// ft_print_piles(pile->pile_a, pile->pile_b);
	// ft_printf("%s**********%s\n\n", RED, RESET);
	
	/*JE PUSH A VERS B*/ 
	// ft_push_pile_a_to_b(pile);
	// ft_push_pile_a_to_b(pile);
	// ft_push_pile_a_to_b(pile);
	// ft_printf("%s***PUSH***%s\n", BLUE, RESET);
	// ft_print_piles(pile->pile_a, pile->pile_b);
	// ft_printf("%s**********%s\n\n", BLUE, RESET);
	
	// /*JE SWAP*/
	// ft_swap_pile_b(&pile);
	// ft_printf("%s***SWAP***%s\n", RED, RESET);
	// ft_print_piles(pile.pile_a, pile.pile_b);
	// ft_printf("%s**********%s\n\n", RED, RESET);

	// /*JE PUSH B VERS A*/ 
	// ft_push_pile_b_to_a(&pile);
	// ft_printf("%s***PUSH***%s\n", BLUE, RESET);
	// ft_print_piles(pile.pile_a, pile.pile_b);
	// ft_printf("%s**********%s\n\n", BLUE, RESET);
	
	// /*JE ROTATE PILE A*/
	// ft_rotate_a(&pile);
	// ft_printf("%s**ROTATE RA**%s\n", MAGENTA, RESET);
	// ft_print_piles(pile.pile_a, pile.pile_b);
	// ft_printf("%s**********%s\n\n", MAGENTA, RESET);
	
	// /*JE ROTATE PILE B*/
	// ft_rotate_b(&pile);
	// ft_printf("%s**ROTATE RB**%s\n", MAGENTA, RESET);
	// ft_print_piles(pile.pile_a, pile.pile_b);
	// ft_printf("%s**********%s\n\n", MAGENTA, RESET);
	
	// /*JE ROTATE PILE A&B*/
	// ft_rotate_a_and_b(&pile);
	// ft_printf("%s*ROTATE RA & RB*%s\n", MAGENTA, RESET);
	// ft_print_piles(pile.pile_a, pile.pile_b);
	// ft_printf("%s**********%s\n\n", MAGENTA, RESET);

	/*JE REVERSE ROTATE PILE A*/
	// ft_reverse_rotate_a(pile);
	// ft_printf("%s**REVERSE ROTATE RRA**%s\n", CYAN, RESET);
	// ft_print_piles(pile->pile_a, pile->pile_b);
	// ft_printf("%s**********%s\n\n", CYAN, RESET);
	
	// /*JE REVERSE ROTATE PILE A AND B*/
	// ft_reverse_rotate_a_and_b(pile);
	// ft_printf("%s**REVERSE ROTATE RRR**%s\n", CYAN, RESET);
	// ft_print_piles(pile->pile_a, pile->pile_b);
	// ft_printf("%s**********%s\n\n", CYAN, RESET);
}
