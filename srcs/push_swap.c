/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:49:22 by abonnefo          #+#    #+#             */
/*   Updated: 2023/02/10 15:18:52 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"



int	main(int ac, char **av)
{
	t_pile	*pile_a = NULL;
	t_pile	*pile_b = NULL;
	int		i;
	int		j;
	int		current_pos;

	j = 0;
	i = 1;
	if (ft_check_ac(ac, av) == 0)
	{
		ft_printf("Error : alphanumeric parameters in argv\n");
		return (0);
	}
	while (i < ac)
	{
		current_pos = ft_atoi(av[i]);
		pile_a = ft_add_pos(pile_a, current_pos, j);
		i++;
		j++;
	}
	
	/*JE FAIS MON PRINT INITIAL*/
	ft_printf("\n****INITIAL PRINT***\n");
	ft_print_list(pile_a);
	ft_printf("-----\n 'a' \n\n");
	ft_print_list(pile_b);
	ft_printf("-----\n 'b' \n");
	ft_printf("********************\n\n");

	/*JE SWAP*/
	pile_a = ft_swap(pile_a);
	ft_printf("********SWAP********\n");
	ft_print_list(pile_a);
	ft_printf("-----\n 'a' \n\n");
	ft_print_list(pile_b);
	ft_printf("-----\n 'b' \n");
	ft_printf("********************\n\n");
	
	/*JE PUSH A VERS B*/
	// pile_b = ft_push(pile_a, pile_b);
	// pile_a = ft_free_at_pos(pile_a, 0); // A SUPPRIMER
	ft_push(pile_a, pile_b);
	ft_printf("********PUSH********\n");
	ft_print_list(pile_a);
	ft_printf("-----\n 'a' \n\n");
	ft_print_list(pile_b);
	ft_printf("-----\n 'b' \n");
	ft_printf("********************\n\n");
	
	// ft_free_list(pile_a);
	// ft_free_list(pile_b);
	return (0);
}
