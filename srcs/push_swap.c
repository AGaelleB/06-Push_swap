/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:49:22 by abonnefo          #+#    #+#             */
/*   Updated: 2023/02/14 13:03:25 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_put_in_pile(t_pile *pile, int ac, char **av)
{
	int		i;
	int		j;
	int		current_pos;

	i = 1;
	j = 0;
	while (i < ac)
	{
		current_pos = ft_atoi(av[i]);
		pile->pile_a = ft_add_pos(pile->pile_a, current_pos, j);
		i++;
		j++;
	}
}

int	main(int ac, char **av)
{
	t_pile	pile;

	pile.pile_a = NULL;
	pile.pile_b = NULL;
	
	ft_check_ac(ac, av);
	ft_put_in_pile(&pile, ac, av);
	degeu(&pile);
	ft_printf("pile A sort ? = %d\n", ft_pile_a_is_sort(&pile));
	ft_printf("pile B sort ? = %d\n", ft_pile_b_is_sort(&pile));
	ft_free_list(pile.pile_a);
	ft_free_list(pile.pile_b);
	return (0);
}
