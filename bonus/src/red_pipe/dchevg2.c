/*
** dchevg2.c for 42sh in /home/ovejer_n/rendu/PSU_2013_42sh/src
** 
** Made by NicolasOVEJERO
** Login   <ovejer_n@epitech.net>
** 
** Started on  Sat Jun  7 16:36:06 2014 NicolasOVEJERO
** Last update Sat Jun  7 16:36:41 2014 NicolasOVEJERO
*/

#include "gene.h"

char	*my_read_chev(char *pass)
{
  int	c;

  while (42)
    {
      c = read(0, pass, 399);
      pass[c - 1] = 0;
      if (c > 0)
	return (pass);
    }
}

int	password(char *first, int i, t_gene *utils)
{
  int	j;

  while (first[i] && (first[i] < 'a' || first[i] > 'z') &&
	 (first[i] < 'A' || first[i] > 'Z'))
    ++i;
  j = 0;
  while (first[i] && ((first[i] >= 'a' && first[i] <= 'z') ||
		      (first[i] >= 'A' && first[i] <= 'Z')))
    utils->pass[j++] = first[i++];
  utils->pass[j] = 0;
  if (utils->pass[j - 1] == ' ')
    utils->pass[j - 1] = 0;
  return (i);
}
