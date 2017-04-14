/*
** del_list.c for my_list in /home/chardo_j/exercices/list
** 
** Made by Julien Chardon
** Login   <chardo_j@epitech.net>
** 
** Started on  Wed May 14 02:25:44 2014 Julien Chardon
** Last update Wed May 14 02:47:39 2014 Julien Chardon
*/

#include <stdlib.h>
#include "my_list.h"

void		del_list(t_list **list)
{
  t_list	*tmp;

  while (*list != NULL)
    {
      tmp = *list;
      *list = (*list)->next;
      free(tmp);
    }
}
