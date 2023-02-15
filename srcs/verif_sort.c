/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:17:38 by abonnefo          #+#    #+#             */
/*   Updated: 2023/02/15 17:29:24 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_pile_a_is_sort(t_pile *pile)
{
	int		i;
	int		size;
	t_pile	*temp;

	i = 0;
	size = ft_lst_size(pile->pile_a);
	temp = pile->pile_a;
	if (temp == NULL)
		return (-1);
	while (temp->next)
	{
		if (temp->data < temp->next->data)
			i++;
		temp = temp->next;
	}
	if (i == size - 1)
		return (1);
	else
		return (-1);
}

int	ft_pile_b_is_sort(t_pile *pile)
{
	int		i;
	int		size;
	t_pile	*temp;

	i = 0;
	size = ft_lst_size(pile->pile_b);
	temp = pile->pile_b;
	if (temp == NULL)
		return (1);
	while (temp->next)
	{
		if (temp->data < temp->next->data)
			i++;
		temp = temp->next;
	}
	if (i == size - 1)
		return (1);
	else
		return (-1);
}

void	ft_check_if_sort(t_pile *pile)
{
	if (ft_pile_a_is_sort(pile) == 1 && ft_pile_b_is_sort(pile) == 1)
	{
		ft_printf("%sThe pile is already sort%s\n", GREEN, RESET);
		exit (0);
	}
}