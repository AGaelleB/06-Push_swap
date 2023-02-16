/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 09:48:49 by abonnefo          #+#    #+#             */
/*   Updated: 2023/02/16 12:40:18 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# define RESET "\033[0m"
# define BLACK "\033[30m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"

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

typedef struct s_pile {
	long			data;
	int				size_a;
	int				size_b;
	struct s_pile	*pile_a;
	struct s_pile	*pile_b;
	struct s_pile	*next;
}					t_pile;

/******************************* A SUPPRIMER *********************************/
void	ft_print_list(t_pile *list);
void	degeu(t_pile *pile);
void	print_piles(t_pile *pile_a, t_pile *pile_b);
/*****************************************************************************/

/******************************* push_sawp.c *********************************/

/********************************* push.c ************************************/

void	ft_push_pile_a_to_b(t_pile *pile);
void	ft_push_pile_b_to_a(t_pile *pile);

/***************************** reverse_rotate.c ******************************/

void	ft_reverse_rotate_a(t_pile *pile);
void	ft_reverse_rotate_b(t_pile *pile);
void	ft_reverse_rotate_a_and_b(t_pile *pile);

/******************************** rotate.c ***********************************/

void	ft_rotate_a(t_pile *pile);
void	ft_rotate_b(t_pile *pile);
void	ft_rotate_a_and_b(t_pile *pile);

/******************************* sort_param.c ********************************/

void	ft_sort_small_pile(t_pile *pile);

/********************************* swap.c ************************************/

void	ft_swap_pile_a(t_pile *pile_a);
void	ft_swap_pile_b(t_pile *pile);
void	ft_swap_pile_a_and_b(t_pile *pile);

/******************************** utils_at.c *********************************/

int		ft_get_at(t_pile *list, int pos);
int		ft_first_cell(t_pile *pile); // faire a et b ? 
int		ft_last_cell_a(t_pile *pile);
int		ft_last_cell_b(t_pile *pile);

/******************************* utils_free.c ********************************/

int		ft_is_empty_list(t_pile *list);
t_pile	*ft_free_list(t_pile *list);
t_pile	*ft_delete_last_cell(t_pile *pile);

/******************************* utils_set.c *********************************/

t_pile	*ft_create_cell(long data);
t_pile	*ft_add_pos(t_pile *list, long data, int pos);
int		ft_lst_size(t_pile *pile);
void	ft_init_struct(t_pile *pile);

/******************************* verif_arg.c *********************************/

int		ft_check_ac(int ac, char **av);
void	ft_check_no_arg(int ac, char **av);
void	ft_check_same_arg(t_pile *pile);
void	ft_check_int_max_and_min(t_pile *pile);

/******************************* verif_sort.c ********************************/

int		ft_pile_a_is_sort(t_pile *pile);
int		ft_pile_b_is_sort(t_pile *pile);
void	ft_check_if_sort(t_pile *pile);

#endif