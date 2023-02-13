/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:00:44 by abonnefo          #+#    #+#             */
/*   Updated: 2023/02/13 16:52:46 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_is_empty_list(t_pile *list)
{
	if (list == NULL)
		return (1);
	else
		return (0);
}

t_pile	*ft_free_list(t_pile *list)
{
	t_pile	*temp;

	temp = NULL;
	while (list)
	{
		temp = list->next;
		free(list);
		list = temp;
	}
	return (list);
}

t_pile	*ft_delete_last_cell(t_pile *pile)
{
	t_pile	*prev;
	t_pile	*curr;

	if (ft_is_empty_list(pile))
		return (NULL);
	if (pile->next == NULL)
	{
		free(pile);
		return (NULL);
	}
	prev = NULL;
	curr = pile;
	while (curr->next != NULL)
	{
		prev = curr;
		curr = curr->next;
	}
	free(curr);
	prev->next = NULL;
	return (pile);
}
