/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:49:22 by abonnefo          #+#    #+#             */
/*   Updated: 2023/02/23 12:20:37 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_put_in_pile(t_pile *pile, int ac, char **av)
{
	int			i;
	int			j;
	long		current_pos;

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
	ft_check_no_arg(ac, av);
	ft_put_in_pile(&pile, ac, av);
	ft_init_struct(&pile);
	ft_check_int_max_and_min(&pile);
	ft_check_same_arg(&pile);
	ft_check_if_sort(&pile);
	// degeu(&pile);
	if (ac > 1 && ac <= 6)
		ft_sort_small_pile(&pile);
	if (ac > 6 && ac <= 101)
		ft_sort_medium_pile(&pile);
	if (ac > 101)
		ft_sort_big_pile(&pile);
	ft_free_list(pile.pile_a);
	ft_free_list(pile.pile_b);
	return (0);
}
