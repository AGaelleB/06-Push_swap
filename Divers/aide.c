/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aide.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:10:30 by abonnefo          #+#    #+#             */
/*   Updated: 2023/02/08 17:35:43 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
@file list.h
@brief contains the struct List and the prototypes of list.c
@author Arthur Detrembleur (DaveTilheim)
@version 1.0
*/
#ifndef __LIST__
#define __LIST__
 
/**
@struct List_t
*/
struct List_t{
 
    struct List_t *next; /*!< point to the next cell of the List */
    void *data; /*!< The data contain in the current cell of the list */
};
 
typedef struct List_t List;
 
/**
@fn unsigned length_list(List *L)
@brief show the length of the list
@param L a list
@post the length of L
@return a value between 0 and +inf
*/
unsigned length_list(List *L);
 
/**
@fn List *empty_list(void)
@brief create an empty list
@post empty list created
@return pointer null
*/
List *empty_list(void);
 
/**
@fn List *create_cell(void *data)
@brief create a cell
@param data a generic pointer contains generic data
@pre data != NULL
@post cell created and contains data
@return a sub-list
*/
List *create_cell(void *data);
 
/**
@fn List *add_first(List *L, void *data)
@brief add a cell at the begining of the list
@param L a list
@param data a generic pointer contains generic data
@pre data != NULL
@post length_list(L) + 1
@return a new list
*/
List *add_first(List *L, void *data);
 
/**
@fn List *add_last(List *L, void *data)
@brief add a cell at the end of the list
@param L a list
@param data a generic pointer contains generic data
@pre data != NULL
@post length_list(L) + 1
@return a new list
*/
List *add_last(List *L, void *data);
 
/**
@fn List *add_at(List *L, int i, void *data)
@brief add a cell at the index i of the list
@param L a list
@param i the index
@param data a generic pointer contains generic data
@pre data != NULL
@post length_list(L) + 1
@return a new list
*/
List *add_at(List *L, int i, void *data);
 
/**
@fn List *remove_list(List *L)
@brief remove all the cells of the list
@param L a list
@post empty_list()
@return a pointer NULL
*/
List *remove_list(List *L);
 
/**
@fn List *remove_first_element(List *L)
@brief remove a cell at the begining of the list
@param L a list
@post length_list(L) - 1
@return a new list
*/
List *remove_first_element(List *L);
 
/**
@fn void *get_element(List *L, int i)
@brief get the i element of the list
@param L a list
@param i the index
@post i element got
@return a generic pointer
*/
void *get_element(List *L, int i);
 
/**
@fn void set_element(List *L, int i, void *data)
@brief change the i element of the list with data
@param L a list
@param i the index
@param data the new data to put in the list
@post i element of the list changed
*/
void set_element(List *L, int i, void *data);
 
 
#endif
 
 
/////////////////////////
 
 
/**
@file list.c
@brief contains the C code about the data sruct 'List'
@author Arthur Detrembleur (DaveTilheim)
@version 1.0
*/
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
 
 
inline List *empty_list(void)
{
 
    return NULL;
}
 
/**
@fn static inline int is_empty(List *L)
@brief indicates if a list is empty
@param L a list
@post list empty or not
@return 0 -> not empty list  1 -> empty list
*/
static inline int is_empty(List *L)
{
    return L == NULL;
}
 
unsigned length_list(List *L)
{
    List *p = L;
    if(is_empty(p))
        return 0;
    int u = 0;
    while(p != NULL)
    {
        p = p->next;
        u++;
    }
 
    return u;
}
 
List *create_cell(void *data)
{
    assert(data != NULL);
 
    List *cell = malloc(sizeof(List));
    if(!cell)
        return empty_list();
 
    cell->data = data;
    cell->next = NULL;
 
    return cell;
}
 
List *add_first(List *L, void *data)
{
    assert(data != NULL);
 
    List *cell = create_cell(data);
    cell->next = L;
 
    return cell;
}
 
List *add_last(List *L, void *data)
{
    assert(data != NULL);
 
    List *p = L;
    List *cell = create_cell(data);
    while(p->next != NULL)
        p = p->next;
    p->next = cell;
 
    return L;
}
 
List *add_at(List *L, int i, void *data)
{
    assert(data != NULL);
 
    if(i >= length_list(L) || i < 0)
    {
        printf("index to big\n");
        return NULL;
    }
 
    List *p_cour = L;
    List *p_avant = p_cour->next;
    List *cell = create_cell(data);
    if(!i)
        return add_first(L, data);
    for(int j = 0; j < i; j++)
    {
        p_avant = p_cour;
        p_cour = p_cour->next;
    }
    p_avant->next = cell;
    cell->next = p_cour;
 
    return L;
}
 
 
 
List *remove_first_element(List *L)
{
    if(is_empty(L))
        return NULL;
    List *p = L;
    L = L->next;
    free(p);
 
    return L;
}
 
List *remove_list(List *L)
{
    if(is_empty(L))
    {
        return empty_list();
    }
    L = remove_first_element(L);
 
    return remove_list(L);
}
 
 
void *get_element(List *L, int i)
{
    if(i >= length_list(L) || i < 0)
    {
        printf("index wrong\n");
        return NULL;
    }
 
    List *p = L;
    for(int j = 0; j < i; j++)
        p = p->next;
 
    return p->data;
}
 
void set_element(List *L, int i, void *data)
{
    assert(data != NULL);
    
    if(i >= length_list(L) || i < 0)
    {
        printf("index wrong\n");
        return;
    }
    List *p = L;
    for(int j = 0; j < i; j++)
        p = p->next;
 
    p->data = data;
}
































/****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct s_lst
{
    void *content;
    int *data;
    struct s_lst *next;
} t_lst;

void *ft_empty_list(void)
{
    return NULL;
}

int ft_is_empty_list(t_lst *list)
{
    return (list == NULL);
}

t_lst *ft_add_pos(t_lst *list, int data, int pos)
{
    t_lst *position = list;
    t_lst *next_pos = position->next;
    t_lst *new_list = malloc(sizeof(t_lst));

    new_list->content = NULL;
    new_list->data = &data;
    new_list->next = next_pos;
    position->next = new_list;

    return new_list;
}

void ft_print_list(t_lst *list)
{
    printf("test\n");
    while (!ft_is_empty_list(list))
    {
        printf("%d\n", *(list->data));
        list = list->next;
    }
}

int main(int ac, char **av)
{
    t_lst *list = ft_empty_list();

    t_lst *head = NULL;
    t_lst *tail = NULL;

    int i = 1;
    while (i < ac)
    {
        t_lst *new_list = malloc(sizeof(t_lst));
        new_list->content = NULL;
        new_list->data = malloc(sizeof(int));
        *(new_list->data) = atoi(av[i]);
        new_list->next = NULL;

        if (head == NULL)
        {
            head = new_list;
            tail = new_list;
        }
        else
        {
            tail->next = new_list;
            tail = new_list;
        }
        i++;
    }
    tail->next = head;

    list = head;
    ft_print_list(list);

    return 0;
}
