
// voici une parti de mon code en liste simplement chainee que je souhaite tranformer en liste doublement chainee, comment faire ?


typedef struct s_pile {
	long			data;
	int				size_a;
	int				size_b;
	int				min_bucket;
	int				max_bucket;
	int				min_pile;
	int				max_pile;
	int				nb_in_bucket;
	int				mediane;
	struct s_pile	*pile_a;
	struct s_pile	*pile_b;
	struct s_pile	*next;
}					t_pile;


void	ft_put_in_pile(t_pile *pile, int ac, char **av)
{
	int			i;
	int			j;
	long		current_pos;

	i = 1;
	j = 0;
	while (i < ac)
	{
		current_pos = ft_atoi(av[i]);
		pile->pile_a = ft_add_pos(pile->pile_a, current_pos, j);
		i++;
		j++;
	}
}

t_pile	*ft_create_cell(long data)
{
	t_pile	*cell;

	cell = malloc(sizeof(t_pile));
	if (!cell)
		return (0);
	cell->data = data;
	cell->next = NULL;
	return (cell);
}

t_pile	*ft_add_pos(t_pile *list, long data, int pos)
{
	t_pile	*previous_pos;
	t_pile	*position;
	t_pile	*cell;
	int		i;

	previous_pos = list;
	position = list;
	cell = ft_create_cell(data);
	i = 0;
	if (ft_is_empty_list(list))
		return (cell);
	if (pos == 0)
	{
		cell->next = list;
		return (cell);
	}
	while (i < pos)
	{
		i++;
		previous_pos = position;
		position = position-> next;
	}
	previous_pos->next = cell;
	cell->next = position;
	return (list);
}