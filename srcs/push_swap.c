/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:49:22 by abonnefo          #+#    #+#             */
/*   Updated: 2023/02/09 14:52:34 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_lst	*a = NULL;
	t_lst	*b = NULL;
	int	i;
	int	j;
	int	current_pos;

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
		a = ft_add_pos(a, current_pos, j);
		i++;
		j++;
	}
	ft_printf("\print intial:\n");
	ft_print_list(a);
	ft_printf("-----\n 'a' \n");
	ft_print_list(b);
	ft_printf("\n\n-----\n 'b' \n");

	a = sa(a);
	ft_printf("\ntest print pile 'a' apres 'sa':\n");
	ft_print_list(a);
	ft_printf("-----\n 'a' \n");
	ft_print_list(b);
	ft_printf("\n\n-----\n 'b' \n");

	// b = sb(b);
	// ft_printf("\ntest print pile 'a' apres 'sa':\n");
	// ft_print_list(b);
	// ft_printf("-----\n 'a' \n");
	// ft_print_list(b);
	// ft_printf("\n\n-----\n 'b' \n");

	ft_free_list(a);
	// ft_free_list(b);
	return (0);
}
