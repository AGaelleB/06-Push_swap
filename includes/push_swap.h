/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 09:48:49 by abonnefo          #+#    #+#             */
/*   Updated: 2023/02/09 14:33:33 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdint.h>
# include <string.h>

# include "../includes/ft_printf.h"
# include "../includes/get_next_line.h"
# include "../includes/libft.h"


typedef struct	s_lst
{
	int				*data;
	// struct s_lst	*a;
	// struct s_lst	*b;
	struct s_lst	*next;
}					t_lst;

// typedef struct	s_pile
// {
// 	struct s_pile	*a;
// 	struct s_pile	*b;
// }					t_pile;

/******************************* push_sawp.c *********************************/

/******************************* utils_free.c ********************************/

int	ft_is_empty_list(t_lst *list);
t_lst	*ft_free_list(t_lst *list);
t_lst	*ft_free_at_list(t_lst *list, int pos);

/******************************* utils_set.c *********************************/

t_lst	*ft_add_pos(t_lst *list, int data, int pos);
int	ft_get_at(t_lst *list, int pos);
void	ft_set_at(t_lst *list, int data, int pos);
void	ft_print_list(t_lst *list);

/******************************* verif_arg.c *********************************/

int	ft_check_ac(int ac, char **av);

/******************************* swap.c *********************************/

t_lst	*sa(t_lst *a);
t_lst	*sb(t_lst *b);
t_lst	*ss(t_lst *a, t_lst *b);




#endif