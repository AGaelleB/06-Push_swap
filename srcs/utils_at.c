/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_at.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:39:47 by abonnefo          #+#    #+#             */
/*   Updated: 2023/02/18 22:19:27 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_get_at(t_pile *list, int pos)
{
	int	i;

	i = 0;
	if (ft_is_empty_list(list))
	{
		ft_printf("empty list\n");
		return (-1);
	}
	while (i < pos)
	{
		i++;
		list = list->next;
	}
	return (list->data);
}

int	ft_first_cell(t_pile *pile)
{
	if (pile == NULL)
		return (0);
	return (pile->data);
}

int	ft_last_cell_a(t_pile *pile)
{
	t_pile	*temp;

	temp = pile->pile_a;
	if (temp == NULL)
		return (0);
	while (temp->next != NULL)
		temp = temp->next;
	return (temp->data);
}

int	ft_last_cell_b(t_pile *pile)
{
	t_pile	*temp;

	temp = pile->pile_b;
	if (temp == NULL)
		return (0);
	while (temp->next != NULL)
		temp = temp->next;
	return (temp->data);
}
