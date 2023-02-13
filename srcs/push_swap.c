/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:49:22 by abonnefo          #+#    #+#             */
/*   Updated: 2023/02/13 16:59:41 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_pile	pile;
	int		i;
	int		j;
	int		current_pos;

	pile.pile_a = NULL;
	pile.pile_b = NULL;
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
		pile.pile_a = ft_add_pos(pile.pile_a, current_pos, j);
		i++;
		j++;
	}
	degeu(&pile);
	return (0);
}
