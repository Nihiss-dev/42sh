/*
** del_elem.c for my_list in /home/chardo_j/exercices/list
** 
** Made by Julien Chardon
** Login   <chardo_j@epitech.net>
** 
** Started on  Wed May 14 01:56:41 2014 Julien Chardon
** Last update Wed May 14 03:27:31 2014 Julien Chardon
*/

#include <stdlib.h>
#include "my_list.h"

void		del_elem_on_begin(t_list **list)
{
  t_list	*tmp;

  if (*list == NULL)
    return ;
  tmp = *list;
  *list = (*list)->next;
  free(tmp);
}

void		del_elem_on_end(t_list **list)
{
  t_list	*tmp;
  t_list	*ptmp;

  if (*list == NULL)
    return ;
  if ((*list)->next == NULL)
    free(*list);
  else
    {
      tmp = *list;
      while (tmp->next != NULL)
	{
	  ptmp = tmp;
	  tmp = tmp->next;
	}
      ptmp->next = NULL;
      free(tmp);
    }
}
