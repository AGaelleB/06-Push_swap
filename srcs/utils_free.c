/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:00:44 by abonnefo          #+#    #+#             */
/*   Updated: 2023/02/09 11:12:51 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_is_empty_list(t_lst *list)
{
	if (list == NULL)
		return (1);
	else
		return (0);
}

t_lst	*ft_free_list(t_lst *list)
{
	t_list *temp = NULL;
	while (list)
	{
		temp = list->next;
		free(list);
		list = temp;
	}
	return (list);
}

t_lst	*ft_free_at_list(t_lst *list, int pos)
{
	t_lst	*previous_pos = list;
	t_lst	*position = list;
	int	i;

	i = 0;
	if (ft_is_empty_list(list))
		return (NULL);
	if (pos == 0)
	{
		list = list->next;
		free(position);
		return (list);
	}
	while (i < pos)
	{
		i++;
		previous_pos = position;
		position = position-> next;
	}
	previous_pos->next = position->next;
	free(position);
	return (list);
}
