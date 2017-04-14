/*
** add_elem.c for my_list in /home/chardo_j/exercices/list/src
** 
** Made by Julien Chardon
** Login   <chardo_j@epitech.net>
** 
** Started on  Wed May 14 02:50:21 2014 Julien Chardon
** Last update Tue Jun 10 11:19:18 2014 NicolasOVEJERO
*/

#include <stdlib.h>
#include "my_list.h"

int		add_elem_on_begin(t_list **list, void *data)
{
  t_list	*elem;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (1);
  elem->data = data;
  elem->next = *list;
  *list = elem;
  return (0);
}

int		add_elem_on_end(t_list **list, void *data)
{
  t_list	*elem;
  t_list	*tmp;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (1);
  elem->data = data;
  elem->next = NULL;
  if (*list == NULL)
    *list = elem;
  else
    {
      tmp = *list;
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = elem;
    }
  return (0);
}
