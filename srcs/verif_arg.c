/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:16:28 by abonnefo          #+#    #+#             */
/*   Updated: 2023/03/10 11:24:05 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_check_ac(int ac, char **av)
{
	int		i;
	int		j;
	int		lenght_arg;
	char	*arg;

	i = 1;
	while (i < ac)
	{
		j = 0;
		arg = av[i];
		lenght_arg = ft_strlen(av[i]);
		while (j < lenght_arg)
		{
			if (!ft_isdigit(arg[j]) && arg[j] != '+' && arg[j] != '-')
			{
				ft_printf("Error\n");
				exit (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_check_no_arg(int ac, char **av)
{
	if (av[1] == NULL)
		exit (0);
	(void)ac;
}

void	ft_check_same_arg(t_pile *pile)
{
	t_pile	*temp1;
	t_pile	*temp2;

	temp1 = pile->pile_a;
	while (temp1)
	{
		temp2 = temp1->next;
		while (temp2)
		{
			if (temp1->data == temp2->data)
			{
				ft_printf("Error\n");
				ft_free_list(pile->pile_a);
				exit(0);
			}
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
}

void	ft_check_int_max_and_min(t_pile *pile)
{
	t_pile	*temp;
	int		i;

	temp = pile->pile_a;
	i = 0;
	while (i < pile->size_a)
	{
		if ((temp->data > INT_MAX) || (temp->data < INT_MIN))
		{
			ft_printf("Error\n");
			ft_free_list(pile->pile_a);
			exit(0);
		}
		temp = temp->next;
		i++;
	}
}
