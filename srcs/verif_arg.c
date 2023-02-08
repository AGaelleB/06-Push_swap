/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:16:28 by abonnefo          #+#    #+#             */
/*   Updated: 2023/02/06 16:33:08 by abonnefo         ###   ########.fr       */
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
	while(i < ac)
	{
		j = 0;
		arg = av[i];
		lenght_arg = ft_strlen(av[i]);
		while(j < lenght_arg)
		{
			if (ft_isalpha(arg[j]))
				return(0);
			j++;
		}
		i++;
	}
	return (1);
}