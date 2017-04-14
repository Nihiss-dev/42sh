/*
** count_elems.c for my_list in /home/chardo_j/exercices/list
** 
** Made by Julien Chardon
** Login   <chardo_j@epitech.net>
** 
** Started on  Wed May 14 02:18:29 2014 Julien Chardon
** Last update Tue Jun 10 11:30:19 2014 NicolasOVEJERO
*/

#include <stdlib.h>
#include "my_list.h"

int		count_elems_on_list(t_list **list)
{
  t_list	*tmp;
  int		nb_elems;

  nb_elems = 0;
  tmp = *list;
  while (tmp != NULL)
    {
      tmp = tmp->next;
      ++nb_elems;
    }
  return (nb_elems);
}
