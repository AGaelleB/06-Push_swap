/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:22:41 by abonnefo          #+#    #+#             */
/*   Updated: 2023/02/09 14:37:22 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
sa (swap a) : Intervertit les 2 premiers éléments au sommet de la pile a.
Ne fait rien s’il n’y en a qu’un ou aucun.

sb (swap b ) : Intervertit les 2 premiers éléments au sommet de la pile b.
Ne fait rien s’il n’y en a qu’un ou aucun.

ss : sa et sb en même temps.
*/

t_lst	*sa(t_lst *a)
{
	t_lst	*temp = NULL;
	
	if (a->next == NULL || a == NULL)
		return;
	temp = a->next;
	a->next = temp->next;
	temp->next = a;
	return(temp);
}

t_lst	*sb(t_lst *b)
{
	t_lst	*temp = NULL;

	if (b->next == NULL || b == NULL)
		return;
	temp = b->next;
	b->next = temp->next;
	temp->next = b;
	return(temp);
}

t_lst	*ss(t_lst *a, t_lst *b)
{
	a = sa(a);
	b = sb(b);
}
