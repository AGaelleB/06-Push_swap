/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 09:48:49 by abonnefo          #+#    #+#             */
/*   Updated: 2023/02/10 15:16:28 by abonnefo         ###   ########.fr       */
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

typedef struct	s_pile {
	int				data;
	// int				position_zero;
	struct s_pile	*pile_a;
	struct s_pile	*pile_b;
	struct s_pile	*next;
}					t_pile, pile;

/******************************* push_sawp.c *********************************/

/******************************* utils_free.c ********************************/

int		ft_is_empty_list(t_pile *list);
t_pile	*ft_free_list(t_pile *list);
t_pile	*ft_free_at_pos(t_pile *list, int pos);

/******************************* utils_set.c *********************************/

t_pile	*ft_add_pos(t_pile *list, int data, int pos);
int		ft_get_at(t_pile *list, int pos);
void	ft_set_at(t_pile *list, int data, int pos);
void	ft_print_list(t_pile *list);

/******************************* verif_arg.c *********************************/

int		ft_check_ac(int ac, char **av);

/********************************* swap.c ************************************/

t_pile	*ft_swap(t_pile *pile);
// t_pile	*sb(t_pile *pile);
// t_pile	*ss(t_pile *pile_a, t_pile *pile_b);

/********************************* push.c ************************************/

// t_pile	*ft_first_cell(t_pile *pile);
int ft_first_cell(t_pile *pile);

// t_pile	*ft_push(t_pile *pile_a, t_pile *pile_b);
t_pile	*ft_push(t_pile *src, t_pile *dest);


#endif