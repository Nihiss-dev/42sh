/*
** manage_alias.c for myshrc in /home/chardo_j/exercices/42shrc
** 
** Made by Julien Chardon
** Login   <chardo_j@epitech.net>
** 
** Started on  Fri May 16 06:34:09 2014 Julien Chardon
** Last update Tue Jun 10 06:57:43 2014 NicolasOVEJERO
*/

#include	"gene.h"

int		manage_alias(t_gene *util, char *str)
{
  t_alias	*alias;

  if ((alias = malloc(sizeof(t_alias))) == NULL)
    return (EXIT_FAILURE);
  if (init_name_val(&alias->name, &alias->cmd, str) == EXIT_FAILURE)
    {
      free(alias);
      return (EXIT_FAILURE);
    }
  add_elem_on_begin(&util->alias, alias);
  return (EXIT_SUCCESS);
}

void		free_alias(t_list *alias)
{
  t_list	*tmp;
  t_alias	*data;

  tmp = alias;
  while (tmp != NULL)
    {
      data = tmp->data;
      free_two_str(data->name, data->cmd);
      free(data);
      tmp = tmp->next;
    }
  del_list(&alias);
}
