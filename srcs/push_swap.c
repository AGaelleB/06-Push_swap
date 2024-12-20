/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:49:22 by abonnefo          #+#    #+#             */
/*   Updated: 2023/03/10 11:16:50 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_pile_a_is_sort(t_pile *pile)
{
	int		i;
	t_pile	*temp;

	i = 0;
	temp = pile->pile_a;
	if (temp == NULL)
		return (-1);
	while (temp->next)
	{
		if (temp->data < temp->next->data)
			i++;
		temp = temp->next;
	}
	if (i == pile->size_a - 1)
		return (1);
	else
		return (-1);
}

void	ft_check_if_sort(t_pile *pile)
{
	if (ft_pile_a_is_sort(pile) == 1)
	{
		ft_free_list(pile->pile_a);
		exit (0);
	}
}

void	ft_put_in_pile(t_pile *pile, int ac, char **av)
{
	int			i;
	long		current_pos;

	i = 1;
	while (i < ac)
	{
		current_pos = ft_atoi(av[i]);
		pile->pile_a = ft_add_pos(pile->pile_a, current_pos, i - 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_pile	pile;

	if (*av && ac < 2)
		return (0);
	pile.pile_a = NULL;
	pile.pile_b = NULL;
	ft_check_ac(ac, av);
	ft_check_no_arg(ac, av);
	ft_put_in_pile(&pile, ac, av);
	ft_init_struct(&pile);
	ft_check_int_max_and_min(&pile);
	ft_check_same_arg(&pile);
	ft_check_if_sort(&pile);
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
