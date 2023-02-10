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

t_pile *ft_create_cell(int data)
{
	t_pile *cell = malloc(sizeof(t_pile));
	if(!cell)
		return (0);
	cell->data = data;
	cell->next = NULL;
	return (cell);
}

t_pile	*ft_add_pos(t_pile *list, int data, int pos)
{
	t_pile	*previous_pos = list;
	t_pile	*position = list;
	t_pile	*cell = ft_create_cell(data);
	int	i;

	i = 0;
	if (ft_is_empty_list(list))
		return (cell);
	if (pos == 0)
	{
		cell->next = list;
		return (cell); // pointeur de tete de liste
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

void	ft_set_at(t_pile *list, int data, int pos)
{
	int	i;
	
	i = 0;
	if (ft_is_empty_list(list))
	{
		ft_printf("empty list\n");
		return;
	}
	if(pos > ft_lstsize(list))
	{
		ft_printf("position > size of list\n");
		return;
	}
	while (i < pos)
	{
		i++;
		list = list->next;
	}
	list->data = data;
}

void	ft_print_list(t_pile *list) // A SUPPRIMER
{
	if (list == NULL)
		return;
	while (list)
	{
		ft_printf("%d\n", list->data);
		list = list->next;
	}
}