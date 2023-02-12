/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:49:22 by abonnefo          #+#    #+#             */
/*   Updated: 2023/02/12 18:43:37 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_piles(t_pile *pile_a, t_pile *pile_b)
{
	ft_print_list(pile_a);
	ft_printf("-----\n 'a'\n\n");
	ft_print_list(pile_b);
	ft_printf("-----\n 'b' \n");
}

int	main(int ac, char **av)
{
	t_pile	pile;

	int		i;
	int		j;
	int		current_pos;

	j = 0;
	i = 1;
	while (i < ac)
	{
		current_pos = ft_atoi(av[i]);
		pile.pile_a = ft_add_pos(pile.pile_a, current_pos, j);
		i++;
		j++;
	}

	/*JE FAIS MON PRINT INITIAL*/
	ft_printf("\n%s***INIT***%s\n", GREEN, RESET);
	print_piles(pile.pile_a, pile.pile_b);
	ft_printf("%s*********%s\n\n", GREEN, RESET);

}




// int	main(int ac, char **av)
// {
// 	t_pile	pile;
	
// 	t_pile	*pile_a = NULL;
// 	t_pile	*pile_b = NULL;
	
// 	int		i;
// 	int		j;
// 	int		current_pos;

// 	j = 0;
// 	i = 1;
// 	if (ft_check_ac(ac, av) == 0)
// 	{
// 		ft_printf("Error : alphanumeric parameters in argv\n");
// 		return (0);
// 	}
// 	while (i < ac)
// 	{
// 		current_pos = ft_atoi(av[i]);
// 		pile.pile_a = ft_add_pos(pile.pile_a, current_pos, j);
// 		i++;
// 		j++;
// 	}

// 	/*JE FAIS MON PRINT INITIAL*/
// 	ft_printf("\n%s***INIT***%s\n", GREEN, RESET);
// 	print_piles(pile.pile_a, pile.pile_b);
// 	ft_printf("%s*********%s\n\n", GREEN, RESET);

// 	/*JE SWAP*/
// 	ft_swap_pile_a(pile.pile_a);
// 	ft_printf("%s***SWAP***%s\n", RED, RESET);
// 	print_piles(pile.pile_a, pile.pile_b);
// 	ft_printf("%s**********%s\n\n", RED, RESET);

// 	/*JE PUSH A VERS B*/ 
// 	pile_b = ft_push(pile_a, pile_b);
// 	pile_a = ft_free_at_pos(pile_a, 0); // A SUPPRIMER
// 	ft_push(pile_a, pile_b);
// 	ft_printf("%s***PUSH***%s\n", BLUE, RESET);
// 	print_piles(pile_a, pile_b);
// 	ft_printf("%s**********%s\n\n", BLUE, RESET);
	
// 	ft_free_list(pile_a);
// 	ft_free_list(pile_b);
// 	return (0);
// }
