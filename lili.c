	
	
	
	
	
	int    ft_find_in_b(t_pile *pile, int data)
{
	t_pile    *tmp;
	int        i;

	tmp = pile->pile_b;
	i = 0;
	while (tmp->data != data)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void    find_near_less(t_pile *pile)
{
	t_pile    *tmp;
	long    template;
	long    yes;

	template = pile->pile_a->data;
	yes = 0;
	while(yes == 0)
	{
		tmp = pile->pile_b;
		template = template - 1;
		while (tmp)
		{
			if (template == tmp->data)
			{
				yes = tmp->data;
				break ;
			}
			tmp = tmp->next;
		}
	}
	while (ft_find_in_b(pile, yes) != 0)
	{
		if (pile->mediane_b >= ft_find_in_b(pile, yes))
			ft_rotate_b(pile);
		else
			ft_reverse_rotate_b(pile);
	}
}

	if (ft_first_cell(pile->pile_a) >= highest_in_b)
	{
		while (ft_first_cell(pile->pile_b) != highest_in_b)
		{
			if (pile->mediane >= ft_find_in_b(pile, highest_in_b))
				ft_rotate_b(pile);
			else
				ft_reverse_rotate_b(pile);
		}
	}
	else if (ft_first_cell(pile->pile_a) < smallest_in_b)
	{
		while (ft_first_cell(pile->pile_b) != highest_in_b)
		{
			if (pile->mediane >= ft_find_in_b(pile, highest_in_b))
				ft_rotate_b(pile);
			else
				ft_reverse_rotate_b(pile);
		}
	}
	else if (ft_first_cell(pile->pile_a) > smallest_in_b 
		&& ft_first_cell(pile->pile_a) < highest_in_b)
		find_near_less(pile);

	while (ft_find_in_b(pile, yes) != 0)
	{
		if (pile->mediane >= ft_find_in_b(pile, yes))
			ft_rotate_b(pile);
		else
			ft_reverse_rotate_b(pile);
	}



	void    ft_reverse_rotate_a(t_pile *pile)
{
    int    last_value;

    last_value = ft_last_cell_a(pile);
    pile->pile_a = ft_add_at_pile(pile->pile_a, last_value, 0);
    pile->pile_a = ft_delete_last_cell(pile->pile_a);
    ft_printf("rra\n");
}

void    ft_reverse_rotate_b(t_pile *pile)
{
    int    last_value;

    last_value = ft_last_cell_b(pile);
    pile->pile_b = ft_add_at_pile(pile->pile_b, last_value, 0);
    pile->pile_b = ft_delete_last_cell(pile->pile_b);
    ft_printf("rrb\n");
}

void    ft_rrr(t_pile *pile)
{
    ft_reverse_rotate_a(pile);
    ft_reverse_rotate_b(pile);
}