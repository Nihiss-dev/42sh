/*
** manage_myshrc.c for myshrc in /home/chardo_j/exercices/42shrc/src
** 
** Made by Julien Chardon
** Login   <chardo_j@epitech.net>
** 
** Started on  Fri May 16 02:39:08 2014 Julien Chardon
** Last update Tue Jun 10 06:58:28 2014 NicolasOVEJERO
*/

#include <stdlib.h>
#include <fcntl.h>
#include "gene.h"

int	manage_myshrc(t_gene *util)
{
  int	fd;

  util->alias = NULL;
  if ((fd = open(MYSHRC_F_NAME, O_RDONLY)) == -1)
    return (EXIT_SUCCESS);
  if (pars_myshrc(util, fd) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

void		free_myshrc(t_gene *util)
{
  free_alias(util->alias);
}
