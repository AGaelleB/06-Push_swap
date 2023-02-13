/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:59:41 by abonnefo          #+#    #+#             */
/*   Updated: 2023/02/09 10:59:54 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_pile	*ft_create_cell(int data)
{
	t_pile	*cell;

	cell = malloc(sizeof(t_pile));
	if (!cell)
		return (0);
	cell->data = data;
	cell->next = NULL;
	return (cell);
}

t_pile	*ft_add_pos(t_pile *list, int data, int pos)
{
	t_pile	*previous_pos;
	t_pile	*position;
	t_pile	*cell;
	int		i;

	previous_pos = list;
	position = list;
	cell = ft_create_cell(data);
	i = 0;
	if (ft_is_empty_list(list))
		return (cell);
	if (pos == 0)
	{
		cell->next = list;
		return (cell);
	}
	while (i < pos)
	{
		i++;
		previous_pos = position;
		position = position-> next;
	}
	previous_pos->next = cell;
	cell->next = position;
	return (list);
}

void	ft_set_at(t_pile *list, int data, int pos)
{
	int	i;

	i = 0;
	if (ft_is_empty_list(list))
	{
		ft_printf("empty list\n");
		return ;
	}
	if (pos > ft_lst_size(list))
	{
		ft_printf("position > size of list\n");
		return ;
	}
	while (i < pos)
	{
		i++;
		list = list->next;
	}
	list->data = data;
}

int	ft_lst_size(t_pile *pile)
{
	int	i;

	i = 0;
	while (pile)
	{
		pile = pile->next;
		i++;
	}
	return (i);
}
