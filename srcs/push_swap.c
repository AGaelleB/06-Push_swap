/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:49:22 by abonnefo          #+#    #+#             */
/*   Updated: 2023/02/08 17:41:30 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
coder toutes les fonctions genre ft_ra

int	ft_check_size_int(int ac, char **av)
int max 2147483647 // int min -2147483648

Implementer l'algorithme radix
	• une liste vide
	• une fonction qui vérifiera si la liste est vide
	• une fonction qui calculera la taille de la liste
	• une fonction qui ajoutera un élement a une position donnée
	• une fonction qui récuperera un élement a une position donnée
	• une fonction qui modifiera un élement a une position donnée
	• une fonction qui effacera un élement a une position donnée
	• une fonction qui effacera tous les élements de la liste
*/

typedef struct s_lst
{
	void			*content;
	int				*data;
	struct s_lst	*next;
}					t_lst;

void	*ft_empty_list(void)
{
	return NULL;
}

int	*ft_is_empty_list(t_lst *list)
{
	if (list == NULL)
		return (1);
	else
		return (0);
}

t_lst	*ft_add_pos(t_lst *list, int data, int pos)
{
	t_lst	*position = list;
	t_lst	*next_pos = position->next;
	t_lst	*new_list = malloc(sizeof(t_lst));

	new_list->content = NULL;
	new_list->data = &data;
	new_list->next = next_pos;
	position->next = new_list;

	return (new_list);
}

void	ft_print_list(t_lst *list)
{
	printf("test\n");
	while (!ft_is_empty_list(list))
	{
		ft_printf("%d\n", list->data);
		list = list->next;
	}
}

int	main(int ac, char **av)
{
	t_lst	*list = ft_empty_list();

	t_lst *head = NULL;
	t_lst *tail = NULL;

	if (ft_check_ac(ac, av) == 0)
		ft_printf("Error : alphanumeric parameters in argv\n");

	ft_print_list(list);

	int i = 1;
	while (i < ac)
	{
		t_lst *new_list = malloc(sizeof(t_lst));
		new_list->content = NULL;
		new_list->data = malloc(sizeof(int));
		new_list->data = ft_atoi(av[i]);
		new_list->next = NULL;
		if (head == NULL)
		{
			head = new_list;
			tail = new_list;
		}
		else
		{
			tail->next = new_list;
			tail = new_list;
		}
		i++;
	}
	tail->next = head;
	list = head;
	ft_print_list(list);

	return (0);
}
