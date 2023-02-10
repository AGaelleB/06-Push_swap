/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:22:41 by abonnefo          #+#    #+#             */
/*   Updated: 2023/02/10 13:46:52 by abonnefo         ###   ########.fr       */
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

t_pile	*ft_swap(t_pile *pile)
{
	t_pile	*temp = NULL;

	if (pile == NULL || pile->next == NULL)
		return;
	temp = pile->next;
	pile->next = temp->next;
	temp->next = pile;
	return(temp);
}
