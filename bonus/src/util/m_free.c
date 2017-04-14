/*
** m_free.c for 42sh in /home/ovejer_n/rendu/PSU_2013_42sh/tmp_work/gene
**
** Made by ovejer_n
** Login   <ovejer_n@epitech.net>
**
** Started on  Thu May 15 14:40:26 2014 ovejer_n
** Last update Sun May 25 22:33:59 2014 Julien Chardon
*/

#include "gene.h"

void	my_free_dtab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    free(tab[++i]);
  free(tab);
}
