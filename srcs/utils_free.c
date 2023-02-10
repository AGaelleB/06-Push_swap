/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:00:44 by abonnefo          #+#    #+#             */
/*   Updated: 2023/02/10 14:24:10 by abonnefo         ###   ########.fr       */
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
	t_list *temp = NULL;
	while (list)
	{
		temp = list->next;
		free(list);
		list = temp;
	}
	return (list);
}

t_pile	*ft_free_at_pos(t_pile *list, int pos)
{
	t_pile	*position = list;
	list = list->next;
	free(position);
	return (list);
}

// t_pile	*ft_free_at_pos(t_pile *list, int pos)
// {
// 	t_pile	*previous_pos = list;
// 	t_pile	*position = list;
// 	int	i;

// 	i = 0;
// 	if (ft_is_empty_list(list))
// 		return (NULL);
// 	if (pos == 0)
// 	{
// 		list = list->next;
// 		free(position);
// 		return (list);
// 	}
// 	while (i < pos)
// 	{
// 		i++;
// 		previous_pos = position;
// 		position = position-> next;
// 	}
// 	previous_pos->next = position->next;
// 	free(position);
// 	return (list);
// }
