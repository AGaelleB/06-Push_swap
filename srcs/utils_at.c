/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_at.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:39:47 by abonnefo          #+#    #+#             */
/*   Updated: 2023/03/10 11:17:49 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
