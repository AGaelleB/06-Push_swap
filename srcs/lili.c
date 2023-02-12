

void ft_swap_pile_a(t_pile **head)
{
    t_pile *temp = NULL;

    temp = (*head)->next;
    (*head)->next = temp->next;
    temp->next = *head;
    *head = temp;
}

int main(int ac, char **av)
{
    t_pile *head = NULL;
    t_pile *pile_a = NULL;
    t_pile *pile_b = NULL;
    int i, j, current_pos;

    j = 0;
    i = 1;
    if (ft_check_ac(ac, av) == 0)
    {
        ft_printf("Error : alphanumeric parameters in argv\n");
        return (0);
    }
    while (i < ac)
    {
        current_pos = ft_atoi(av[i]);
        pile_a = ft_add_pos(pile_a, current_pos, j);
        i++;
        j++;
    }
    head = pile_a;

    /*JE FAIS MON PRINT INITIAL*/
    ft_printf("\n%s***INIT***%s\n", GREEN, RESET);
    print_piles(head, pile_b);
    ft_printf("%s*********%s\n\n", GREEN, RESET);

    /*JE SWAP*/
    ft_swap_pile_a(&head);
    ft_printf("%s***SWAP***%s\n", RED, RESET);
    print_piles(head, pile_b);
    ft_printf("%s**********%s\n\n", RED, RESET);

    return (0);
}
