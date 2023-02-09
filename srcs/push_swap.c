/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:49:22 by abonnefo          #+#    #+#             */
/*   Updated: 2023/02/09 11:14:14 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
coder toutes les fonctions genre ft_ra
*/

int	main(int ac, char **av)
{
	t_lst	*list = NULL;
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
		list = ft_add_pos(list, current_pos, j);
		i++;
		j++;
	}
	ft_print_list(list);
	ft_free_list(list);
	return (0);
}

	// ft_printf("la liste est elle vide ? : %d\n", ft_is_empty_list(list));
	// ft_printf("data en pos 0 = %d\n", ft_get_at(list, 0));
	// list = ft_add_pos(list, 10, 0);
	// ft_printf("la liste est elle vide ? : %d\n", ft_is_empty_list(list));
	// ft_print_list(list);
	// list = ft_add_pos(list, 20, 0);
	// ft_print_list(list);
	// list = ft_add_pos(list, 500, 0);
	// ft_print_list(list);
	// ft_printf("data en pos 2 = %d\n", ft_get_at(list, 2));
	// ft_set_at(list, 999, 2);
	// ft_printf("longueur liste = %d\n", ft_lstsize(list));
	// ft_printf("data en pos 2 apres ft_set_at 999 = %d\n", ft_get_at(list, 2));
	// list = ft_free_list(list); // utiliser ft_lstclear
	// ft_printf("longueur liste apres free = %d\n", ft_lstsize(list));