/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:23:38 by abonnefo          #+#    #+#             */
/*   Updated: 2023/02/10 15:18:23 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
pa (push a) : Prend le premier élément au sommet de b et le met sur a.
Ne fait rien si b est vide.

pb (push b) : Prend le premier élément au sommet de a et le met sur b.
Ne fait rien si a est vide.
*/


// t_pile	*ft_free_at_pos(t_pile *list, int pos)
// {
// 	t_pile	*position = list;
// 	list = list->next;
// 	free(position);
// 	return (list);
// }

// t_pile	*ft_add_pos(t_pile *list, int data, int pos)
// {
// 	t_pile	*previous_pos = list;
// 	t_pile	*position = list;
// 	t_pile	*cell = ft_create_cell(data);
// 	int	i;

// 	i = 0;
// 	if (ft_is_empty_list(list))
// 		return (cell);
// 	if (pos == 0)
// 	{
// 		cell->next = list;
// 		return (cell); // pointeur de tete de liste
// 	}
// 	while (i < pos)
// 	{
// 		i++;
// 		previous_pos = position;
// 		position = position-> next;
// 	}
// 	previous_pos->next = cell;
// 	cell->next = position;
// 	return (list);
// }

int ft_first_cell(t_pile *pile)
{
	if (pile == NULL)
		return 0;

	return pile->data;
}

t_pile	*ft_push(t_pile *src, t_pile *dest)
{
	int	pos_zero_src;

	pos_zero_src = ft_first_cell(src);
	dest->pile_b = ft_add_pos(dest, pos_zero_src, 0);

	src->pile_a = ft_free_at_pos(src, 0);
	// src = src->next;

	// return (dest);
}


// typedef struct s_image {
// 	void	*img_sand;
// 	void	*img_cactus;
// 	void	*img_cowboy;
// 	void	*img_gold;
// 	void	*img_horse;
// }				t_image;

// typedef struct s_data {
// 	void			*mlx;
// 	void			*mlx_win;
// 	char			**tab;
// 	char			**duplicated_tab;
// 	struct s_image	*img;
// }				t_data;

// void	ft_free_images(t_data *data)
// {
// 	if (data->img->img_sand)
// 		mlx_destroy_image(data->mlx, data->img->img_sand);
// 	if (data->img->img_cactus)
// 		mlx_destroy_image(data->mlx, data->img->img_cactus);
// 	if (data->img->img_cowboy)
// 		mlx_destroy_image(data->mlx, data->img->img_cowboy);
// 	if (data->img->img_gold)
// 		mlx_destroy_image(data->mlx, data->img->img_gold);
// 	if (data->img->img_horse)
// 		mlx_destroy_image(data->mlx, data->img->img_horse);
// }